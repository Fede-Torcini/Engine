#include "MainMenuState.h"
#include "GameState.h"
#include <iostream>

namespace pacman
{
	MainMenuState::MainMenuState(sf::RenderWindow* window)
		: engine::State(window), 
		m_startGameButton(engine::Button({ 0,0 })),
		m_closeButton(engine::Button({ 500,0 })),
		m_startGame(false)
	{
		this->initButtons();
	}

	MainMenuState::~MainMenuState()
	{
	}
	void MainMenuState::endState()
	{
		std::cout << "MainMenuState Ending\n";
	}
	void MainMenuState::initButtons()
	{
	}
	void MainMenuState::updateKeybinds(float const& deltaTime)
	{
	}
	void MainMenuState::updateEvents()
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
	void MainMenuState::update(float const& deltaTime)
	{
		this->updateMousePosition();
		this->updateKeybinds(deltaTime);

		//Update StartGame Button
		m_startGameButton.update(sf::Vector2f(static_cast<float>(mousePositionWindow.x), static_cast<float>(mousePositionWindow.y)));
		m_startGame = m_startGameButton.getButtonPressed();

		//Update Close Button
		m_closeButton.update(sf::Vector2f(static_cast<float>(mousePositionWindow.x), static_cast<float>(mousePositionWindow.y)));
		m_quit = m_closeButton.getButtonPressed();
	}
	void MainMenuState::render(sf::RenderTarget* target)
	{
		if (target == nullptr)
		{
			m_startGameButton.render(m_window);
			m_closeButton.render(m_window);
		}
	}

	std::unique_ptr<engine::State> MainMenuState::getNewState()
	{
		if (m_startGame)
		{
			m_startGame = false;
			return std::make_unique <GameState>(m_window);
		}
		return nullptr;
	}
}