#include "Player.h"
#include "MovementComponent.h"
#include "SpriteRenderer.h"

namespace pacman
{
    Player::Player(std::string const& textDir, sf::RenderTarget* target = nullptr) : Entity ()
    {
        this->addComponent(new engine::MovementComponent(m_transform));
        this->addComponent(new engine::SpriteRenderer(m_transform, textDir, target));
    }

    Player::~Player()
    {
    }

    void Player::move(float const& deltaTime, float const x, float const y)
    {
    }

}