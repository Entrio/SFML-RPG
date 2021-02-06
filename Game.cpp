//
// Created by alex on 6/2/21.
//

#include "Game.h"

//region Initializers

void Game::InitializeWindow() {

    /* Load the config file */
    std::ifstream ifs("game.ini");

    /* Set default values that will be changed via the config file */
    std::string title = "SFML Window";
    sf::VideoMode windowsBounds(800, 600);
    unsigned int frameRateLimit = 60;
    bool isVerticalSync = false;

    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> windowsBounds.width >> windowsBounds.height;     // Read the width Height
        ifs >> frameRateLimit;
        ifs >> isVerticalSync;

        ifs.close();
    }

    this->window = new sf::RenderWindow(windowsBounds, title);
    this->window->setFramerateLimit(frameRateLimit);
    this->window->setVerticalSyncEnabled(isVerticalSync);

}

void Game::InitializeStates() {
    this->states.push(new GameState(this->window));
}

//endregion


//region Constructors / Destructors
Game::Game() {
    this->InitializeWindow();
    this->InitializeStates();
}

Game::~Game() {
    delete this->window;

    while (!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
}

//endregion

void Game::updateSFMLEvents() {
    while (this->window->pollEvent(this->sfEvent)) {
        if (this->sfEvent.type == sf::Event::Closed) {
            this->window->close();
        }
    }
}

void Game::updateDeltaTime() {

    /* Update the deltaTime variable with the time it takes to render a single frame */

    this->deltaTime = this->dtClock.restart().asSeconds();
}

void Game::update() {
    this->updateSFMLEvents();

    if (!this->states.empty()) {
        this->states.top()->update(this->deltaTime);
    }
}

void Game::render() {

    this->window->clear();

    // Draw the game
    if (!this->states.empty()) {
        this->states.top()->render(this->window);
    }

    this->window->display();

}

void Game::run() {
    while (this->window->isOpen()) {
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}






