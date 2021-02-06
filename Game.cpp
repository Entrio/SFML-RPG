//
// Created by alex on 6/2/21.
//

#include "Game.h"

//region Initializers

void Game::InitializeWindow() {

    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML RPG");

}

//endregion


//region Constructors / Destructors
Game::Game() {
    this->InitializeWindow();
}

Game::~Game() {
    delete this->window;
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

    std::cout << this->deltaTime << "\n\n";
}

void Game::update() {
    this->updateSFMLEvents();
}

void Game::render() {

    this->window->clear();

    // Draw the game

    this->window->display();

}

void Game::run() {
    while (this->window->isOpen()) {
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}




