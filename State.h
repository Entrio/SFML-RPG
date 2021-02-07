//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_STATE_H
#define SFML_RPG_STATE_H

#include "Entity.h"

class State {

protected:
    sf::RenderWindow *window;
    std::map<std::string, int> *supportedKeys;
    std::map<std::string, int> keyBinds;        // State specific key binds

    virtual void stateKeyBinds() = 0;           // Each state has to define their own keys

private:

    //region Variables

    std::vector<sf::Texture *> textures;
    bool wantsToEndState;

    //endregion

    //region Functions
    //endregion

public:
    State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);

    virtual ~State();

    const bool &getEnd() const;

    virtual void checkForEnd();

    virtual void endState() = 0;

    virtual void updateInput(const float &dt) = 0;

    virtual void update(const float &deltaTime) = 0;

    virtual void render(sf::RenderTarget *target = nullptr) = 0;

};


#endif //SFML_RPG_STATE_H
