
#include "Game.h"


//Constructor
Game::Game()
    : desktopWindow(VideoMode::getDesktopMode(), "Zaidimas"){}


void Game::run() {

    if (!gameMap.loadFromXML("../Data/Maps/Level1.xml")) {
        cerr << "Error loading the map!" << endl;
    }
    if (!enemies.loadFromXML("../Data/Maps/Level1.xml", gameMap)) {
        cerr << "Error loading the map!" << endl;
    }
    gameMap.generateLevel();
    actions = new Actions(gameMap);
    enemies.generateEnemy(gameMap);
    player.generatePlayer(gameMap);

    while (desktopWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    while (const std::optional event = desktopWindow.pollEvent())
    {
        if (event->is<Event::Closed>())
        {
            desktopWindow.close();
        }
        else if (const auto* keyPressed = event->getIf<Event::KeyPressed>()) {
            switch (keyPressed->scancode) {
                case Keyboard::Scancode::D:
                    player.set_is_moving_forward(true);
                    break;
                case Keyboard::Scancode::A:
                    player.set_is_moving_backward(true);
                    break;
                case Keyboard::Scancode::W:
                        actions->isJumping(player, player.is_jumping()); // Start jumping if not already jumping
                    break;
                case Keyboard::Scancode::F:
                    actions->playerAttack(player, gameMap);
                    break;
                case Keyboard::Scancode::Escape:
                    desktopWindow.close();
                    break;
            }
        } else if (const auto* keyReleased = event->getIf<Event::KeyReleased>()) {
            switch (keyReleased->scancode) {
                case Keyboard::Scancode::D:
                    player.set_is_moving_forward(false);
                    break;
                case Keyboard::Scancode::A:
                    player.set_is_moving_backward(false);
                    break;
                case Keyboard::Scancode::F:
                    player.set_is_attacking(false);
                    player.set_is_actions(false);
            }
        }
    }
}

void Game::update() {
    actions->playerJump(player, gameMap);
    actions->playerMoveForward(player, gameMap);
    actions-> playerMoveBackward(player, gameMap);
    player.generatePlayer(map);
    actions->applyGravity(player, gameMap);
}

void Game::render() {
    desktopWindow.clear(Color::White);
    gameMap.drawMap(desktopWindow);
    enemies.drawEnemy(desktopWindow);
    player.drawPlayer(desktopWindow);
    desktopWindow.display();
}
