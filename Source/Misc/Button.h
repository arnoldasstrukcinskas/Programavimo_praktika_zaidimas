//
// Created by arnol on 4/21/2025.
//

#ifndef BUTTONS_H
#define BUTTONS_H
#include "FontManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


class Button {

public:

    FontManager fontManager;
    vector<Sprite> buttonSprite;
    vector<Text> buttonText;
    bool isHovered;
    bool isClicked;

    void updateHoover(Vector2i mousePos, Button &button);
    void checkClick(Vector2i mousePos, bool isPressed);
    void resetClick();
    void setText(Text &text);

    int number1() {
        return number;
    }

    void set_number(int number) {
        this->number = number;
    }

private:
    int number = 0;
    String start = "Start";
    String levels = "Levels";
    String saves = "Saves";
};



#endif //BUTTONS_H
