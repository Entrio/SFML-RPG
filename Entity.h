//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_ENTITY_H
#define SFML_RPG_ENTITY_H

#include "Components/HitboxComponent.h"
#include "Components/MovementComponent.h"
#include "Components/AnimationComponent.h"

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
    sf::Sprite sprite;
    sf::Texture *texture;

    HitboxComponent *hitboxComponent;
    MovementComponent *movementComponent;
    AnimationComponent *animationComponent;

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
    virtual void move(float x, float y, const float &deltaTime);
    virtual void render(sf::RenderTarget *target);

    //region Component Functions
    virtual void setPosition(float x, float y);
    void setTexture(sf::Texture &texture);
    void createMovementComponent(float maxVelocity, float acceleration, float deceleration);
    void createAnimationComponent(sf::Texture &spriteSheet);
    //endregion

    //endregion
};


#endif //SFML_RPG_ENTITY_H
