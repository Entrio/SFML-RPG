/**
 * Created by Alexander Titarenko <westal@gmail.com> on 10/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#include "Player.h"

//region Constructor / Destruct

Player::Player(float x, float y, sf::Texture &texture) {
    this->initVariables();
    this->initComponents();

    this->setTexture(texture);
    this->setPosition(x, y);
}
Player::~Player() {}

//endregion

void Player::initVariables() {

}

void Player::initComponents() {
    this->createMovementComponent(100.f, 9.f, 0.2);
}

