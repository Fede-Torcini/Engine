#pragma once

#include "SFML/Graphics.hpp"

namespace engine
{
class Entity
{
public:

	Entity();
	Entity(sf::Texture* texture);
	virtual ~Entity();

	void createSprite();

	virtual void move(float const& deltaTime, float const x, float const y) = 0;
	virtual void update(float const& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

protected:
	std::unique_ptr <sf::Texture> m_texture;
	std::unique_ptr <sf::Sprite> m_sprite;
	float m_speed;
};

}
