

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tinyxml2.h>
#include "../Enemy/Enemy.h"

using namespace std;
using namespace sf;
using namespace tinyxml2;

class Map {

public:
    Map();
    bool loadMapFromXML(const string& filePath);
    bool loadEnemyFromXML(const string& filePath);
    void drawMap(RenderWindow& window);
    void updateEnemies(RenderWindow& window);
    void generateLevel();
    void generateEnemy();
    vector<Enemy> enemies;
    map<int, Texture> enemiesTextures;

    //Getters
    const vector<vector<int>>& getTiles();
    const int& getmapWidth();
    const int& getMapHeight();
    int start_position_x();
    int start_position_y();

private:
    vector<Sprite> enemiesSprites;
    vector<vector<int>> mapTiles;
    map<int, Texture> texturesMap;
    vector<Sprite> spritesVector;
    Texture tileTexture;
    int mapWidth;
    int mapHeight;
    int startPositionX;
    int startPositionY;

    const vector<string> tilePaths = {
        // bacground map tiles
        "../Assets/Textures/Map/Tiles/1.png",
        "../Assets/Textures/Map/Tiles/2.png",
        "../Assets/Textures/Map/Tiles/3.png",
        "../Assets/Textures/Map/Tiles/Border.png",
        // map elements tils
        "../Assets/Textures/Map/Obstacles/ground.png",
        "../Assets/Textures/Map/Obstacles/grass.png",
        "../Assets/Textures/Map/Obstacles/box.png",
        "../Assets/Textures/Map/Obstacles/steelBox.png"
    };

    const vector<string> enemyPaths = {
        "../Assets/Textures/Enemies/barrel.png",
        "../Assets/Textures/Enemies/cannon.png",
        "../Assets/Textures/Enemies/croc.png",
        "../Assets/Textures/Enemies/pc.png"
    };

    void loadMapTiles();
    void loadEnemyTiles();
    void loadEnemies();
};


#endif //MAP_H


