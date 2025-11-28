#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

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
};
