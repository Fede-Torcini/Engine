#pragma once

#include "State.h"
#include "Player.h"

namespace pacman
{
class GameState : public engine::State
{
public: 
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	virtual void endState();

	virtual void updateKeybinds(float const& deltaTime);
	virtual void update(float const& deltaTime);
	virtual void updateEvents();
	virtual void render(sf::RenderTarget* target = nullptr);
private:
	Player m_player;
};
}
