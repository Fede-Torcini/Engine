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

		bool const& getQuit();

		virtual void checkForQuit();

		virtual void endState();

		virtual void updateKeybinds(float const& deltaTime);
		virtual void update(float const& deltaTime);
		virtual void render(sf::RenderTarget* target = nullptr);

	private:
		engine::Button button;
	};
}



