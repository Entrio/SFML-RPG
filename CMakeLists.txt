cmake_minimum_required(VERSION 3.17)
project(SFML_RPG)

set(CMAKE_CXX_STANDARD 11)

add_executable(SFML_RPG main.cpp Game.cpp Game.h States/State.cpp States/State.h States/GameState.cpp States/GameState.h Entity.cpp Entity.h States/MainMenuState.cpp States/MainMenuState.h UI/Button.cpp UI/Button.h Player.cpp Player.h Components/MovementComponent.cpp Components/MovementComponent.h Components/AnimationComponent.cpp Components/AnimationComponent.h)
target_link_libraries(SFML_RPG PRIVATE -lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-system)