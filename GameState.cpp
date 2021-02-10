//
// Created by alex on 6/2/21.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
        : State(window,
                supportedKeys, states) {
    this->stateKeyBinds();
    this->InitializeTextures();
    this->InitializePlayers();
}

GameState::~GameState() {
    delete this->player;
}

/**
 * Initialize GameState key bindings. These are only available for this state
 */
void GameState::stateKeyBinds() {

    std::ifstream ifs("keyboard.ini");

    if (ifs.is_open()) {
        std::string key;
        std::string keyValue;

        while (ifs >> key >> keyValue) {
            this->keyBinds[key] = this->supportedKeys->at(keyValue);
        }
        ifs.close();
    }

    // Make sure that Escape is always the terminating key
    this->keyBinds["Terminate"] = this->supportedKeys->at("Escape");
    this->keyBinds["DEBUG"] = this->supportedKeys->at("F1");

    // State key bindings

    /**
    this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
    this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
     */
}

void GameState::updateInput(const float &deltaTime) {
    this->checkForEnd(); // Inherited from State

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT")))) {
        this->player->move(deltaTime, -5.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT")))) {
        this->player->move(deltaTime, 5.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP")))) {
        this->player->move(deltaTime, 0.f, -5.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN")))) {
        this->player->move(deltaTime, 0.f, 5.f);
    }
}

void GameState::update(const float &deltaTime) {
    this->updateMousePosition();
    this->updateInput(deltaTime);
    this->player->update(deltaTime);
}

void GameState::render(sf::RenderTarget *target) {

    if (!target) {
        target = this->window;
    }
    this->player->render(target);
}


void GameState::InitializeFonts() {
    std::cout << "InitializeFonts::GameState" << std::endl;
}

void GameState::InitializeTextures() {
    std::cout << "InitializeTextures::GameState" << std::endl;

    if (!this->textures["PLAYER_IDLE"].loadFromFile(
            "assets/sprites/warrior spritesheet calciumtrice.png", sf::IntRect(0, 0, 32, 32)
    )) {
        std::cout << "GameState::InitializeTextures::loadFromFile" << std::endl;
        throw "Failed to load player textures";
    }
}
void GameState::InitializePlayers() {
    this->player = new Player(0.f, 0.f, this->textures["PLAYER_IDLE"]);
}



