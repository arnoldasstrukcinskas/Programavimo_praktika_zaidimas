

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tinyxml2.h>

using namespace std;
using namespace sf;
using namespace tinyxml2;

class Map {

public:
    Map();
    bool loadFromXML(const string& filePath);
    void example(RenderWindow& window);
    void drawMap(RenderWindow& window);
    void generateLevel();

    //Getters
    const vector<vector<int>>& getTiles();
    const int& getmapWidth();
    const int& getMapHeight();
    int start_position_x();
    int start_position_y();

private:
    vector<vector<int>> mapTiles;
    map<int, Texture> texturesMap;
    vector<Sprite> spritesVector;
    Texture tileTexture;
    int mapWidth;
    int mapHeight;
    int startPositionX;
    int startPositionY;

private:
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

    void loadMapTiles();
    void loadEnemyTiles();
};


#endif //MAP_H


