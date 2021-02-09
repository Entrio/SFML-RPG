//
// Created by alex on 6/2/21.
//

#include "Game.h"

//region Initializers

void Game::InitializeWindow() {

    this->videoModes = sf::VideoMode::getFullscreenModes();

    /* Load the config file */
    std::ifstream ifs("game.ini");

    /* Set default values that will be changed via the config file */
    std::string title = "SFML Window";
    sf::VideoMode windowsBounds = sf::VideoMode::getDesktopMode();
    unsigned int frameRateLimit = 60;
    unsigned aa_level = 0;

    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> windowsBounds.width >> windowsBounds.height;     // Read the width Height
        ifs >> this->isFullscreen;
        ifs >> frameRateLimit;
        ifs >> this->isVerticalSync;
        ifs >> aa_level;

        ifs.close();
    }

    this->windowContextSettings.antialiasingLevel = aa_level;

    if (this->isFullscreen) {
        this->window = new sf::RenderWindow(windowsBounds, title, sf::Style::Fullscreen, this->windowContextSettings);
    } else {
        this->window = new sf::RenderWindow(windowsBounds, title, sf::Style::Titlebar | sf::Style::Close,
                                            this->windowContextSettings);
    }

    this->window->setFramerateLimit(frameRateLimit);
    this->window->setVerticalSyncEnabled(isVerticalSync);
}

void Game::InitializeStates() {
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

void Game::InitializeKeys() {

    // Load keyboard configuration

    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
    this->supportedKeys["A"] = sf::Keyboard::Key::A;
    this->supportedKeys["D"] = sf::Keyboard::Key::D;
    this->supportedKeys["W"] = sf::Keyboard::Key::W;
    this->supportedKeys["S"] = sf::Keyboard::Key::S;
    this->supportedKeys["X"] = sf::Keyboard::Key::X;
    this->supportedKeys["UpArrow"] = sf::Keyboard::Key::Up;
    this->supportedKeys["DownArrow"] = sf::Keyboard::Key::Down;
    this->supportedKeys["Select"] = sf::Keyboard::Key::Enter;

}

//endregion


//region Constructors / Destructors
Game::Game() {
    this->InitializeWindow();
    this->InitializeKeys();
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
        if (this->states.top()->getEnd()) {
            // state wants to quit
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    } else {
        // no more state, run final hooks (if any) and then terminate the app
        this->endApplication();

        // Terminate the application
        this->window->close();
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

void Game::endApplication() {
    std::cout << "Program termination hooks...\n\n";
}






