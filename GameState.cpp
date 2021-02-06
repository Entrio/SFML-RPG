//
// Created by alex on 6/2/21.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow *window) : State(window) {

}

GameState::~GameState() {

}

void GameState::endState() {
    std::cout << "GameState has ended \n\n";
}

void GameState::updateKeybinds(const float &deltaTime) {
    this->checkForEnd();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "A has been pressed \n\n";
    }
}

void GameState::update(const float &deltaTime) {
    this->updateKeybinds(deltaTime);
}

void GameState::render(sf::RenderTarget *target) {

}





