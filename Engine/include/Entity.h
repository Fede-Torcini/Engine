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

	virtual void move(float const& deltaTime, float const x, float const y) = 0;
	virtual void draw(sf::RenderTarget* target);
	virtual void update(float const& deltaTime);
	virtual void addComponent(Component* component);

protected:
	Transform m_transform;
	std::vector<std::unique_ptr<Component>> m_components;

};

}
