//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_GAMESTATE_H
#define SFML_RPG_GAMESTATE_H

#include "State.h"

class GameState : public State {

private:

public:
    GameState(sf::RenderWindow *window);

    virtual ~GameState();

    void endState();

    void update(const float &deltaTime);

    void render(sf::RenderTarget *target = nullptr);
};


#endif //SFML_RPG_GAMESTATE_H
