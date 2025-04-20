#include "Actions.h"


void Actions::playerMoveForward(Player &player, Map &map) {

    if (player.is_moving_forward()) {
        int x = player.position_x();
        int y = player.position_y();

        if (moveTimer.getElapsedTime().asMilliseconds() >= 32) {
            if (canMoveFoward(x + 4, y)) {
                player.set_position_x(player.position_x() + 4);
                moveTimer.restart();
            } else {
                cout << "No go" << endl;
            }
        }
    }

}

void Actions::playerMoveBackward(Player &player, Map &map) {

    if (player.is_moving_backward()) {
        int x = player.position_x();
        int y = player.position_y();

        if (moveTimer.getElapsedTime().asMilliseconds() >= 32) {
            if (canMoveBackwards(x, y)) {
                player.set_position_x(player.position_x() - 4);
                moveTimer.restart();
            } else {
                cout << "No go" << endl;
            }
        }
    }
}

void Actions::playerJump(Player &player, Map &map) {
    if (!player.is_jumping()) {
        return;
    }
        if (jumpTimer.getElapsedTime().asMilliseconds() >= 32) {
            if (player.jump_frame() < player.max_jump_frame()) {
                player.set_position_y(player.position_y() - 4);
                player.set_jump_frame(player.jump_frame() + 4);
            } else {
                if (!canLand(player, map)) {
                    player.set_position_y(player.position_y() + 4);
                } else {
                    player.set_is_jumping1(false);
                    player.set_jump_frame(0);
                    return;
                }
            }
            jumpTimer.restart();
    }
}


void Actions::applyGravity(Player &player, Map &map) {
    int positionX = (player.position_x() - 32) / 64 + 1; // distracting 32 for pixels axxuraxy and adding 1 for 1 ahead
    int positionY = player.position_y() / 64 + 1; // adding 1 for one tile ahead

    int tileId = tiles[positionY][positionX];

    if (player.is_jumping()) {
        return;
    }
    if (jumpTimer.getElapsedTime().asMilliseconds() >= 32) {
        if (tileId >= 1 && tileId <= 3) {
            cout << "nuleidziu" << endl;
            player.set_position_y(player.position_y() + 4);
        }
        jumpTimer.restart();
    }
}

bool Actions::canLand(Player &player, Map &map) {
    int positionX = (player.position_x() + 32) / 64;
    int positionY = (player.position_y() + 64) / 64;

    int tileId = tiles[positionY][positionX];

    return (tileId < 1 || tileId > 3);
}

void Actions::isWalkingForward(Player &player, bool isWalkingForward) {
        player.set_is_moving_forward(isWalkingForward);
}

void Actions::isWalkingBackward(Player &player, bool isWalkingBackward) {
        player.set_is_moving_backward(isWalkingBackward);
}

void Actions::isJumping(Player &player, bool isJumping) {
    if (!isJumping) {
        player.set_is_jumping1(true);
        player.set_jump_frame(0);
    }
}

bool Actions::canMoveFoward(int positionX, int positionY) {
    const int tileSize = 64;
    positionX = (positionX - 32) / tileSize + 1;     //distracting 32 for pixel correction adding 1 for getting one tile ahead
    positionY = (positionY + 60) / tileSize;        // adding 60 for pixel correction

    if (positionX < 0 || positionX >= mapWidth - 1 || positionY < 0 || positionY >= mapHeight) {
        return false;
    }

    int tile = tiles[positionY][positionX];
    if (tile < 1 || tile > 3) {
        return false;
    }

    return true;
}

bool Actions::canMoveBackwards(int positionX, int positionY) {
    const int tileSize = 64;
    positionX = (positionX + 16) / tileSize;            //adding 16 for pixel correction
    positionY = (positionY + 60) / tileSize;            // adding 60 for pixel correction

    if (positionX < 0 || positionX >= mapWidth || positionY < 0 || positionY >= mapHeight)
        return false;

    int tile = tiles[positionY][positionX];
    if (tile < 1 || tile > 3)
        return false;

    return true;
}

void Actions::playerAttack(Player &player, Map &map) {
    player.set_is_attacking(true);
    player.set_is_actions(true);
    cout << "attack triggered" << endl;
    cout << player.is_attacking() << endl;
    cout << player.is_actions() << endl;

    player.generatePlayer(map);

}

void Actions::playerHit() {
}

void Actions::playerDie() {
}

void Actions::monsterAttack() {
}

void Actions::monsterDies() {
}
