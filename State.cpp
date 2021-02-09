//
// Created by alex on 6/2/21.
//

#include "State.h"

//region Constructors / Destructors

State::State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states) {
    this->states = states;
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->wantsToEndState = false;
}

State::~State() {

}

//endregion

//region Methods

const bool &State::getEnd() const {
    return this->wantsToEndState;
}

void State::checkForEnd() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["Terminate"]))) {
        this->wantsToEndState = true;
    }
}

void State::updateMousePosition() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::LoadAssets() {
    this->InitializeFonts();

}

//endregion