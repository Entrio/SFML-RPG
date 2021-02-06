//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_ENTITY_H
#define SFML_RPG_ENTITY_H

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

class Entity {
/**
 * Protected variables are allowed in child classes
 */
protected:
    //region Variables
    sf::RectangleShape shape;
    float movementSpeed;
    //endregion

private:

    //region Functions
    //endregion

public:
    //region Constructor / Destructor
    Entity();

    virtual ~Entity();
    //endregion

    //region Functions

    virtual void update(const float &deltaTime) = 0;

    virtual void render(sf::RenderTarget *target) = 0;

    virtual void move(const float &deltaTime, float x, float y) = 0;

    //endregion
};


#endif //SFML_RPG_ENTITY_H
