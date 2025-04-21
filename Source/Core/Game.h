#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "../Misc/FontManager.h"
#include "../Systems/MapSystem/Map.h"
#include "../Systems/Player/Player.h"
#include "../Systems/Actions/Actions.h"


using namespace std;
using namespace sf;



class Game {

public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();
private:
    RenderWindow window;
    RenderWindow desktopWindow;
    Map map;
    Texture tileSet;
    Map gameMap;
    Player player;
    Actions *actions;
};





#endif //GAME_H
