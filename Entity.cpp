//
// Created by alex on 6/2/21.
//

#include "Entity.h"

//region Constructor / Destructor
Entity::Entity() {
    this->initialize();
}

Entity::~Entity() {
    if (this->sprite)
        delete this->sprite;
};
//endregion

//region Functions

void Entity::initialize() {
    //this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->sprite = nullptr;
    this->texture = nullptr;
    this->movementSpeed = 20.0f;
}

void Entity::update(const float &deltaTime) {

}

void Entity::move(const float &deltaTime, float dirX, float dirY) {
    if (this->sprite) {
        this->sprite->move(
                dirX * this->movementSpeed * deltaTime,
                dirY * this->movementSpeed * deltaTime
        );
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

//endregion

//endregion