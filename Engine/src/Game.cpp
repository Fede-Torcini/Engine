#include "Game.h"
#include "Constants.h"

#include "GameState.h"
#include "MainMenuState.h"

namespace engine
{
	Game::Game()
		:m_window (std::make_unique<sf::RenderWindow> (sf::VideoMode(constants::WINDOW_SIZE_X, constants::WINDOW_SIZE_Y), constants::TITLE))
	{
		this->initWindow();
		this->initStates();
	}

	Game::~Game()
	{
		while (!m_states.empty())
		{
			m_states.pop();
		}
	}

	void Game::updateTime()
	{
		m_deltaTime = m_clock.restart().asMilliseconds();
	}

	void Game::updateEvents()
	{
		while (m_window->pollEvent(m_event))
		{
			if (this->m_event.type == sf::Event::Closed)
			{
				m_window->close();
			}
		}
	}
	void Game::update()
	{
		this->updateEvents();

		if (!m_states.empty())
		{
			m_states.top()->update(m_deltaTime);

			if (m_states.top()->getQuit())
			{
				m_states.top()->endState();
				m_states.pop();
			}
		}

		else
		{
			m_window->close();
		}
	}
	void Game::render()
	{
		m_window->clear();

		if (!m_states.empty())
		{
			m_states.top()->render();
		}

		m_window->display();
	}
	void Game::run()
	{
		while (m_window->isOpen())
		{
			this->updateTime();
			this->update();
			this->render();
		}
	}
	void Game::initWindow()
	{
	}
	void Game::initStates()
	{
		m_states.push(std::make_unique<pacman::MainMenuState> (m_window.get()));
	}
}