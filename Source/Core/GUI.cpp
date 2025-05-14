//
// Created by arnol on 4/21/2025.
//

#include "GUI.h"

void GUI::generateMenu() {
    loadGuiTiles();
    loadGuiButtons();

    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            int tileId = tiles[row][col];
            if (texturesMap.find(tileId) != texturesMap.end()) {
                Sprite sprite(texturesMap[tileId]);
                sprite.setScale({4, 4});
                sprite.setPosition(Vector2f(col * 64 + 600, row * 64 + 200));
                menuSprites.push_back(sprite);
            }
        }
    }
    generateButtons();
}

void GUI::loadGuiTiles() {
    for (int i = 0; i < backTilePaths.size(); ++i) {
        Texture texture;
        if (!texture.loadFromFile(backTilePaths[i], false, IntRect({0, 0}, {16, 16}))) {
            cerr << "Failed to load tile " << i << endl;
        }
        texturesMap[i] = move(texture); // Store preloaded texture
    }
}

void GUI::loadGuiButtons() {
    Texture texture;
    if (!texture.loadFromFile(buttonTilePath, false, IntRect({0, 0}, {16, 16}))) {
        cerr << "Failed to load tile " << 5 << endl;
    }
    texturesMap[5] = move(texture); // Store preloaded texture
}

void GUI::generateButtons() {
    int buttoncCounter = 0;
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            int tileId = tiles[row][col];
            if (tileId == 5) {
                buttoncCounter++;
                Button button;

                cout << "button created" << endl;
                button.set_number(buttoncCounter);

                //setting text
                Text text(fontManager.font);
                button.setText(text);
                text.setPosition(Vector2f(col * 64 + 675, row * 64 + 200));
                buttonTexts.push_back(text);

                //setting sprite
                Sprite buttonSprite(texturesMap[tileId]);
                buttonSprite.setScale({16, 4});
                buttonSprite.setPosition(Vector2f(col * 64 + 600, row * 64 + 200));
                button.buttonSprite.push_back(buttonSprite);
                buttons.push_back(button);

            }
        }
    }
}

void GUI::drawMenu(RenderWindow &window) {

    for (Sprite sprite : menuSprites) {
        window.draw(sprite);
    }
    for (int i = 0; i < buttons.size(); ++i) {
        window.draw(buttons[i].buttonSprite[0]);
    }
    for (Text &text : buttonTexts) {
        window.draw(text);
    }
}

void GUI::update (Vector2i mousePos, bool isPressed){
    
    for (int i = 0; i < buttons.size(); ++i) {
        string checking = buttonTexts[i].getString();
        if (isPressed && checking == "Start") {
            startGame = true;
        }

        buttons[i].updateHoover(mousePos, buttons[i]);
        buttons[i].checkClick(mousePos, isPressed);
    }
}
