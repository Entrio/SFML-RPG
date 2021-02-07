//
// Created by alex on 6/2/21.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys) : State(window,
                                                                                                  supportedKeys) {
    this->stateKeyBinds();
}

GameState::~GameState() {

}

void GameState::endState() {
    std::cout << "GameState has ended \n\n";
}

void GameState::updateInput(const float &deltaTime) {
    this->checkForEnd(); // Inherited from State

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT")))) {
        this->player.move(deltaTime, -1.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT")))) {
        this->player.move(deltaTime, 1.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP")))) {
        this->player.move(deltaTime, 0.f, -1.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN")))) {
        this->player.move(deltaTime, 0.f, 1.f);
    }
}

void GameState::update(const float &deltaTime) {
    this->updateInput(deltaTime);
    this->player.update(deltaTime);
}

void GameState::render(sf::RenderTarget *target) {

    if (!target) {
        target = this->window;
    }
    this->player.render(target);
}

/**
 * Initialize gamestate key bindings
 */
void GameState::stateKeyBinds() {
    // State key bindings
    this->keyBinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
    this->keyBinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
    this->keyBinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
    this->keyBinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
}





