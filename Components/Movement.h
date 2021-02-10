/**
 * Created by Alexander Titarenko <westal@gmail.com> on 10/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#ifndef SFML_RPG_MOVEMENT_H
#define SFML_RPG_MOVEMENT_H

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

    float maxVelocity;
    sf::Vector2f velocity, acceleration, deceleration;

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

    MovementComponent(float maxVelocity);
    ~MovementComponent();

    //endregion

    //Region Accessors

    const sf::Vector2f &getVelocity() const;

    //endregion

    //region Public variables


    //endregion

    //region Public functions

    void update(const float &deltaTime);
    void move(float dirX, float dirY);

    //endregion

};


#endif //SFML_RPG_MOVEMENT_H
