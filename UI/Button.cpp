/**
 * Created by Alexander Titarenko <westal@gmail.com> on 7/2/21
 * Please respect author's work and credit where its due.
 *
 * Find me on github: https://github.com/Entrio
 *
 */

#include "Button.h"

//region Accessors

bool Button::IsPressed() const {
    return this->state == BTN_PRESSED;
}

//endregion

Button::Button(float x, float y, float width, float height, const std::string &text, unsigned int fontSize,
               sf::Font *font,
               sf::Color textIdleColour,
               sf::Color textHoverColour,
               sf::Color textActiveColour,
               sf::Color idleColour,
               sf::Color hoverColour,
               sf::Color activeColour
) :
        idleColour(idleColour),
        hoverColour(hoverColour),
        activeColour(activeColour),
        textIdleColour(textIdleColour),
        textActiveColour(textActiveColour),
        textHoverColour(textHoverColour) {

    this->state = BTN_IDLE;

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setPosition(sf::Vector2f(x, y));
    this->font = font;

    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setCharacterSize(fontSize);

    this->text.setPosition(
            this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) -
            this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) -
            this->text.getGlobalBounds().height
    );

    this->text.setFillColor(this->textIdleColour);
    this->shape.setFillColor(this->idleColour);
}

Button::~Button() {

}

void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}

void Button::update(const sf::Vector2f &mousePos) {
    /**
     * Update the booleans for hover and pressed
     */

    if (this->shape.getGlobalBounds().contains(mousePos)) {
        // the mouse is within the bounding box
        this->state = BTN_HOVER;

        // Check for press
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->state = BTN_PRESSED;
        }

    } else {
        // we are either not in bounds or have exited the bounds
        this->state = BTN_IDLE;
    }

    if (this->oldState != this->state) {
        switch (this->state) {
            case BTN_PRESSED:
                this->shape.setFillColor(this->activeColour);
                this->text.setFillColor(this->textActiveColour);
                break;
            case BTN_HOVER:
                this->shape.setFillColor(this->hoverColour);
                this->text.setFillColor(this->textHoverColour);
                break;
            default:
                this->shape.setFillColor(this->idleColour);
                this->text.setFillColor(this->textIdleColour);
                break;
        }
    }

    this->oldState = this->state;

}
