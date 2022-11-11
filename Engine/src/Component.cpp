#include "Component.h"

namespace engine
{
    Component::Component(Transform& transform, std::string const& name)
     : m_transform(transform), m_name(name)
    {
    }
    void Component::draw(sf::RenderTarget* target)
    {
    }

    std::string const& Component::getName() const
    {
        return m_name;
    }

}