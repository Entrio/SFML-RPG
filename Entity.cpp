//
// Created by alex on 6/2/21.
//

#include "Entity.h"

//region Constructor / Destructor
Entity::Entity() {
    this->initialize();
}

Entity::~Entity() {
    // Deleting nullptr has no effect
    delete this->movementComponent;
    delete this->animationComponent;
    delete this->hitboxComponent;
};
//endregion

//region Functions

void Entity::initialize() {
    this->texture = nullptr;
    this->movementComponent = nullptr;
    this->animationComponent = nullptr;
    this->hitboxComponent = nullptr;
}

void Entity::update(const float &deltaTime) {
    if (this->movementComponent) {
        this->movementComponent->update(deltaTime);
    }
}

void Entity::move(float dirX, float dirY, const float &deltaTime) {
    if (this->movementComponent) {
        this->movementComponent->move(dirX, dirY, deltaTime);
    }
}

void Entity::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
    if (this->hitboxComponent) {
        this->hitboxComponent->render(target);
    }
}

//region Component Functions

void Entity::setTexture(sf::Texture &sTexture) {
    this->texture = &sTexture;
    this->sprite.setTexture(sTexture);
}

void Entity::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Entity::createMovementComponent(float maxVelocity, const float acceleration, const float deceleration) {
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture &spriteSheet) {
    this->animationComponent = new AnimationComponent(this->sprite, spriteSheet);
}

void Entity::createHitboxComponent(sf::Sprite &spriteRef, float xOffset, float yOffset, float width, float height) {
    this->hitboxComponent = new HitboxComponent(spriteRef, xOffset, yOffset, width, height);
}

//endregion

//endregion