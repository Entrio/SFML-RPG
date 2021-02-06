//
// Created by alex on 6/2/21.
//

#include "Entity.h"


//region Constructor / Destructor
//endregion

Entity::Entity() {
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->movementSpeed = 20.f;
}

Entity::~Entity() = default;

void Entity::move(const float &deltaTime, float x, float y) {
    this->shape.move(x * this->movementSpeed * deltaTime, y * this->movementSpeed * deltaTime);
}