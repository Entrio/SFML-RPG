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

void Entity::update(const float &deltaTime) {

}

void Entity::move(const float &deltaTime, float dirX, float dirY) {
    this->shape.move(dirX * this->movementSpeed * deltaTime, dirY * this->movementSpeed * deltaTime);
}

void Entity::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}