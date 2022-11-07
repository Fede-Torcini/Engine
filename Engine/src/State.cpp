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
	std::unique_ptr<State> State::getNewState()
	{
		return nullptr;
	}
	void State::updateMousePosition()
	{
		mousePositionWorld = sf::Mouse::getPosition();
		mousePositionWindow = sf::Mouse::getPosition(*m_window);
		mousePositionView = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));

	}
	bool State::getQuit()
	{
		return m_quit;
	}
}