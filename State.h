//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_STATE_H
#define SFML_RPG_STATE_H

#include "Entity.h"

class State {

protected:
    std::stack<State *> *states;
    sf::RenderWindow *window;
    std::map<std::string, int> *supportedKeys;
    std::map<std::string, int> keyBinds;        // State specific key binds

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    bool wantsToEndState;

    virtual void stateKeyBinds() = 0;           // Each state has to define their own keys
    virtual void InitializeFonts() = 0;
    virtual void LoadAssets();

private:

    //region Variables

    std::vector<sf::Texture *> textures;


    //endregion

    //region Functions



    //endregion

public:
    State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states);
    virtual ~State();
    const bool &getEnd() const;
    virtual void checkForEnd();
    virtual void endState() = 0;
    virtual void updateMousePosition();
    virtual void updateInput(const float &dt) = 0;
    virtual void update(const float &deltaTime) = 0;
    virtual void render(sf::RenderTarget *target = nullptr) = 0;
};


#endif //SFML_RPG_STATE_H
