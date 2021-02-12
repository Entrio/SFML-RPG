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

    this->createMovementComponent(300.f, 15.f, 4.f);
    this->createAnimationComponent(spriteSheet);

    this->animationComponent->addAnimation("IDLE", 0, 128, 32, 32, 9, 10.0f);
}
Player::~Player() = default;

//endregion

void Player::initVariables() {

}
void Player::update(const float &deltaTime) {
    Entity::update(deltaTime);
    if (this->animationComponent) {
        this->animationComponent->play("IDLE", deltaTime);
    }
}
