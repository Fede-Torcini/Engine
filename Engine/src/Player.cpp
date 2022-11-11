#include "Player.h"
#include "MovementComponent.h"
#include "SpriteRenderer.h"
#include "AnimationController.h"

namespace pacman
{
    Player::Player(std::string const& textDir, sf::RenderTarget* target = nullptr) : Entity()
    {
        this->addComponent(new engine::MovementComponent(m_transform, 5));
        engine::SpriteRenderer* sprite = new engine::SpriteRenderer(m_transform, textDir, target);
        this->addComponent(new engine::AnimationController(m_transform, sprite));
    }

    Player::~Player()
    {
    }
}