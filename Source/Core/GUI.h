//
// Created by arnol on 4/21/2025.
//

#ifndef GUI_H
#define GUI_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <Map>
#include "../Misc/FontManager.h"
#include "../Misc/Button.h"

using namespace sf;
using namespace std;


class GUI {

public:

    void drawMenu(RenderWindow &window);
    void update (Vector2i mousePos, bool isPressed);
    void generateMenu();
    void buttonIsClicked(Vector2i mousePos, bool isPressed);
    bool startGame = false;
    bool levelsMenu = false;
    bool savesMenu = false;

private:
    vector<vector<int>> tiles = {
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
{ 4, 0, 0, 5, 0, 0, 0, 0, 0, 4 },
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
{ 4, 0, 0, 5, 0, 0, 0, 0, 0, 4 },
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
{ 4, 0, 0, 5, 0, 0, 0, 0, 0, 4 },
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 3 }
    };
    vector<int> playButton;
    vector<int> levelsButton;
    vector<int> savesButton;
    map<int, Texture> texturesMap;
    vector<Button> buttons;
    vector<Sprite> menuSprites;
    vector<Text> buttonTexts;
    vector<string> backTilePaths = {
        "../Assets/Textures/Gui/Tiles/0.png",
        "../Assets/Textures/Gui/Tiles/1.png",
        "../Assets/Textures/Gui/Tiles/2.png",
        "../Assets/Textures/Gui/Tiles/3.png",
        "../Assets/Textures/Gui/Tiles/4.png"
    };
    string buttonTilePath = "../Assets/Textures/Gui/Buttons/1.png";
    FontManager fontManager;
    Texture texture;
    void loadGuiTiles();
    void loadGuiButtons();
    void generateButtons();
};



#endif //GUI_H
