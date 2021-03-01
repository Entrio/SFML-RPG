/**
 * Created by Alexander Titarenko <westal@gmail.com> on 10/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#include "Player.h"

//region Constructor / Destruct

Player::Player(float x, float y, sf::Texture &spriteSheet) {
    this->initVariables();
    this->setPosition(x, y);

    this->createHitboxComponent(this->sprite, 6.f, 0.f, 20.f, 32.f);
    this->createMovementComponent(150.f, 15.f, 8.f);
    this->createAnimationComponent(spriteSheet);

    this->animationComponent->addAnimation("IDLE", 0, 0, 32, 32, 9, 10.0f);
    this->animationComponent->addAnimation("WALK", 0, 64, 32, 32, 9, 10.0f);
}
Player::~Player() = default;

//endregion

void Player::initVariables() {

}
void Player::update(const float &deltaTime) {
    Entity::update(deltaTime);

    if (this->movementComponent->getState(IDLE)) {
        if (this->animationComponent) {
            this->animationComponent->play("IDLE", deltaTime);
        }
    } else if (this->movementComponent->getState(MOVING_LEFT)) {
        // we are not idle
        if (this->animationComponent) {
            this->sprite.setScale(-1.f, 1.f);
            this->sprite.setOrigin(32.f,0.f);
            this->animationComponent->play("WALK", deltaTime);
        }
    } else if (this->movementComponent->getState(MOVING_RIGHT)) {
        // we are not idle
        if (this->animationComponent) {
            this->sprite.setScale(1.f, 1.f);
            this->sprite.setOrigin(0.f,0.f);
            this->animationComponent->play("WALK", deltaTime);
        }
    } else if (this->movementComponent->getState(MOVING_UP)) {
        // we are not idle
        if (this->animationComponent) {
            this->animationComponent->play("WALK", deltaTime);
        }
    } else if (this->movementComponent->getState(MOVING_DOWN)) {
        // we are not idle
        if (this->animationComponent) {
            this->animationComponent->play("WALK", deltaTime);
        }
    }

    this->hitboxComponent->update();
}
