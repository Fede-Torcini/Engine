#pragma once

#include <SFML/Graphics.hpp>
#include "ButtonState.h"

namespace engine
{
class Button
{
public: 
	Button(sf::Vector2f position);
	Button(sf::Vector2f position, sf::Vector2f size, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor);
	~Button();

	void update(sf::Vector2f const mousePos);
	void render(sf::RenderTarget* target);
private:

	ButtonState m_state;

	sf::RectangleShape m_shape;
	sf::Text m_text;
	sf::Font m_font;

};
}

