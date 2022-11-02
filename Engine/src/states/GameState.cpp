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
	bool const& GameState::getQuit()
	{
		return false;
	}
	void GameState::checkForQuit()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_quit = true;
		}
	}
	void GameState::endState()
	{
		std::cout << "GameState Ending\n";
	}
	void GameState::updateKeybinds(float const& deltaTime)
	{
		this->checkForQuit();
	}
	void GameState::update(float const& deltaTime)
	{
		this->updateKeybinds(deltaTime);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			std::cout << "HI\n";
		}
	}
	void GameState::render(sf::RenderTarget* target)
	{
	}
}