//
// Created by arnol on 4/20/2025.
//

#ifndef FONTMANAGER_H
#define FONTMANAGER_H
#include<SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;



class FontManager {

public:
    FontManager(){
        if (!font.openFromFile("../Assets/textFont.ttf")) {
            cout << "error" << endl;
        } else {
        }
    }

    Font font;
    Clock clock;
    vector<Text> floatingTexts;
    void writeText(string text, int textSize, string enteredColor, int positionX, int positionY);
    void drawTexts(RenderWindow& window);
    void clearTexts();
};



#endif //FONTMANAGER_H
