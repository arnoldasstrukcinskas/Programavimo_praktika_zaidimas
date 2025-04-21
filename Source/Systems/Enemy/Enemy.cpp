//
// Created by arnol on 4/17/2025.
//

#include "Enemy.h"

Enemy::Enemy() {
}

Enemy::Enemy(int id, int positionX, int positionY) {
    switch(id) {
        case 1:
            this->id = 1;
            this->health = 100;
            this->damage = 10;
            this->rewardExp = 100;
            this->attackRange = 0;
            this->positionX = positionX;
            this->positionY = positionY;
            this->attackSpeed = 1000;
            this->isDead = false;
            break;
        case 2:
            this->id = 2;
            this->health = 150;
            this->damage = 15;
            this->rewardExp = 100;
            this->attackRange = 3;
            this->attackSpeed = 1200;
            this->positionX = positionX;
            this->positionY = positionY;
            this->isDead = false;
            break;
        case 3:
            this->id = 3;
            this->health = 200;
            this->damage = 20;
            this->rewardExp = 40;
            this->attackRange = 2;
            this->attackSpeed = 1500;
            this->positionX = positionX;
            this->positionY = positionY;
            this->isDead = false;
            break;
        case 4:
            this->id = 4;
            this->health = 300;
            this->damage = 30;
            this->rewardExp = 50;
            this->attackRange = 0;
            this->attackSpeed = 2000;
            this->positionX = positionX;
            this->positionY = positionY;
            this->isDead = false;
            break;
        default:
            cout << "Something wrong" << endl;
    }
}

void Enemy::enemyAttack() {

}

void Enemy::enemyDie() {
}

void Enemy::checkEnemyHp() {
    if (health <= 0) {
        isDead = true;
    }
}


