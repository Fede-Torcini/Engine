#pragma once

#include "SFML/Graphics.hpp"

namespace engine
{
class Entity
{
public:

	Entity();
	virtual ~Entity();

	virtual void move(float const& deltaTime, float const x, float const y) = 0;
	virtual void update(float const& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

protected:
	sf::RectangleShape m_render;
	float m_speed;
};

}
