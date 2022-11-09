#include "MovementComponent.h"

namespace engine
{
    MovementComponent::MovementComponent(Transform& transform, float speed) : Component (transform)
    {
        m_speed = speed;
    }
    MovementComponent::~MovementComponent()
    {
    }
    void MovementComponent::checkInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_velocity = sf::Vector2f(0, -1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            m_velocity = sf::Vector2f(0, 1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_velocity = sf::Vector2f(-1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_velocity = sf::Vector2f(1, 0);
        }
    }
    void MovementComponent::update(float deltaTime)
    {
        this->checkInput();
        this->move();
    }
    void MovementComponent::move()
    {
        m_transform.setPosition(m_transform.getPosition() + (m_velocity * m_speed));
    }
}