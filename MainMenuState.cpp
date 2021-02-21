//
// Created by alex on 7/2/21.
//

#include "MainMenuState.h"
#include "GameState.h"
#include "EditorState.h"

MainMenuState::MainMenuState(
        sf::RenderWindow *window,
        std::map<std::string, int> *supportedKeys,
        std::stack<State *> *states
) : State(
        window,
        supportedKeys,
        states
) {
    this->InitializeVariables();
    this->setupBackground();
    this->stateKeyBinds();
    this->LoadAssets();
    this->SetupButtons();
}

MainMenuState::~MainMenuState() {
    for (auto &b : buttons) {
        delete b.second;
    }
}

void MainMenuState::updateInput(const float &deltaTime) {
    this->checkForEnd(); // Inherited from State

}

void MainMenuState::update(const float &deltaTime) {
    this->updateMousePosition();
    this->updateInput(deltaTime);

    for (auto const &b : buttons) {
        b.second->update(this->mousePosView);
    }

    if (this->buttons["EXIT"]->IsPressed()) {
        this->endState();
    }

    if (this->buttons["EDITOR"]->IsPressed()) {
        this->states->push(new EditorState(this->window, this->supportedKeys, this->states));
    }

    if (this->buttons["PLAY"]->IsPressed()) {
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }
}

void MainMenuState::render(sf::RenderTarget *target) {
    if (!target) {
        target = this->window;
    }
    target->draw(this->background);

    for (auto const &b : buttons) {
        b.second->render(*target);
    }

    //this->testButton->render(target);
    State::render(target);
}

/**
 * Initialize GameState key bindings. These are only available for this state
 */
void MainMenuState::stateKeyBinds() {
    // If we remove terminate from keybinds, it shouldnt get triggered in parent state, hence not exiting the app
    //this->keyBinds["Terminate"] = this->supportedKeys->at("Escape");

    this->keyBinds["DEBUG"] = this->supportedKeys->at("F1");

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

void MainMenuState::SetupButtons() {
    this->buttons["PLAY"] = new Button(
            10, 10, 250, 30, "Play Game", 15, &this->font
    );

    this->buttons["EDITOR"] = new Button(
            1100, 615, 150, 30, "Editor", 15, &this->font, sf::Color::White, sf::Color::White, sf::Color::White,
            sf::Color(0, 0, 240, 120)
    );

    this->buttons["EXIT"] = new Button(
            1100, 660, 150, 30, "Exit", 15, &this->font, sf::Color::White, sf::Color::White, sf::Color::White,
            sf::Color(0, 0, 240, 120)
    );
}
void MainMenuState::InitializeVariables() {

}
void MainMenuState::setupBackground() {
    this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));

    if (!this->backgroundTexture.loadFromFile("assets/images/bg.jpg")) {
        // Failed to load the background image
        std::cerr << "ERROR::NON_CRITICAL::MAINMENUSTATE::BACKGROUND_TEXTURE_NOT_FOUND" << std::endl;
        this->background.setFillColor(sf::Color(100, 149, 237));        // Good ol cornflower blue
    } else {
        // If its loaded, set the background to loaded texture
        this->background.setTexture(&this->backgroundTexture);
    }
}

/**
 * This function is called just before the state is terminated
 */
void MainMenuState::onBeforeEndState() {

}
void MainMenuState::InitializeTextures() {
//TODO:
}
