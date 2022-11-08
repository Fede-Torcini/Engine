#include "Entity.h"

namespace engine
{
	Entity::Entity()
		: m_speed(0), m_sprite(nullptr), m_texture(nullptr)
	{
	}
	//Posible crash, debug later
	Entity::Entity(sf::Texture* texture)
		: m_speed(0), m_sprite(nullptr), m_texture(texture)
	{
	}
	Entity::~Entity()
	{
	}
	void Entity::createSprite()
	{
		if (m_texture != nullptr)
		{
			m_sprite = std::make_unique<sf::Sprite>();
			m_sprite->setTexture(*m_texture);
		}
	}
}