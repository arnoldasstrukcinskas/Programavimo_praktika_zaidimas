
#include "Game.h"


//Constructor
Game::Game()
    : desktopWindow(VideoMode::getDesktopMode(), "Zaidimas"){
}


void Game::run() {
    gui.generateMenu();

    if (!gameMap.loadMapFromXML("../Data/Maps/Level1.xml")) {
        cerr << "Error loading the map!" << endl;
    }
    if (!gameMap.loadEnemyFromXML("../Data/Maps/Level1.xml")) {
        cerr << "Error loading the enemies!" << endl;
    }
    gameMap.generateLevel();
    gameMap.generateEnemy();
    actions = new Actions(gameMap);
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
        } else if (const auto* mouseMoved = event->getIf<Event::MouseMoved>()) {
            gui.update(mouseMoved->position, false);
        } else if (const auto* mousePressed = event->getIf<Event::MouseButtonPressed>()) {
            if (mousePressed->button == Mouse::Button::Left) {
                gui.update(mousePressed->position, true);
            }
        }
    }
}

void Game::update() {
    if (gui.startGame) {
        actions->playerJump(player, gameMap);
        actions->playerMoveForward(player, gameMap);
        actions-> playerMoveBackward(player, gameMap);
        actions->monsterAttack(player, gameMap);
        player.generatePlayer(map);
        player.checkLevel(player);
        actions->applyGravity(player, gameMap);
        actions->damageText.clearTexts();
    }
}

void Game::render() {
    desktopWindow.clear(Color::White);
    if (!gui.startGame) {
        gui.drawMenu(desktopWindow);
    }
    if (gui.startGame) {
        gameMap.drawMap(desktopWindow);
        player.drawPlayer(desktopWindow);
        gameMap.updateEnemies(desktopWindow);
        actions->damageText.drawTexts(desktopWindow);
        player.drawHealthBar(desktopWindow);
        player.drawExpBar(desktopWindow);
    }
    desktopWindow.display();
}
