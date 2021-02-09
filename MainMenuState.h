/**
 * Created by Alexander Titarenko <westal@gmail.com> on 07/02/2021
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 * Followed tutorial: https://www.youtube.com/watch?v=IdKZpv6xqdw&list=PL6xSOsbVA1ebkU66okpi-KViAO8_9DJKg
 */


#ifndef SFML_RPG_MAINMENUSTATE_H
#define SFML_RPG_MAINMENUSTATE_H

#include "State.h"
#include "UI/Button.h"

class MainMenuState : public State {

private:

    //region Private variables

    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    //endregion

    //region Private functions

    void stateKeyBinds();
    void InitializeFonts();
    void SetupButtons();

    //endregion

protected :
    //region Protected variables
    //endregion

    //region Protected functions
    //endregion

public:

    //region Public variables
    //endregion

    //region Constructor / Destructor

    MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);

    virtual ~MainMenuState();

    //endregion

    //region Public functions


    void endState();

    void updateInput(const float &deltaTime);

    void update(const float &deltaTime);

    void render(sf::RenderTarget *target = nullptr);
    //endregion

};


#endif //SFML_RPG_MAINMENUSTATE_H
