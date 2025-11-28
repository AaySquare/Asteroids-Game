#include "Game.h"

Game::Game()
{
    window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Asteroids");
    window.setFramerateLimit(144);

    // Create Player Ship
    // Create initial asteroid
}

void Game::Run()
{
    while (window.isOpen())
    {
        const float deltaTime = clock.restart().asSeconds();

        ProcessInput();
        Update(deltaTime);
        Render();
    }
}

void Game::ProcessInput()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }
}

void Game::Update(float deltaTime)
{

}

void Game::Render()
{
    window.clear();
    window.display();
}
