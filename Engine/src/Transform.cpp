#include "Transform.h"

namespace engine
{
    void Transform::update(float deltaTime)
    {

    }
    sf::Vector2f Transform::getPosition() const
    {
        return m_position;
    }
    void Transform::setPosition(sf::Vector2f newPosition)
    {
        m_position = newPosition;
    }
}