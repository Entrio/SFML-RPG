//
// Created by alex on 6/2/21.
//

#ifndef SFML_RPG_STATE_H
#define SFML_RPG_STATE_H

#include "Entity.h"

class State {

protected:
    sf::RenderWindow *window;
    std::vector<sf::Texture *> textures;
    bool wantsToEndState;

private:

    //region Variables




    //endregion

    //region Functions
    //endregion

public:
    State(sf::RenderWindow *window);

    virtual ~State();

    const bool &getEnd() const;

    virtual void checkForEnd();

    virtual void endState() = 0;

    virtual void updateInput(const float &dt) = 0;

    virtual void update(const float &deltaTime) = 0;

    virtual void render(sf::RenderTarget *target = nullptr) = 0;

};


#endif //SFML_RPG_STATE_H
