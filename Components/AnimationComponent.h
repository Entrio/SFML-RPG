/**
 * Created by Alexander Titarenko <westal@gmail.com> on 12/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#ifndef SFML_RPG_ANIMATIONCOMPONENT_H
#define SFML_RPG_ANIMATIONCOMPONENT_H

#include <iostream>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class AnimationComponent {
private:

    //region Private Classes

    class Animation {
    public:

        sf::Sprite &sprite;
        sf::Texture &spriteSheet;
        float animTimer, timer;
        int width, height;
        sf::IntRect startRect, currentRect, endRect;

        explicit Animation(
                sf::Sprite &sprite,
                sf::Texture &spriteSheet,
                int startX, int startY,
                int width, int height,
                int frames,
                float speed
        );
        ~Animation();

        void play(const float &deltaTime);
        void reset();
    };

    //endregion

    //region Private variables

    std::map<std::string, Animation *> animations;
    sf::Sprite &sprite;
    sf::Texture &spriteSheet;

    //endregion

    //region Private functions
    //endregion

protected:

    //region Protected variables
    //endregion

    //region Protected functions
    //endregion

public:

    //region Constructor / Destruct
    AnimationComponent(sf::Sprite &sprite, sf::Texture &spriteSheet);
    ~AnimationComponent();
    //endregion

    //region Public variables
    //endregion

    //region Public functions

    void addAnimation(
            std::string animationName,
            int startX, int startY,
            int width, int height,
            int frames,
            float speed
    );

    void play(std::string animationName, const float &deltaTime);

    //endregion

};


#endif //SFML_RPG_ANIMATIONCOMPONENT_H
