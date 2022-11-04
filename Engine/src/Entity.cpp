#include "Entity.h"

namespace engine
{
	Entity::Entity()
	{
		m_render.setSize(sf::Vector2f(50.0f, 50.0f));
	}
	Entity::~Entity()
	{
	}
}