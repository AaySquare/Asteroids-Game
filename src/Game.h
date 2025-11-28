#pragma once

#include <memory>

#include "SFML/Graphics/RenderWindow.hpp"
#include "PlayerShip.h"

class Game
{
public:
    Game();
    void Run();

private:
    void ProcessInput();
    void Update(float deltaTime);
    void Render();

private:
    sf::RenderWindow window;
    sf::Clock clock;

    std::unique_ptr<PlayerShip> playerShip;
};
