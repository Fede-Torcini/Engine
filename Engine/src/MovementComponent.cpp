#include "MovementComponent.h"
#include "Constants.h"
#include <iostream>

namespace engine
{
    MovementComponent::MovementComponent(Transform& transform, float speed) 
        : Component(transform, constants::componentNames::MOVEMENT_COMPONENT)
    {
        m_speed = speed;
        m_mass = 80;
        m_aceleration = { 0,0 };
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

    void updateAccelerationAxis(float& acceleration, float velocity, float inputForce, float mass, float dragConstant)
    {
        if (velocity < 0)
        {
            acceleration = (inputForce + velocity * velocity * dragConstant / mass) / mass;
        }
        else if (velocity > 0)
        {
            acceleration = (inputForce - velocity * velocity * dragConstant / mass) / mass;
        }
        else
        {
            acceleration = inputForce / mass;
        }
    }

    void MovementComponent::updateVelocity(sf::Vector2f const& inputForce)
    {  
        float c = 1000;
        updateAccelerationAxis(m_aceleration.x, m_velocity.x, inputForce.x, m_mass, c);
        updateAccelerationAxis(m_aceleration.y, m_velocity.y, inputForce.y, m_mass, c);
       
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
