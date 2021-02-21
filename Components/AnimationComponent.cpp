/**
 * Created by Alexander Titarenko <westal@gmail.com> on 12/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#include "AnimationComponent.h"

//region Constructor / Destruct

AnimationComponent::AnimationComponent(
        sf::Sprite &sprite,
        sf::Texture &spriteSheet
) : sprite(sprite),
    spriteSheet(spriteSheet),
    lastAnimation(nullptr) {

}

AnimationComponent::~AnimationComponent() {
    for (auto &a : this->animations) {
        delete a.second;
    }
};

AnimationComponent::Animation::Animation(
        sf::Sprite &sprite,
        sf::Texture &spriteSheet,
        int startX, int startY,
        int width, int height,
        int frames,
        float speed
) : sprite(sprite),
    spriteSheet(spriteSheet),
    width(width),
    height(height),
    animTimer(speed) {

    this->timer = 0.0f;
    this->startRect = sf::IntRect(startX, startY, width, height);
    this->currentRect = this->startRect;
    this->endRect = sf::IntRect((startX + width) * frames, startY, width, height);

    this->sprite.setTexture(this->spriteSheet, true);
    this->sprite.setTextureRect(this->startRect);
};
AnimationComponent::Animation::~Animation() = default;

//endregion

//region Animation class

void AnimationComponent::Animation::play(const float &deltaTime) {
    // update the timer
    this->timer += 100.f * deltaTime;
    if (this->timer >= this->animTimer) {
        // reset the time
        this->timer = 0.0f;

        if (this->currentRect != this->endRect) {
            // still got more frames to go
            this->currentRect.left += this->width;
        } else {
            // reset animation
            this->reset();
        }
        this->sprite.setTextureRect(this->currentRect);
    }
}

void AnimationComponent::Animation::reset() {
    this->currentRect.left = this->startRect.left;
}

//endregion

//region AnimationComaonent class

void AnimationComponent::addAnimation(
        const std::string animationName,
        int startX, int startY,
        int width, int height,
        int frames,
        float speed
) {
    this->animations[animationName] = new Animation(
            this->sprite,
            this->spriteSheet,
            startX, startY, width, height, frames, speed
    );
}

void AnimationComponent::play(const std::string animationName, const float &deltaTime) {

    if (this->lastAnimation != this->animations[animationName]) {
        if (this->lastAnimation == nullptr) {
            this->lastAnimation = this->animations[animationName];
        } else {
            this->lastAnimation->reset();
            this->lastAnimation = this->animations[animationName];
        }
    }

    this->animations[animationName]->play(deltaTime);
}

//endregion