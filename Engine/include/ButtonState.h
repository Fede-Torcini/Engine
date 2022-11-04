#pragma once

#include "SFML/Graphics.hpp"

namespace engine
{
class ButtonState
{
public:
    ButtonState(sf::Color const& idle, sf::Color const& hovered, sf::Color const& pressed);
    sf::Color getColor();
    void hover();
    void press();
    bool isPressed();
private:
    float frames;

    bool m_isPressed;
    bool m_isHovered;

    sf::Color m_idleColor;
    sf::Color m_hoveredColor;
    sf::Color m_pressedColor;
};

}
