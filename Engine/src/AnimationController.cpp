#include "AnimationController.h"
#include "Constants.h"

namespace engine
{
    AnimationController::AnimationController(Transform& transform, SpriteRenderer* sprite)
        : Component(transform, constants::componentNames::ANIMATION_CONTROLLER), m_sprite(sprite)
    {
    }
    AnimationController::~AnimationController()
    {
    }
    void AnimationController::createAnimation(std::string const& name, sf::Texture texture)
    {
        Animation temp(std::move(texture));
        m_animations.insert({name, std::move(temp)});
    }
    void AnimationController::removeAnimation(std::string const& name)
    {
    }
    void AnimationController::update(float deltaTime)
    {
        m_sprite->update(deltaTime);
    }
    void AnimationController::draw(sf::RenderTarget* target) 
    {
        m_sprite->draw(target);
    }
    AnimationController::Animation::Animation(sf::Texture texture)
    {
    }
    AnimationController::Animation::~Animation()
    {
    }
    void AnimationController::Animation::play()
    {
    }
    void AnimationController::Animation::pause()
    {
    }
    void AnimationController::Animation::reset()
    {
    }
}