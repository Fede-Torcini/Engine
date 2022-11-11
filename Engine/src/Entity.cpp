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
		for (auto const& component : m_components)
		{
			if (component.second != nullptr)
			{
				component.second->update(deltaTime);
			}
		}
	}

	void Entity::draw(sf::RenderTarget* target)
	{
		for (auto const& component : m_components)
		{
			if  (component.second != nullptr)
			{
				component.second->draw(target);
			}
		}
	}

	void Entity::addComponent(Component* component)
	{
		if (component != nullptr)
		{
			m_components.insert({ component->getName(), std::unique_ptr<Component>(component) });
		}
	}

}