#include "GameState.h"
#include <iostream>

namespace pacman
{
	GameState::GameState(sf::RenderWindow* window) 
		: engine::State(window)
	{
	}
	GameState::~GameState()
	{
	}

	void GameState::endState()
	{
		std::cout << "GameState Ending\n";
	}
	void GameState::updateKeybinds(float const& deltaTime)
	{
	}
	void GameState::updateEvents()
	{
		sf::Event myEvent;
		while (m_window->pollEvent(myEvent))
		{
			if (myEvent.type == sf::Event::Closed)
			{
				m_window->close();
			}
			if (myEvent.type == sf::Event::KeyReleased)
			{
				if (myEvent.key.code == sf::Keyboard::Escape)
				{
					m_quit = true;
				}
			}
		}
	}
	void GameState::update(float const& deltaTime)
	{
		this->updateMousePosition();
		this->updateKeybinds(deltaTime);
	}
	void GameState::render(sf::RenderTarget* target)
	{
	}
}