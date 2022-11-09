#include "Component.h"

namespace engine
{
    Component::Component(Transform& transform)
     : m_transform(transform)
    {
    }
    void Component::draw(sf::RenderTarget* target)
    {
    }

}