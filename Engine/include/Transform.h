#pragma once

#include "SFML/graphics.hpp"

namespace engine
{
class Transform
{
public:
    
    void update(float deltaTime);

    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f newPosition);

private:
    
    sf::Vector2f m_position;
    
};
}