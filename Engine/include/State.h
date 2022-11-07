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
	State(State const&) = default;

	bool getQuit();

	virtual void endState() = 0;

	virtual std::unique_ptr<State> getNewState();
	virtual void updateMousePosition();
	virtual void updateKeybinds(float const& deltaTime) = 0;
	virtual void update(float const& deltaTime) = 0;
	virtual void updateEvents() = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
	bool m_quit;

	sf::Vector2i mousePositionWorld;
	sf::Vector2i mousePositionWindow;
	sf::Vector2f mousePositionView;

	sf::RenderWindow* m_window;
private:

	std::vector<sf::Texture> m_textures;
};
}

