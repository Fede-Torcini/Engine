#include "GameState.h"
#include "Constants.h"
#include <iostream>

namespace pacman
{
	GameState::GameState(sf::RenderWindow* window) 
		: engine::State(window), m_player(engine::constants::PLAYER_TEXTURE_DIR, m_window)
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

		m_player.update(deltaTime);
	}
	void GameState::render(sf::RenderTarget* target)
	{
		target != nullptr ? m_player.draw(target) : m_player.draw(m_window);
	}
}