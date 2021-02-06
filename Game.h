//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_GAME_H
#define SFML_RPG_GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

class Game {

private:

    //region Variables

    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float deltaTime;

    //endregion

    //region Initialization

    void InitializeWindow();

    //endregion

    //region Constructors / Destructors

    //endregion

public:
    Game();

    virtual ~Game();

    void updateSFMLEvents();

    void updateDeltaTime();

    void update();

    void render();

    void run();
};


#endif //SFML_RPG_GAME_H
