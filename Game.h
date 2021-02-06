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

    //endregion

    //region Initialization

    //endregion

    //region Constructors / Destructors

    //endregion

public:
    Game();

    virtual ~Game();

    void updateSFMLEvents();
    void update();

    void render();

    void run();
};


#endif //SFML_RPG_GAME_H
