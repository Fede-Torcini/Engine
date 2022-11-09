#include "SpriteRenderer.h"

namespace engine
{
    SpriteRenderer::SpriteRenderer(Transform const& transform, std::string const& textDir, sf::RenderTarget* window = nullptr) : Component (transform)
    {
        m_target = window;

        m_texture = std::make_unique<sf::Texture>();
        m_texture->loadFromFile(textDir);

        m_sprite = std::make_unique<sf::Sprite>();
        m_sprite->setTexture(*m_texture);
    }

    SpriteRenderer::~SpriteRenderer()
    {

    }

    void SpriteRenderer::update(float deltaTime)
    {
        if (m_target != nullptr)
        {
            m_target->draw(*m_sprite);
        }
    }

    void SpriteRenderer::draw(sf::RenderTarget* target)
    {
        m_target->draw(*m_sprite);
    }
}