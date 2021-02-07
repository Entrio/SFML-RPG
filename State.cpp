//
// Created by alex on 6/2/21.
//

#include "State.h"

//region Constructors / Destructors

State::State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys) {
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->wantsToEndState = false;
}

State::~State() {

}

const bool &State::getEnd() const {
    return this->wantsToEndState;
}

void State::checkForEnd() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["Terminate"]))) {
        this->wantsToEndState = true;
    }
}

//endregion

//region Methods
//endregion