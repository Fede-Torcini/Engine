#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
class MovementComponent : public Component
{
public:
    MovementComponent(Transform const& transform, float speed = 0);
    virtual ~MovementComponent();

    void update(float deltaTime);

    void move(float const dir_x, float const dir_y);


private:
    
    float m_speed;
    sf::Vector2f m_velocity;
    sf::Vector2f m_position;
    sf::Vector2f m_aceleration;

};
}

