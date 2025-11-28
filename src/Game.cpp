#include "Game.h"

Game::Game()
{
    window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Asteroids");
    window.setFramerateLimit(144);

    // Create Player Ship
    playerShip = std::make_unique<PlayerShip>();

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

    playerShip->RotateLeft( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left));
    playerShip->RotateRight( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right));
}

void Game::Update(float deltaTime)
{
    if (playerShip)
    {
        playerShip->Update(deltaTime);
    }
}

void Game::Render()
{
    window.clear();
    if (playerShip)
    {
        playerShip->Draw(window);
    }

    window.display();
}
