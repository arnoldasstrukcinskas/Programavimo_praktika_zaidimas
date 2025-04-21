//
// Created by arnol on 4/16/2025.
//

#include "Player.h"

#include <iostream>
using namespace std;

Player::Player() {
    //empty constructor
}

void Player::generatePlayer(Map &map) {

    if (position_x() == 0 && position_y() == 0) {
        setDefaultPosition(map);
    }

    playerTextures.clear();
    if (level < 8) {
        if (!isActions) {
            if (texture.loadFromFile(playerPaths[0], false, IntRect({0, 0},{128,128}))) {
                playerTextures.push_back(move(texture));
                // cout << "pushed" << endl;
            }
        } else if (isAttacking) {
            for (int i = 0; i < 4; ++i) {
                if (texture.loadFromFile(meleeAttackAnimation, false, IntRect({(i * 128), 0}, {128, 128}))) {
                    playerTextures.push_back(move(texture));
                }
            }
        }
    } else if (level < 15) {
        if (!isActions) {
            if (texture.loadFromFile(playerPaths[1], false, IntRect({0, 0},{128,128}))) {
                playerTextures.push_back(move(texture));
                // cout << "pushed" << endl;
            }
        } else if (isAttacking) {
            for (int i = 0; i < 4; ++i) {
                if (texture.loadFromFile(commanderAttack, false, IntRect({(i * 128), 0}, {128, 128}))) {
                    playerTextures.push_back(move(texture));
                }
            }
        }
    } else {
        if (!isActions) {
            if (texture.loadFromFile(playerPaths[2], false, IntRect({0, 0},{128,128}))) {
                playerTextures.push_back(move(texture));
                // cout << "pushed" << endl;
            }
        } else if (isAttacking && !is_bow_attack()) {
            for (int i = 0; i < 4; ++i) {
                if (texture.loadFromFile(archerMelee, false, IntRect({(i * 128), 0}, {128, 128}))) {
                    playerTextures.push_back(move(texture));
                }
            }
        } else {
            for (int i = 0; i < 4; ++i) {
                if (texture.loadFromFile(archerShot, false, IntRect({(i * 128), 0}, {128, 128}))) {
                    playerTextures.push_back(move(texture));
                }
            }
        }
    }
}

bool Player::isAlive() {
    if (hp > 0) {
        return true;
    }
    return false;
}

void Player::drawPlayer(RenderWindow &window) {

    if (isAlive()) {
        for (Texture &texture: playerTextures) {
            Sprite playerSprite(texture);
            playerSprite.setScale({0.5, 0.5});
            playerSprite.setPosition({position_x(), position_y()});
            window.draw(playerSprite);
        }
    }
}


void Player::setDefaultPosition(Map &map) {
    float x = map.start_position_x() * 64;
    float y = map.start_position_y() * 64;
    set_position_x(x);
    set_position_y(y);
}

void Player::checkLevel(Player &player) {
    if (player.exp1() > 99) {
        player.set_level(player.level1() + 1);
        player.set_max_hp(player.max_hp() + 20);
        player.set_hp(player.max_hp());
        player.set_exp(0);
        player.set_attack(player.attack1() + 5);
        cout << "level Up" << endl;
    }
    if (level >= 15) {
        attackRange = 2;
    }
}

void Player::drawHealthBar(RenderWindow &window) {

    if (!isAlive()) {
        return;
    }

    float barWidth = 48;
    float barHeight = 8;
    float x = position_x();
    float y = position_y() - 16;

    //background bar
    RectangleShape backgroundBar(Vector2f(barWidth, barHeight));
    backgroundBar.setFillColor(Color::Black);
    backgroundBar.setPosition(Vector2f(x, y));

    // Hp bar
    float hpRatio = static_cast<float>(hp) / static_cast<float>(maxHp);

    RectangleShape healthBar(sf::Vector2f(barWidth * hpRatio, barHeight));
    healthBar.setFillColor(sf::Color::Green);
    healthBar.setPosition(Vector2f(x, y));

    if (hpRatio < 0.5) {
        healthBar.setFillColor(sf::Color::Yellow);
    }

    if (hpRatio < 0.25) {
        healthBar.setFillColor(sf::Color::Red);
    }

    window.draw(backgroundBar);
    window.draw(healthBar);
}

void Player::drawExpBar(RenderWindow &window) {

    if (!isAlive()) {
        return;
    }

    float barWidth = 48;
    float barHeight = 8;
    float x = position_x();
    float y = position_y() - 8;

    //background bar
    RectangleShape backgroundBar(Vector2f(barWidth, barHeight));
    backgroundBar.setFillColor(Color::Black);
    backgroundBar.setPosition(Vector2f(x, y));

    // Hp bar
    float hpRatio = static_cast<float>(exp) / 100.f;

    RectangleShape healthBar(sf::Vector2f(barWidth * hpRatio, barHeight));
    healthBar.setFillColor(sf::Color::White);
    healthBar.setPosition(Vector2f(x, y));


    window.draw(backgroundBar);
    window.draw(healthBar);
}

