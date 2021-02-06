//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_STATE_H
#define SFML_RPG_STATE_H

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class State {

private:

    //region Variables

    sf::RenderWindow *window;
    std::vector<sf::Texture *> textures;
    bool wantsToEndState;

    //endregion

    //region Functions
    //endregion

public:
    State(sf::RenderWindow *window);

    virtual ~State();

    const bool &getEnd() const;

    virtual void checkForEnd();

    virtual void endState() = 0;

    virtual void updateKeybinds(const float &dt) = 0;

    virtual void update(const float &deltaTime) = 0;

    virtual void render(sf::RenderTarget *target = nullptr) = 0;

};


#endif //SFML_RPG_STATE_H
