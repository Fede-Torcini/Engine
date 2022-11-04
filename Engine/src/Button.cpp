#include "Button.h"
#include <iostream>

namespace engine
{
	Button::Button(sf::Vector2f position)
		:m_state(sf::Color::Cyan, sf::Color::Blue, sf::Color::Black)
	{
		m_shape.setSize({100, 30});
		m_shape.setPosition(position);

		m_font.loadFromFile("src/resources/sansation.ttf");

		m_text.setFont(m_font);
		m_text.setString("Click Me");
		m_text.setFillColor(sf::Color::White);
		m_text.setCharacterSize(15);
		m_text.setPosition(
			(m_shape.getPosition().x + m_shape.getSize().x) / 2.0f - m_text.getGlobalBounds().width / 2.0f
			, (m_shape.getPosition().y + m_shape.getSize().y) / 2.0f - m_text.getGlobalBounds().height / 2.0f
		);
	}

	Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text = "Click Me", 
		sf::Color idleColor = sf::Color::Cyan, sf::Color hoverColor = sf::Color::Blue, sf::Color pressedColor = sf::Color::Black)
		: m_shape(size), m_state(idleColor, sf::Color::Blue, sf::Color::Black)
	{
		m_shape.setPosition(position);

		m_font.loadFromFile("src/resources/sansation.ttf");

		m_text.setFont(m_font);
		m_text.setString(text);
		m_text.setFillColor(sf::Color::White);
		m_text.setCharacterSize(24);
		m_text.setPosition(
			  (m_shape.getPosition().x + m_shape.getSize().x) / 2.0f - m_text.getGlobalBounds().width / 2.0f
			, (m_shape.getPosition().y + m_shape.getSize().y) / 2.0f - m_text.getGlobalBounds().height / 2.0f
		);
	}

	Button::~Button()
	{

	}

	void Button::update(sf::Vector2f const mousePos)
	{
		m_shape.setFillColor(m_state.getColor());

		if (m_shape.getGlobalBounds().contains(mousePos) )
		{	
			m_state.hover();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!m_state.isPressed())
				{
					std::cout << "button pressed\n";
				}
				m_state.press();
			}
		}
	}
	void Button::render(sf::RenderTarget* target) 
	{
		target->draw(m_shape);
		target->draw(m_text);
	}
}