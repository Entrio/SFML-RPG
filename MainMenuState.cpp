//
// Created by alex on 7/2/21.
//

#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys) : State(window,
                                                                                                          supportedKeys) {
    this->stateKeyBinds();
    this->LoadAssets();

    this->testButton = new Button(
            10, 10, 250, 25, "Hello, world", 12, &this->font
    );

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color(100, 149, 237));        // Good ol cornflower blue
}

MainMenuState::~MainMenuState() {
    delete this->testButton;
}

void MainMenuState::endState() {
    std::cout << "GameState has ended \n\n";
}

void MainMenuState::updateInput(const float &deltaTime) {
    this->checkForEnd(); // Inherited from State

}

void MainMenuState::update(const float &deltaTime) {
    this->updateMousePosition();
    this->updateInput(deltaTime);
    this->testButton->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget *target) {
    if (!target) {
        target = this->window;
    }
    target->draw(this->background);
    this->testButton->render(target);
}

/**
 * Initialize GameState key bindings. These are only available for this state
 */
void MainMenuState::stateKeyBinds() {
    this->keyBinds["Terminate"] = this->supportedKeys->at("Escape");

    this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
    this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
}

void MainMenuState::InitializeFonts() {
    if (!this->font.loadFromFile("assets/fonts/slkscr.ttf")) {
        throw "Failed to load main menu fonts";
    }
}
