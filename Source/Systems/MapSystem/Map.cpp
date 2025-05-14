
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


bool Map::loadMapFromXML(const string &filePath) {

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
    return true;
}

bool Map::loadEnemyFromXML(const string &filePath) {

    XMLDocument mapDocument;
    if (mapDocument.LoadFile(filePath.c_str()) != XML_SUCCESS) {
        cerr << "Error loading XML file!" << endl;
        return false;
    }

    XMLElement* root = mapDocument.FirstChildElement("map");
    if (!root) {
        cerr << "No <map> element found in the XML file!" << endl;
        return false;
    }

    XMLElement *enemiesRoot = root->FirstChildElement("enemies");
    XMLElement *info = enemiesRoot->FirstChildElement("info");


    while (info) {
        int enemyId = info->IntAttribute("id");
        int positionX = info->IntAttribute("positionX");
        int positionY = info->IntAttribute("positionY");
        Enemy enemy(enemyId, positionX, positionY);

        enemies.push_back(enemy);

        info = info->NextSiblingElement("info");
    }
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
                cout << "No such tile ID: " << tileId << endl;
            }
        }
    }
}

void Map::loadEnemies() {
        for (int i = 0; i < 3; ++i) {
            Texture texture;
            if (!texture.loadFromFile(enemyPaths[i], false, IntRect({0, 0}, {48, 48}))) {
                cerr << "Failed to load enemy " << i << endl;
            }
            enemiesTextures[i] = move(texture);
        }
}

void Map::generateEnemy() {

    loadEnemies();
    enemiesSprites.clear();

    for (int i = 0; i < enemies.size(); i++) {
        int enemyId = enemies[i].id1();
        int textureIndex = enemyId - 1;
        int positionX = enemies[i].position_x();
        int positionY = enemies[i].position_y();

        Sprite enemySprite(enemiesTextures[textureIndex]);
        enemySprite.setScale({1.333, 1.333});
        enemySprite.setPosition(Vector2f(positionX * 64, positionY * 64));
        enemiesSprites.push_back(enemySprite);
    }
}

void Map::drawMap(RenderWindow& window) {
    for (Sprite sprite : spritesVector) {
        window.draw(sprite);
    }
    for (Sprite sprite : enemiesSprites) {
        window.draw(sprite);
    }
}

void Map::updateEnemies(RenderWindow &window) {

    for (Sprite sprite : enemiesSprites) {
        window.draw(sprite);
    }
}


