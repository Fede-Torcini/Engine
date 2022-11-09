#include "Entity.h"

namespace engine
{
	//Posible crash, debug later
	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}

	void Entity::update(float const& deltaTime) 
	{
		for (unsigned int i = 0; i < m_components.size(); i++)
		{
			if (m_components[i] != nullptr)
			{
				m_components[i]->update(deltaTime);
			}
		}
	}

	void Entity::draw(sf::RenderTarget* target)
	{
		for (unsigned int i = 0; i < m_components.size(); i++)
		{
			if (m_components[i] != nullptr)
			{
				m_components[i]->draw(target);
			}
		}
	}

	void Entity::addComponent(Component* component)
	{
		if (component != nullptr)
		{
			m_components.push_back(std::unique_ptr<Component>(component));
		}
	}

}