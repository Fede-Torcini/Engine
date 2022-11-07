#pragma once
#include "State.h"
#include "Button.h"

namespace pacman
{
	class MainMenuState : public engine::State
	{
	public:
		MainMenuState(sf::RenderWindow* window);
		virtual ~MainMenuState();

		virtual void endState();

		void initButtons();
		virtual void updateKeybinds(float const& deltaTime);
		virtual void updateEvents();
		virtual void update(float const& deltaTime);
		virtual void render(sf::RenderTarget* target = nullptr);
		std::unique_ptr<engine::State> getNewState();

	private:
		engine::Button m_startGameButton;
		engine::Button m_closeButton;
		bool m_startGame;
	};
}



