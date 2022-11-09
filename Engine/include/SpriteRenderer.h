#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
class SpriteRenderer : public Component
{
public:
   
    SpriteRenderer(Transform& transform, std::string const& textDir, sf::RenderTarget* window);
    virtual ~SpriteRenderer();

    virtual void draw(sf::RenderTarget* target);
    virtual void update(float deltaTime);


private:
    sf::RenderTarget* m_target;
    std::unique_ptr<sf::Sprite> m_sprite;
    std::unique_ptr<sf::Texture> m_texture;
};
}