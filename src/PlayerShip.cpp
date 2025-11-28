//
// Created by user on 28/11/2025.
//

#include "PlayerShip.h"

#include <algorithm>

PlayerShip::PlayerShip()
{
    // Classic Asteroids-style ship outline
    body.setPointCount(4);
    body.setPoint(0, sf::Vector2f( 0, -20)); // tip
    body.setPoint(1, sf::Vector2f(-12,  12)); // left wing
    body.setPoint(2, sf::Vector2f(  0,  4)); // back center (indented)
    body.setPoint(3, sf::Vector2f( 12,  12)); // right wing

    body.setFillColor(sf::Color::Transparent);
    body.setOutlineColor(sf::Color::White);
    body.setOutlineThickness(2);
}

void PlayerShip::Update(float deltaTime)
{
    // Rotation
    if (rotatingLeft && !rotatingRight)
    {
        rotation -= rotationSpeed * deltaTime;
    }
    else if (rotatingRight && !rotatingLeft)
    {
        rotation += rotationSpeed * deltaTime;
    }

    body.setPosition(position);
    body.setRotation(sf::degrees(rotation));
}

void PlayerShip::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}

void PlayerShip::RotateLeft(bool active)
{
    rotatingLeft = active;
}

void PlayerShip::RotateRight(bool active)
{
    rotatingRight = active;
}


