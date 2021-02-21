/**
 * Created by Alexander Titarenko <westal@gmail.com> on 10/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#ifndef SFML_RPG_MOVEMENTCOMPONENT_H
#define SFML_RPG_MOVEMENTCOMPONENT_H

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class MovementComponent {
private:

    //region Private variables

    sf::Sprite &sprite;

    sf::Vector2f velocity;
    float maxVelocity;
    float acceleration, deceleration;

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

    MovementComponent(sf::Sprite &sprite, float maxVelocity, float acceleration, float deceleration);
    ~MovementComponent();

    //endregion

    //Region Accessors

    const sf::Vector2f &getVelocity() const;
    bool idle() const;

    //endregion

    //region Public variables


    //endregion

    //region Public functions

    void update(const float &deltaTime);
    void move(float dirX, float dirY, const float &deltaTime);

    //endregion

};


#endif //SFML_RPG_MOVEMENTCOMPONENT_H
