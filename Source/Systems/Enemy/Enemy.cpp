//
// Created by arnol on 4/17/2025.
//

#include "Enemy.h"

bool Enemy::loadFromXML(const string &filePath, Map map) {
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

    int mapWidth = root->IntAttribute("width");
    int mapHeight = root->IntAttribute("height");
    enemyTiles.resize(mapHeight, vector<int>(mapWidth, mapHeight));

    XMLElement* enemies = root->FirstChildElement("enemies");
    XMLElement* row = enemies->FirstChildElement("row");
    int elementFloor = 0;

    while (row) {
        // Read the row data (space-separated values)
        const char* rowText = row->GetText();

        if (rowText) {
            stringstream rowStream(rowText);

            int enemyId;
            int elementPosition = 0;

            // Parse each tile ID in the row
            while (rowStream >> enemyId) {
                enemyTiles[elementFloor][elementPosition] = enemyId;
                elementPosition++;
            }
        }

        // Move to the next row
        row = row->NextSiblingElement("row");
        elementFloor++;
    }
    return true;
}

// bool Enemy::loadFromXML(const string &filePath, Map map) {
//
//     XMLDocument mapDocument;
//     if (mapDocument.LoadFile(filePath.c_str()) != XML_SUCCESS) {
//         cerr << "Error loading XML file!" << endl;
//         return false;
//     }
//
//     XMLElement* root = mapDocument.FirstChildElement("map");
//     if (!root) {
//         cerr << "No <map> element found in the XML file!" << endl;
//         return false;
//     }
//
//     XMLElement *enemies = root->FirstChildElement("enemies");
//     XMLElement *info = enemies->FirstChildElement("info");
//     int enemyId;
//     int positionX;
//     int positionY;
//
//     while (info) {
//         enemyId = info->IntAttribute("id");
//         positionX = info->IntAttribute("positionX");
//         positionY = info->IntAttribute("positionY");
//
//         enemyTiles[positionY][positionX] = enemyId;
//
//         info = info->NextSiblingElement("info");
//     }
//
//     return false;
// }

void Enemy::loadEnemyTiles() {
    for (int i = 1; i <= 4; ++i) {
        Texture texture;
        if (!texture.loadFromFile(enemyPaths[i - 1], false, IntRect({0, 0}, {48, 48}))) {
            cerr << "Failed to load enemy " << i << endl;
        }
        enemiesMap[i + 10] = move(texture);
    }
}

void Enemy::generateEnemy(Map map) {

    loadEnemyTiles();

    for (int row = 0; row < map.getMapHeight(); row++) {
        for (int column = 0; column < map.getmapWidth(); column++) {
            int enemyId = enemyTiles[row][column];

            if (enemyId > 10 && enemyId < 15) {
                if (enemiesMap.find(enemyId) != enemiesMap.end()) { // Check if texture exists
                    Sprite sprite(enemiesMap[enemyId]);
                    sprite.setScale({1.333, 1.333});
                    sprite.setPosition(sf::Vector2f(column * 64, row * 64)); // Adjusted for scaling
                    enemySprites.push_back(sprite);
                } else {
                    std::cout << "No such Enemy ID: " << enemyId << std::endl;
                }
            }
        }
    }
}

void Enemy::drawEnemy(RenderWindow& window) {
    for (Sprite sprite : enemySprites) {
        window.draw(sprite);
    }
}

void Enemy::enemyAttack() {

}

void Enemy::enemyDie() {
}


