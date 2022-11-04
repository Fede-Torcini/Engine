#pragma once

#include "State.h"

namespace pacman
{
class GameState : public engine::State
{
public: 
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	bool const& getQuit();

	virtual void checkForQuit();

	virtual void endState();

	virtual void updateKeybinds(float const& deltaTime);
	virtual void update(float const& deltaTime);
	virtual void render(sf::RenderTarget* target = nullptr);
};
}
