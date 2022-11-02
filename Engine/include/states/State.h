#pragma once

#include <vector>
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>

namespace engine
{
class State
{

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	bool const& getQuit();

	virtual void checkForQuit() = 0;

	virtual void endState() = 0;

	virtual void updateKeybinds(float const& deltaTime) = 0;
	virtual void update(float const& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
	bool m_quit;

private:
	sf::RenderWindow* m_window;
	std::vector<sf::Texture> m_textures;
};
}

