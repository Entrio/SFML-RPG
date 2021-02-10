/**
 * Created by Alexander Titarenko <westal@gmail.com> on 10/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#ifndef SFML_RPG_PLAYER_H
#define SFML_RPG_PLAYER_H


#include "Entity.h"

class Player : public Entity {
private:
    void initVariables();
    void initComponents();
protected:
public:
    Player(float x, float y, sf::Texture *texture);
    ~Player();
};


#endif //SFML_RPG_PLAYER_H
