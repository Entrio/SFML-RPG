/**
 * Created by Alexander Titarenko <westal@gmail.com> on 7/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#ifndef SFML_RPG_BUTTON_H
#define SFML_RPG_BUTTON_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

enum button_states {
    BTN_IDLE = 0,
    BTN_PRESSED,
    BTN_HOVER,
};

class Button {
private:

    //region Private variables

    short unsigned state;           // Current button state
    short unsigned oldState;        // Previous frame button state

    sf::RectangleShape shape;
    sf::Font *font;
    sf::Text text;

    sf::Color idleColour, hoverColour, activeColour;

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
    Button(float x,
           float y,
           float width,
           float height,
           const std::string &text,
           unsigned int fontSize,
           sf::Font *font,
           sf::Color idleColour = sf::Color::Blue,
           sf::Color hoverColour = sf::Color::Red,
           sf::Color activeColour = sf::Color::Magenta
    );
    ~Button();

    //endregion

    //region Accessors

    bool IsPressed() const;

    //endregion

    //region Public variables
    //endregion

    //region Public functions

    void update(const sf::Vector2f &mousePos);
    void render(sf::RenderTarget *target);

    //endregion
};


#endif //SFML_RPG_BUTTON_H
