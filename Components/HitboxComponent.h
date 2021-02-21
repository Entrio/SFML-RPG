/**
 * Created by Alexander Titarenko <westal@gmail.com> on 21/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#ifndef SFML_RPG_HITBOXCOMPONENT_H
#define SFML_RPG_HITBOXCOMPONENT_H

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class HitboxComponent {
private:

    //region Private variables
    sf::RectangleShape hitbox;
    sf::Sprite &sprite;

    float xOffset, yOffset;
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
    HitboxComponent(sf::Sprite &sprite, float xOffset, float yOffset, float width, float height);
    ~HitboxComponent();
    //endregion

    //region Public variables
    //endregion

    //region Public functions
    void update();
    void render(sf::RenderTarget &target);
    bool checkIntersect(const sf::FloatRect &fRect);
    //endregion

};


#endif //SFML_RPG_HITBOXCOMPONENT_H
