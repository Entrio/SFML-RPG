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

void State::endState() {
    this->wantsToEndState = true;
}

void State::checkForEnd() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["Terminate"]))) {
        this->endState();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["DEBUG"]))) {
        this->drawDebug = !this->drawDebug;
    }
}

void State::updateMousePosition() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

    if (!drawDebug) return;
    mousePosText.setPosition(this->mousePosView.x, this->mousePosView.y - 20.0f);
    std::stringstream temp;
    ss.swap(temp);
    ss << this->mousePosView.x << "," << this->mousePosView.y;
    mousePosText.setString(ss.str());
}

void State::LoadAssets() {
    this->InitializeFonts();
    if (!this->debugFont.loadFromFile("assets/fonts/slkscr.ttf")) {
        std::cerr << "ERROR::NON_CRITICAL::STATE::DEBUG_FONT_NOT_FOUND" << std::endl;
    } else {
        std::cout << "State::LoadAssets" << std::endl;
        mousePosText.setFont(this->debugFont);
        mousePosText.setCharacterSize(15);
    }
}

void State::render(sf::RenderTarget *target) {
    if (!drawDebug) return;
    target->draw(mousePosText);
}

//endregion