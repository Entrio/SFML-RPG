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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->move(deltaTime, -1.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->move(deltaTime, 1.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->move(deltaTime, 0.f, -1.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->move(deltaTime, 0.f, 1.f);
    }
}

void Entity::move(const float &deltaTime, float dirX, float dirY) {
    this->shape.move(dirX * this->movementSpeed * deltaTime, dirY * this->movementSpeed * deltaTime);
}

void Entity::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}