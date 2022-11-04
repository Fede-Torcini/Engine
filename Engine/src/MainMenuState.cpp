#include "MainMenuState.h"
#include <iostream>

namespace pacman
{
	MainMenuState::MainMenuState(sf::RenderWindow* window)
		: engine::State(window), button(engine::Button({ 0,0 }))
	{

	}

	MainMenuState::~MainMenuState()
	{
	}
	bool const& MainMenuState::getQuit()
	{
		return false;
	}
	void MainMenuState::checkForQuit()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_quit = true;
		}
	}
	void MainMenuState::endState()
	{
		std::cout << "MainMenuState Ending\n";
	}
	void MainMenuState::updateKeybinds(float const& deltaTime)
	{
		this->checkForQuit();
	}
	void MainMenuState::update(float const& deltaTime)
	{
		this->updateMousePosition();
		this->updateKeybinds(deltaTime);
		button.update(sf::Vector2f(mousePositionWindow.x, mousePositionWindow.y));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			std::cout << "HI\n";
		}
	}
	void MainMenuState::render(sf::RenderTarget* target)
	{
		if (target == nullptr)
		{
			button.render(m_window);
		}
	}
}