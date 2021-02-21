//
// Created by alex on 7/2/21.
//

#include "EditorState.h"
#include "GameState.h"

EditorState::EditorState(
        sf::RenderWindow *window,
        std::map<std::string, int> *supportedKeys,
        std::stack<State *> *states
) : State(
        window,
        supportedKeys,
        states
) {
    this->InitializeVariables();
    this->stateKeyBinds();
    this->LoadAssets();
    this->SetupButtons();
}

EditorState::~EditorState() {
    for (auto &b : buttons) {
        delete b.second;
    }
}

void EditorState::updateInput(const float &deltaTime) {
    this->checkForEnd(); // Inherited from State

}

void EditorState::update(const float &deltaTime) {
    this->updateMousePosition();
    this->updateInput(deltaTime);

    for (auto const &b : buttons) {
        b.second->update(this->mousePosView);
    }
}

void EditorState::render(sf::RenderTarget *target) {
    if (!target) {
        target = this->window;
    }

    for (auto const &b : buttons) {
        b.second->render(*target);
    }

    State::render(target);
}

/**
 * Initialize GameState key bindings. These are only available for this state
 */
void EditorState::stateKeyBinds() {
    this->keyBinds["DEBUG"] = this->supportedKeys->at("F1");
    this->keyBinds["Terminate"] = this->supportedKeys->at("Escape");

}

void EditorState::InitializeFonts() {
    if (!this->font.loadFromFile("assets/fonts/slkscr.ttf")) {
        throw "Failed to load main menu fonts";
    }
}

void EditorState::SetupButtons() {

    this->buttons["EXIT"] = new Button(
            1100, 660, 150, 30, "Exit", 15, &this->font, sf::Color::White, sf::Color::White, sf::Color::White,
            sf::Color(0, 0, 240, 120)
    );
}
void EditorState::InitializeVariables() {

}
void EditorState::setupBackground() {
    this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));

    if (!this->backgroundTexture.loadFromFile("assets/images/bg.jpg")) {
        // Failed to load the background image
        std::cerr << "ERROR::NON_CRITICAL::EditorState::BACKGROUND_TEXTURE_NOT_FOUND" << std::endl;
        this->background.setFillColor(sf::Color(100, 149, 237));        // Good ol cornflower blue
    } else {
        // If its loaded, set the background to loaded texture
        this->background.setTexture(&this->backgroundTexture);
    }
}

/**
 * This function is called just before the state is terminated
 */
void EditorState::onBeforeEndState() {

}
void EditorState::InitializeTextures() {
//TODO:
}
