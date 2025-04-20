//
// Created by arnol on 4/16/2025.
//

#include "Player.h"

#include <iostream>
using namespace std;

Player::Player() {
    //empty constructor
}

void Player::generatePlayer(Map map) {

    if (position_x() == 0 && position_y() == 0) {
        setDefaultPosition(map);
    }

    playerTextures.clear();

    if (!isActions) {
        if (texture.loadFromFile(playerPaths[0], false, IntRect({0, 0},{128,128}))) {
            playerTextures.push_back(move(texture));
            cout << "pushed" << endl;
        }
    } else if (isAttacking) {
        for (int i = 0; i < 4; ++i) {
            if (texture.loadFromFile(meleeAttackAnimation, false, IntRect({(i * 128), 0}, {128, 128}))) {
                playerTextures.push_back(move(texture));
            }
        }
    }
}

void Player::drawPlayer(RenderWindow &window) {

    for (Texture &texture: playerTextures) {
        Sprite playerSprite(texture);
        playerSprite.setScale({0.5, 0.5});
        playerSprite.setPosition({position_x(), position_y()});
        window.draw(playerSprite);
    }
}


void Player::setDefaultPosition(Map &map) {
    float x = map.start_position_x() * 64;
    float y = map.start_position_y() * 64;
    set_position_x(x);
    set_position_y(y);
}

