//
// Created by arnol on 4/16/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../MapSystem/Map.h"

using namespace sf;
using namespace std;



class Player {
public:
    Player();
    void drawPlayer(RenderWindow& window);
    void generatePlayer(Map &map);
    bool isAlive();
    void checkLevel(Player &player);
    void drawHealthBar(RenderWindow &window);
    void drawExpBar(RenderWindow &window);
    int animationFrame = 0;

    int hp1() const {
        return hp;
    }

    void set_hp(int hp) {
        this->hp = hp;
    }

    int max_hp() {
        return maxHp;
    }

    void set_max_hp(int max_hp) {
        maxHp = max_hp;
    }

    int attack1() const {
        return attack;
    }

    void set_attack(int attack) {
        this->attack = attack;
    }

    int attack_range() {
        return attackRange;
    }

    void set_attack_range(int attack_range) {
        attackRange = attack_range;
    }

    int exp1() const {
        return exp;
    }

    void set_exp(int exp) {
        this->exp = exp;
    }

    int level1() const {
        return level;
    }

    void set_level(int level) {
        this->level = level;
    }
    float position_x() const {
        return positionX;
    }

    void set_position_x(float position_x) {
        positionX = position_x;
    }

    float position_y() const {
        return positionY;
    }

    void set_position_y(float position_y) {
        positionY = position_y;
    }

    bool is_actions() const {
        return isActions;
    }

    void set_is_actions(bool is_actions) {
        isActions = is_actions;
    }

    bool is_attacking() const {
        return isAttacking;
    }

    void set_is_attacking(bool is_attacking) {
        isAttacking = is_attacking;
    }

    void set_is_jumping1(bool is_jumping) {
        isJumping = is_jumping;
    }

    bool is_jumping() const {
        return isJumping;
    }

    void set_jump_frame(int jump_frame) {
        jumpFrame = jump_frame;
    }

    int jump_frame() const {
        return jumpFrame;
    }

    int max_jump_frame() const {
        return maxJumpFrame;
    }

    bool is_moving_forward() const {
        return isMovingForward;
    }

    void set_is_moving_forward(bool is_moving_forward) {
        isMovingForward = is_moving_forward;
    }

    bool is_moving_backward() const {
        return isMovingBackward;
    }

    void set_is_moving_backward(bool is_moving_backward) {
        isMovingBackward = is_moving_backward;
    }

    bool is_bow_attack() {
        return isBowAttack;
    }

    void set_is_bow_attack(bool is_bow_attack) {
        isBowAttack = is_bow_attack;
    }

private:
    //Stats
    int hp = 200;
    int maxHp = 200;
    int attack = 5;
    int attackRange = 0;
    int exp = 0;
    int level = 18;
    const int maxLevel = 50;
    //Starting position
    float positionX = 0;
    float positionY = 0;
    // Movement
    bool isActions = false;
    bool isAttacking = false;
    bool isMovingForward = false;
    bool isMovingBackward = false;
    bool isJumping = false;
    bool isBowAttack = false;
    int jumpFrame = 0;
    int maxJumpFrame = 96;

    //Timer
    Clock meleeAttackTimer;

    // Character textures
    Texture texture;
    const vector<string> playerPaths = {
        "../Assets/Textures/Character/warrior.png",
        "../Assets/Textures/Character/commander.png",
        "../Assets/Textures/Character/archer.png"
    };
    const string meleeAttackAnimation = "../Assets/Textures/Character/attacks/meleeAttack.png";
    const string archerShot = "../Assets/Textures/Character/attacks/archerShot.png";
    const string archerMelee = "../Assets/Textures/Character/attacks/archerMelee.png";
    const string commanderAttack = "../Assets/Textures/Character/attacks/commanderAttack.png";
    vector<Texture> playerTextures;
    const vector<string> rangeAttackAnimation = {
    "path",
    "path"};
    const vector<string> playerDieAnimation = {
    "path",
    "path"};
    const vector<string> levelUpAnimation = {
    "path",
    "path"};
    vector <Sprite> healthBar;
    vector <Sprite> expBar;
    // private functions
    void setDefaultPosition(Map &map);



};



#endif //PLAYER_H
