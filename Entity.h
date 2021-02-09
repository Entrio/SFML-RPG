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

    // Debug entity box
    sf::RectangleShape shape;

    /**
     * NB: The reason these are pointers, is because a texture/sprite that will be assigned to this
     * entity *SHOULD* have already been loaded somewhere prior.
     */
    sf::Sprite *sprite;
    sf::Texture *texture;

    float movementSpeed;
    //endregion

private:

    //region Functions

    void initialize();

    //endregion

public:
    //region Constructor / Destructor
    Entity();
    virtual ~Entity();
    //endregion

    //region Functions

    virtual void update(const float &deltaTime);
    virtual void move(const float &deltaTime, float x, float y);
    virtual void render(sf::RenderTarget *target);

    //region Component Functions
    void createSprite(sf::Texture *texture);
    //endregion

    //endregion
};


#endif //SFML_RPG_ENTITY_H
