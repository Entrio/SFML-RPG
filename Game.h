//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_GAME_H
#define SFML_RPG_GAME_H

#include "GameState.h"
#include "MainMenuState.h"
#include "UI/Button.h"

class Game {

private:

    //region Variables

    sf::RenderWindow *window;
    sf::Event sfEvent;
    sf::Clock dtClock;
    float deltaTime;
    std::stack<State *> states;
    std::map<std::string, int> supportedKeys;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings windowContextSettings;
    bool isFullscreen = false;
    bool isVerticalSync = false;

    //endregion

    //region Initialization

    void InitializeWindow();
    void InitializeStates();
    void InitializeKeys();

    //endregion

    //region Constructors / Destructors

    //endregion

public:
    Game();

    virtual ~Game();


    //region Functions
    void updateSFMLEvents();

    void updateDeltaTime();

    void update();

    void render();

    void run();

    void endApplication();

    //endregion
};


#endif //SFML_RPG_GAME_H
