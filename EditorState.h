/**
 * Created by Alexander Titarenko <westal@gmail.com> on 07/02/2021
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#ifndef SFML_RPG_EDITORSTATE_H
#define SFML_RPG_EDITORSTATE_H

#include "State.h"
#include "UI/Button.h"

class EditorState : public State {
private:

    //region Private variables

    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button *> buttons;

    //endregion

    //region Private functions

    void InitializeVariables();
    void stateKeyBinds();
    void InitializeFonts();
    void InitializeTextures();
    void SetupButtons();
    void setupBackground();

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

    EditorState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states);

    virtual ~EditorState();

    //endregion

    //region Public functions
    void onBeforeEndState();
    void updateInput(const float &deltaTime);
    void update(const float &deltaTime);
    void render(sf::RenderTarget *target = nullptr);
    //endregion

};

#endif //SFML_RPG_MAINMENUSTATE_H
