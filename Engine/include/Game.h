#pragma once

#include <SFML/Graphics.hpp>

#include <stack>
#include <map>

#include "State.h"

namespace engine
{
class Game
{
public:
	Game();
	virtual ~Game();

	void update();
	void render();
	void run();

private:
	
	void initWindow();
	void initStates();

	void updateTime();

	std::stack<std::unique_ptr<State>> m_states;

	float m_deltaTime;
	sf::Clock m_clock;
	
	std::vector<sf::VideoMode> m_vidModes;
	std::unique_ptr<sf::RenderWindow> m_window;
	sf::Event m_event;
};
}

