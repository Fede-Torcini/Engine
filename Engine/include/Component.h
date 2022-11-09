#pragma once 

#include "SFML/Graphics.hpp"
#include "Transform.h"

namespace engine
{
class Component
{
public:
    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderTarget* target);

protected:
    Transform const& m_transform;
    Component(Transform const& transform);
};
}