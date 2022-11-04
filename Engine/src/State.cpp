#include "State.h"

namespace engine
{
	State::State(sf::RenderWindow* window)
		:m_window(window), m_quit(false)
	{
	}
	State::~State()
	{
	}
	void State::checkForQuit()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_quit = true;
		}
	}
	void State::updateMousePosition()
	{
		mousePositionWorld = sf::Mouse::getPosition();
		mousePositionWindow = sf::Mouse::getPosition(*m_window);
		mousePositionView = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));

	}
	bool const& State::getQuit()
	{
		return m_quit;
	}
}