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
    delete this->sprite;
    delete this->movementComponent;
};
//endregion

//region Functions

void Entity::initialize() {
    this->sprite = nullptr;
    this->texture = nullptr;

    this->movementComponent = nullptr;
}

void Entity::update(const float &deltaTime) {

}

void Entity::move(const float &deltaTime, float dirX, float dirY) {
    if (this->sprite && this->movementComponent) {
        this->movementComponent->move(dirX, dirY);      // Sets teh velocity
        this->sprite->move(this->movementComponent->getVelocity() * deltaTime);     // Uses velocity
    }
}

void Entity::render(sf::RenderTarget *target) {
    if (this->sprite) {
        target->draw(*this->sprite);
    }
}

//region Component Functions
void Entity::createSprite(sf::Texture *sTexture) {
    this->texture = sTexture;
    this->sprite = new sf::Sprite(*this->texture);
}

void Entity::setPosition(const float x, const float y) {
    if (this->sprite) {
        this->sprite->setPosition(x, y);
    }
}

void Entity::createMovementComponent(float maxVelocity) {
    this->movementComponent = new MovementComponent(maxVelocity);
}

//endregion

//endregion