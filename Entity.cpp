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
};
//endregion

//region Functions

void Entity::initialize() {
    this->texture = nullptr;

    this->movementComponent = nullptr;
}

void Entity::update(const float &deltaTime) {

}

void Entity::move(const float &deltaTime, float dirX, float dirY) {
    if (this->movementComponent) {
        this->movementComponent->move(dirX, dirY, deltaTime);
    }
}

void Entity::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
}

//region Component Functions
void Entity::setTexture(sf::Texture &sTexture) {
    this->texture = &sTexture;
    this->sprite.setTexture(sTexture);
}

void Entity::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Entity::createMovementComponent(float maxVelocity) {
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity);
}

//endregion

//endregion