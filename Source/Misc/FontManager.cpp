//
// Created by arnol on 4/20/2025.
//

#include "FontManager.h"

void FontManager::writeText(string text, int textSize, string enteredColor, int positionX, int positionY) {

    srand(time(nullptr));
    int offsetX = rand() % 10;
    int offsetY = rand() % 10;

    positionX = positionX * 64 - 32 + offsetX;
    positionY = positionY * 64 - 10 + offsetY;
    text = "-" + text;

    Color color;
    if (enteredColor == "red") {
        color = Color::Red;
    } else if (enteredColor == "green") {
        color = Color::Green;
    } else if (enteredColor == "blue") {
        color = Color::Blue;
    } else if (enteredColor == "yellow") {
        color = Color::Yellow;
    } else if (enteredColor == "black") {
        color = Color::Black;
    }

    Text textToDraw(font);
    textToDraw.setString(text);
    textToDraw.setCharacterSize(textSize);
    textToDraw.setFillColor(color);
    textToDraw.setPosition(Vector2f(positionX, positionY));

    floatingTexts.push_back(textToDraw);
}

void FontManager::drawTexts(RenderWindow &window) {
    for (Text t : floatingTexts) {
        window.draw(t);
    }
}

void FontManager::clearTexts() {
    if (clock.getElapsedTime().asMilliseconds() >= 500) {
        floatingTexts.clear();
        clock.restart();
    }
}
