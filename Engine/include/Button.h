#pragma once

#include "SFML/Graphics.hpp"

namespace engine
{
enum class ButtonState
{
	IDLE = 0,
	HOVERED,
	PRESSED
};
class Button
{
public: 
	Button(sf::Vector2f position);
	Button(sf::Vector2f position, sf::Vector2f size, std::string text, sf::Color idleColor);
	~Button();

	void update(sf::Vector2f const mousePos);
	void render(sf::RenderTarget* target);
private:

	void setState(ButtonState newState);

	ButtonState m_state;

	sf::RectangleShape m_shape;
	sf::Text m_text;
	sf::Font m_font;

	sf::Color m_color;
	sf::Color m_pressedColor;
	sf::Color m_hoveredColor;

};
}

