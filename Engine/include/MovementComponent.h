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

    void updateVelocity(sf::Vector2f const& inputForce);
    void move();
    
    float m_speed;
    float m_mass;
    sf::Vector2f m_aceleration;
    sf::Vector2f m_velocity;
};
}

