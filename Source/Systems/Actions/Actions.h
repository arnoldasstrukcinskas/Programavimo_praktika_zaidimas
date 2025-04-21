//
// Created by arnol on 4/16/2025.
//

#ifndef FIGHT_H
#define FIGHT_H
#include "../MapSystem/Map.h"
#include "../Player/Player.h"
#include "../../Misc/FontManager.h"
#include <chrono>
#include <thread>



class Actions {

public:
    Actions(Map &map) {
        mapHeight = map.getMapHeight();
        mapWidth = map.getmapWidth();
        tiles = map.getTiles();
    }
    void playerMoveForward(Player &player, Map &map);
    void playerMoveBackward(Player &player, Map &map);
    void isJumping(Player &player, bool isJumping);
    void isWalkingForward(Player &player, bool isWalkingForward);
    void isWalkingBackward(Player &player, bool isWalkingBackward);
    void playerJump(Player &player, Map &map);
    void applyGravity(Player &player, Map &map);
    void playerAttack(Player &player, Map &map);
    void monsterHit(Player &player, Map &map);


    void playerHit(Map &map, Player &player, int plyasPositionX, int playerPositionY);
    void playerDie();
    void monsterAttack(Player &player, Map &map);
    void monsterDies();
    FontManager damageText;
private:
    Clock moveTimer;
    Clock jumpTimer;
    Clock attackTimer;
    int mapHeight;
    int mapWidth;
    vector<vector<int>> tiles;

    //private functions
    bool canMoveFoward(int positionX, int positionY);
    bool canMoveBackwards(int position, int positionY);
    bool canLand(Player &player, Map &map);
    bool isInRage(int playerX, int playerY, int monsterX, int monsterY, int range);
};



#endif //FIGHT_H
