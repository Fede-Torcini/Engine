#include "Game.h"
#include "Constants.h"

#include "GameState.h"
#include "MainMenuState.h"

namespace engine
{
	//Constructors
	Game::Game()
		:m_window (nullptr),
		m_deltaTime(0.f),
		m_vidModes(sf::VideoMode::getFullscreenModes())
	{
		this->initWindow();
		this->initStates();
	}

	//Destructors
	Game::~Game()
	{
		while (!m_states.empty())
		{
			m_states.pop();
		}
	}


	//Updates
	void Game::updateTime()
	{
		m_deltaTime = static_cast<float>(m_clock.restart().asMilliseconds());
	}

	void Game::update()
	{
		if (!m_states.empty())
		{
			//Update top state
			m_states.top()->update(m_deltaTime);
			m_states.top()->updateEvents();

			//Check if state wants to push a new state
			std::unique_ptr<State> newState (m_states.top()->getNewState());
			if (newState != nullptr)
			{
				m_states.push(std::move(newState));
			}

			//Check if state wants to quit
			if (m_states.top()->getQuit())
			{
				m_states.top()->endState();
				m_states.pop();
			}
		}

		//if there are no states to render close the window
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
		while (m_window != nullptr && m_window->isOpen())
		{
			this->updateTime();
			this->update();
			this->render();
		}
	}

	//Initializers
	void Game::initWindow()
	{
		bool fullscreen = constants::FULLSCREEN;
		unsigned frameLimit = constants::FRAME_LIMIT;
		bool verticalSyncEnabled = constants::VSYNC;
		unsigned antialiasingLvl = constants::ANTIALIASING;

		sf::ContextSettings windowSettings;
		windowSettings.antialiasingLevel = antialiasingLvl;

		if (fullscreen)
		{
			m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), constants::TITLE, sf::Style::Fullscreen, windowSettings);
		}
		else
		{
			m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), constants::TITLE, sf::Style::Titlebar | sf::Style::Close, windowSettings);
		}
		
		if(m_window != nullptr)
		{
			m_window->setFramerateLimit(frameLimit);
			m_window->setVerticalSyncEnabled(verticalSyncEnabled);
		}
	}
	void Game::initStates()
	{
		m_states.push(std::make_unique<pacman::MainMenuState> (m_window.get()));
	}
}