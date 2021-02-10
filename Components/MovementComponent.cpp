/**
 * Created by Alexander Titarenko <westal@gmail.com> on 10/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#include "MovementComponent.h"

//region Constructor / Destruct

MovementComponent::MovementComponent(
        sf::Sprite &sprite,
        float maxVelocity,
        float acceleration,
        float deceleration
) : sprite(sprite),
    maxVelocity(maxVelocity),
    acceleration(acceleration),
    deceleration(deceleration) {
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

    //Deceleration

    if (this->velocity.x > 0.f) {
        this->velocity.x -= deceleration;
        if (this->velocity.x < 0.f) {
            velocity.x = 0.f;
        }
    } else if (this->velocity.x < 0.f) {
        this->velocity.x += deceleration;
        if (this->velocity.x > 0.f) {
            velocity.x = 0.f;
        }
    }

    // Final move
    this->sprite.move(this->velocity * deltaTime);
}

void MovementComponent::move(const float dirX, const float dirY, const float &deltaTime) {

    /**
     * Accelerating a sprite until it reaches max velocity
     */

    // Acceleration
    this->velocity.x += this->acceleration * dirX;

    if (this->velocity.x > 0.f) { // going to the right
        if (this->velocity.x > this->maxVelocity) {
            // we are going as fast as we can already
            this->velocity.x = maxVelocity;
        }
    } else if (this->velocity.x < 0.f) { // going to the left
        if (this->velocity.x < -this->maxVelocity) {
            // we are going as fast as we can already
            this->velocity.x = -maxVelocity;
        }
    }

    this->velocity.y = this->maxVelocity * dirY;
}


//endregion
