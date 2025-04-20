//
// Created by arnol on 4/15/2025.
//

#include "Map.h"

using namespace std;

Map::Map(){
}

const vector<vector<int> > &Map::getTiles() {
    return this->mapTiles;
}

const int & Map::getmapWidth() {
    return this->mapWidth;
}

const int & Map::getMapHeight() {
    return this->mapHeight;
}

int Map::start_position_x() {
    return startPositionX;
}

int Map::start_position_y(){
    return startPositionY;
}


bool Map::loadFromXML(const string &filePath) {

    XMLDocument mapDocument;
    if (mapDocument.LoadFile(filePath.c_str()) != XML_SUCCESS) {
        cerr << "Error loading XML file!" << endl;
        return false;
    }

    // Get root element <map>
    XMLElement* root = mapDocument.FirstChildElement("map");
    if (!root) {
        cerr << "No <map> element found in the XML file!" << endl;
        return false;
    }

    XMLElement* startPosition = root->FirstChildElement("start");
    startPositionX = startPosition->IntAttribute("width") - 1;
    startPositionY = startPosition->IntAttribute("height") - 1;

    mapWidth = root->IntAttribute("width");
    mapHeight = root->IntAttribute("height");
    mapTiles.resize(mapHeight, vector<int>(mapWidth, mapHeight));

    XMLElement* background = root->FirstChildElement("background");
    XMLElement* row = background->FirstChildElement("row");
    int elementFloor = 0;

    while (row) {
        // Read the row data (space-separated values)
        const char* rowText = row->GetText();

        if (rowText) {
            stringstream rowStream(rowText);

            int tileID;
            int elementPosition = 0;

            // Parse each tile ID in the row
            while (rowStream >> tileID) {
                mapTiles[elementFloor][elementPosition] = tileID;
                elementPosition++;
            }
        }

        // Move to the next row
        row = row->NextSiblingElement("row");
        elementFloor++;
    }

    // for (const auto& row : tiles) {
    //     for (const auto& element : row) {
    //         cout << element << " ";
    //     }
    //     cout << endl; // Move to the next row
    // }
    return true;
}

void Map::loadMapTiles() {
    for (int i = 1; i <= 8; ++i) {
        Texture texture;
        if (!texture.loadFromFile(tilePaths[i - 1], false, IntRect({0, 0}, {16, 16}))) {
            cerr << "Failed to load tile " << i << endl;
        }
        texturesMap[i] = move(texture); // Store preloaded texture
    }
}

void Map::generateLevel() {
    loadMapTiles();

    for (int row = 0; row < mapHeight; row++) {
        for (int column = 0; column < mapWidth; column++) {
            int tileId = mapTiles[row][column];

            if (texturesMap.find(tileId) != texturesMap.end()) { // Check if texture exists
                Sprite sprite(texturesMap[tileId]);
                sprite.setScale({4, 4});
                sprite.setPosition(sf::Vector2f(column * 16 * 4, row * 16 * 4)); // Adjusted for scaling
                spritesVector.push_back(sprite);
            } else {
                std::cout << "No such tile ID: " << tileId << std::endl;
            }
        }
    }
}

void Map::drawMap(RenderWindow& window) {
    for (Sprite sprite : spritesVector) {
        window.draw(sprite);
    }
}



