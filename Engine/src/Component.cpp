#include "Component.h"

namespace engine
{
    Component::Component(Transform const& transform)
     : m_transform(transform)
    {
    }
    void Component::draw(sf::RenderTarget* target)
    {
    }

}