#include "ButtonState.h"
#include <iostream>

namespace engine
{
    ButtonState::ButtonState(sf::Color const& idle, sf::Color const& hovered, sf::Color const& pressed)
        : m_idleColor(idle), m_hoveredColor(hovered), m_pressedColor(pressed)
    {
        frames = 60;
        m_isPressed = false;
        m_isHovered = false;
    }
    sf::Color ButtonState::getColor()
    {
        if (frames <= 0)
        {
            m_isPressed = false;
            m_isHovered = false;
        }
        if (m_isPressed)
        {
            frames--;
            return m_pressedColor;
        }
        if (m_isHovered)
        {
            frames--;
            return m_hoveredColor;
        }
        else
        {
            return m_idleColor;
        }
    }
    void ButtonState::hover()
    {
        frames = 60;
        m_isHovered = true;
    }
    void ButtonState::press()
    {
        frames = 60;
        m_isPressed = true;
    }

    bool ButtonState::isPressed()
    {
        return m_isPressed;
    }
}