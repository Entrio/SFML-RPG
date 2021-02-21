/**
 * Created by Alexander Titarenko <westal@gmail.com> on 21/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(
        sf::Sprite &sprite,
        float xOffset, float yOffset,
        float width, float height) :
        sprite(sprite),
        xOffset(xOffset),
        yOffset(yOffset) {
    this->hitbox.setPosition(this->sprite.getPosition().x + this->xOffset,
                             this->sprite.getPosition().y + this->yOffset);
    this->hitbox.setSize(sf::Vector2f(width, height));
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineThickness(1.0f);
    this->hitbox.setOutlineColor(sf::Color::Red);
}

HitboxComponent::~HitboxComponent() = default;

void HitboxComponent::update() {
    this->hitbox.setPosition(this->sprite.getPosition().x + this->xOffset,
                             this->sprite.getPosition().y + this->yOffset);
}

void HitboxComponent::render(sf::RenderTarget &target) {
    target.draw(this->hitbox);
}

bool HitboxComponent::checkIntersect(const sf::FloatRect &fRect) {
    return this->hitbox.getGlobalBounds().intersects(fRect);
}
