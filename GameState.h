//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_GAMESTATE_H
#define SFML_RPG_GAMESTATE_H

#include "State.h"

class GameState : public State {

private:
    Entity player;

public:
    GameState(sf::RenderWindow *window);

    virtual ~GameState();

    void endState();

    void updateInput(const float &deltaTime);

    void update(const float &deltaTime);

    void render(sf::RenderTarget *target = nullptr);
};


#endif //SFML_RPG_GAMESTATE_H
