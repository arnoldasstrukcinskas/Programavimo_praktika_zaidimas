
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <tinyxml2.h>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;
using namespace tinyxml2;


class Enemy {

public:
    Enemy();
    Enemy(int id, int positionX, int positionY);
    Clock timer;
    void drawHealthBar(RenderWindow &window);

    int id1() const {
        return id;
    }

    int position_x() const {
        return positionX;
    }

    int position_y() const {
        return positionY;
    }

    int damage1() const {
        return damage;
    }

    int attack_range() const {
        return attackRange;
    }

    void set_health(int health) {
        this->health = health;
    }

    int health1() const {
        return health;
    }

    int reward_exp() const {
        return rewardExp;
    }

    void set_is_dead(bool is_dead) {
        isDead = is_dead;
    }

    bool is_dead() const {
        return isDead;
    }

    bool is_attacking() const {
        return isAttacking;
    }

    void set_is_attacking(bool is_attacking) {
        isAttacking = is_attacking;
    }

    int attack_speed() const {
        return attackSpeed;
    }

    void checkEnemyHp();

private:
    int id;
    int positionX;
    int positionY;
    int damage;
    int attackRange;
    int health;
    int rewardExp;
    bool isDead = false;
    bool isAttacking = false;
    int attackSpeed;

    vector<vector<int>> enemyTiles;
    Texture texture;
    vector<Sprite> enemySprites;

    //functions
    void enemyAttack();
    void enemyDie();


};



#endif //ENEMY_H
