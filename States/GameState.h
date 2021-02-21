//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_GAMESTATE_H
#define SFML_RPG_GAMESTATE_H

#include "State.h"

class GameState : public State {

private:
    Player *player;

    //region Functions

    void stateKeyBinds();
    void InitializeFonts();
    void InitializeTextures();
    void InitializePlayers();

    //endregion

public:
    GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states);
    virtual ~GameState();
    void onBeforeEndState();
    void updateInput(const float &deltaTime);
    void update(const float &deltaTime);
    void render(sf::RenderTarget *target = nullptr);
};


#endif //SFML_RPG_GAMESTATE_H
