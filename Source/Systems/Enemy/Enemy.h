
#ifndef ENEMY_H
#define ENEMY_H
#include "SFML/Graphics/Texture.hpp"
#include "../MapSystem/Map.h"
#include "../Player/Player.h"
#include <tinyxml2.h>
#include <iostream>

using namespace sf;
using namespace std;
using namespace tinyxml2;


class Enemy {
public:
    bool loadFromXML(const string &filePath, Map map);
    void generateEnemy(Map map);
    void drawEnemy(RenderWindow& window);
    void loadEnemyTiles();

    //functions
    int health1() const {
        return health;
    }

    void set_health(int health) {
        this->health = health;
    }


private:
    int health;
    int rewardExp;
    vector<vector<int>> enemyTiles;
    Texture texture;
    vector<Sprite> enemySprites;
    const vector<string> enemyPaths = {
        "../Assets/Textures/Enemies/barrel.png",
        "../Assets/Textures/Enemies/cannon.png",
        "../Assets/Textures/Enemies/croc.png",
        "../Assets/Textures/Enemies/pc.png"
    };
    map<int, Texture> enemiesMap;

    //functions
    void enemyAttack();
    void enemyDie();

};



#endif //ENEMY_H
