#include "MovementComponent.h"
#include <iostream>

namespace engine
{
    MovementComponent::MovementComponent(Transform& transform, float speed) : Component(transform)
    {
        m_speed = speed;
        m_mass = 80;
        m_aceleration = { 0,0 };
        m_deceleration = { .1, .1 };
    }

    MovementComponent::~MovementComponent()
    {
    }

    sf::Vector2f checkInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            return sf::Vector2f(0, -100);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            return sf::Vector2f(0, 100);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            return sf::Vector2f(-100, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            return sf::Vector2f(100, 0);
        }
        return sf::Vector2f(0, 0);
    }

    void MovementComponent::updateVelocity(sf::Vector2f const& inputForce)
    {  
        float c = 1000;
        if (m_velocity.x < 0)
        {
            m_aceleration.x = (inputForce.x  + m_velocity.x * m_velocity.x * c / m_mass) / m_mass;
        }
        else if (m_velocity.x > 0)
        {
            m_aceleration.x = (inputForce.x - m_velocity.x * m_velocity.x * c / m_mass) / m_mass;
        }
        else
        {
            m_aceleration.x = inputForce.x / m_mass;
        }
        if (m_velocity.y < 0)
        {
            m_aceleration.y = (inputForce.y + m_velocity.y * m_velocity.y * c / m_mass) / m_mass;
        }
        else if (m_velocity.y > 0)
        {
            m_aceleration.y = (inputForce.y - m_velocity.y * m_velocity.y * c / m_mass) / m_mass;
        }
        else
        {
            m_aceleration.y = inputForce.y / m_mass;
        }

        m_velocity += m_aceleration / 2.0f;
        if (m_velocity.x < .2f && m_velocity.x > -.2f)
        {
            m_velocity.x = 0;
        }
        if (m_velocity.y < .2f && m_velocity.y > -.2f)
        {
            m_velocity.y = 0;
        }
    }

    void MovementComponent::update(float deltaTime)
    {
        this->updateVelocity(checkInput());
        this->move();
    }
    void MovementComponent::move()
    {
        m_transform.setPosition(m_transform.getPosition() + (m_velocity * m_speed));
    }
}
