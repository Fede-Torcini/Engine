#include "SpriteRenderer.h"

namespace engine
{
    SpriteRenderer::SpriteRenderer(Transform& transform, std::string const& textDir, sf::RenderTarget* window = nullptr) : Component (transform)
    {
        m_target = window;

        m_texture = std::make_unique<sf::Texture>();
        m_texture->loadFromFile(textDir);

        m_sprite = std::make_unique<sf::Sprite>();
        m_sprite->setTexture(*m_texture);
        m_sprite->setScale(sf::Vector2f(10, 10));
    }

    SpriteRenderer::~SpriteRenderer()
    {

    }

    void SpriteRenderer::update(float deltaTime)
    {
        m_sprite->setPosition(m_transform.getPosition());
    }

    void SpriteRenderer::draw(sf::RenderTarget* target)
    {
          target != nullptr ? target->draw(*m_sprite) : m_target->draw (*m_sprite);
            
    }
}