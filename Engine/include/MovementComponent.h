#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
class MovementComponent : public Component
{
public:
    MovementComponent(Transform& transform, float speed = 0);
    virtual ~MovementComponent();

    void update(float deltaTime);

private:

    void checkInput();
    void move();
    
    float m_speed;
    sf::Vector2f m_velocity;
    sf::Vector2f m_aceleration;

};
}

