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

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class State {

private:

    //region Variables

    std::vector<sf::Texture *> textures;

    //endregion

    //region Functions
    //endregion

public:
    State();

    virtual ~State();

    virtual void update() = 0;

    virtual void render() = 0;

};


#endif //SFML_RPG_STATE_H
