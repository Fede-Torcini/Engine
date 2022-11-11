#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
class Entity
{
public:
	Entity();
	virtual ~Entity();

	void createSprite();

	virtual void draw(sf::RenderTarget* target);
	virtual void update(float const& deltaTime);
	virtual void addComponent(Component* component);

protected:
	Transform m_transform;
	std::map<std::string ,std::unique_ptr<Component>> m_components;

};

}
