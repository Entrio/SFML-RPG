/**
 * Created by Alexander Titarenko <westal@gmail.com> on 10/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#include "Player.h"

//region Constructor / Destruct

Player::Player(float x, float y, sf::Texture *texture) {
    this->initVariables();
    this->initComponents();

    this->createSprite(texture);
    this->setPosition(x, y);
}
Player::~Player() {}

//endregion

void Player::initVariables() {

}

void Player::initComponents() {

}
