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

bool MovementComponent::getState(const unsigned short state) const {

    switch (state) {
        case IDLE:
            if (this->velocity.x == 0.f && this->velocity.y == 0.f) {
                return true;
            }
            break;
        case MOVING:
            if (this->velocity.x != 0.f || this->velocity.y != 0.f) {
                return true;
            }
            break;
        case MOVING_LEFT:
            if (this->velocity.x < 0.f) {
                return true;
            }
            break;
        case MOVING_RIGHT:
            if (this->velocity.x > 0.f) {
                return true;
            }
            break;
        case MOVING_DOWN:
            if (this->velocity.y > 0.f) {
                return true;
            }
            break;
        case MOVING_UP:
            if (this->velocity.y < 0.f) {
                return true;
            }
            break;
    }

    return false;
}

//endregion

//region Public functions

void MovementComponent::update(const float &deltaTime) {

    //Deceleration

    /**
     * X positive and negative velocity checks
     */
    if (this->velocity.x > 0.f) {

        if (this->velocity.x > this->maxVelocity) {
            // we are going as fast as we can already
            this->velocity.x = maxVelocity;
        }

        this->velocity.x -= deceleration;
        if (this->velocity.x < 0.f) {
            velocity.x = 0.f;
        }
    } else if (this->velocity.x < 0.f) {

        if (this->velocity.x < -this->maxVelocity) {
            // we are going as fast as we can already
            this->velocity.x = -maxVelocity;
        }

        this->velocity.x += deceleration;
        if (this->velocity.x > 0.f) {
            velocity.x = 0.f;
        }
    }

    /**
     * Y Velocity check
     */
    if (this->velocity.y > 0.f) {

        if (this->velocity.y > this->maxVelocity) {
            // we are going as fast as we can already
            this->velocity.y = maxVelocity;
        }

        this->velocity.y -= deceleration;
        if (this->velocity.y < 0.f) {
            velocity.y = 0.f;
        }
    } else if (this->velocity.y < 0.f) {

        if (this->velocity.y < -this->maxVelocity) {
            // we are going as fast as we can already
            this->velocity.y = -maxVelocity;
        }

        this->velocity.y += deceleration;
        if (this->velocity.y > 0.f) {
            velocity.y = 0.f;
        }
    }

    // Final move
    this->sprite.move(this->velocity * deltaTime);
}

void MovementComponent::move(const float dirX, const float dirY, const float &deltaTime) {

    // Acceleration
    this->velocity.x += this->acceleration * dirX;
    this->velocity.y = this->maxVelocity * dirY;
}




//endregion
