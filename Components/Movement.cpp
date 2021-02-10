/**
 * Created by Alexander Titarenko <westal@gmail.com> on 10/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#include "Movement.h"

//region Constructor / Destruct

MovementComponent::MovementComponent(float maxVelocity) {
    this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent() = default;

//endregion

//region Accessors

const sf::Vector2f &MovementComponent::getVelocity() const {
    return this->velocity;
}

//endregion

//region Public functions

void MovementComponent::update(const float &deltaTime) {

}

void MovementComponent::move(const float dirX, const float dirY) {
    this->velocity.x = this->maxVelocity * dirX;
    this->velocity.y = this->maxVelocity * dirY;
}


//endregion
