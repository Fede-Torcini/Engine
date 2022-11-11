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
    virtual std::string const& getName() const;

protected:
    std::string m_name;
    Transform& m_transform;
    Component(Transform& transform, std::string const& name);
};
}