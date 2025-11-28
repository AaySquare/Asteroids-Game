#pragma once

#include <SFML/Graphics.hpp>

class PlayerShip
{
public:
    PlayerShip();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

    void RotateLeft(bool active);
    void RotateRight(bool active);

private:
    sf::ConvexShape body;
    sf::Vector2f position {960.f, 540.f};
    float rotation = 0.f;
    float rotationSpeed = 250.f;

    // Current input state (set from outside every frame)
    bool rotatingLeft  = false;
    bool rotatingRight = false;
};
