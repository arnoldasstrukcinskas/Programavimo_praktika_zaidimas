//
// Created by arnol on 4/21/2025.
//

#include "Button.h"



void Button::updateHoover(Vector2i mousePos, Button &button) {
    FloatRect buttonBounds = button.buttonSprite.at(0).getGlobalBounds();
    isHovered = buttonBounds.contains(Vector2f(mousePos));

    if (isHovered) {
        button.buttonSprite.at(0).setColor(Color::Yellow);
    } else {
        button.buttonSprite.at(0).setColor(Color::White);
    }
}

void Button::checkClick(Vector2i mousePos, bool isPressed) {
    if (isPressed && isHovered) {
        cout << "button clicked" << endl;
        isClicked = true;
    }
}

void Button::resetClick() {
    isClicked = false;
}

void Button::setText(Text &text) {
    switch (number) {
        case 1:
            text.setString(start);
            break;
        case 2:
            text.setString(levels);
            break;
        case 3:
            text.setString(saves);
            break;
    }
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Black);
    text.setScale(Vector2f(3, 3));
}
