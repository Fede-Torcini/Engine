#pragma once 

#include "Component.h"
#include "SpriteRenderer.h"

namespace engine
{
class AnimationController : public Component
{
    
    class Animation
    {
    public:
        sf::Texture textureSheet;
        Animation(sf::Texture textureSheet);
        ~Animation();

        void play();
        void pause();
        void reset();

    private:
        float m_speed;
    };

public:
    AnimationController(Transform& transform, SpriteRenderer* sprite);
    virtual ~AnimationController();

    void createAnimation(std::string const& name, sf::Texture textureSheet);
    void removeAnimation(std::string const& name);
    virtual void update(float deltaTime);
    virtual void draw(sf::RenderTarget* target);

private:
    std::map<std::string, Animation> m_animations;
    std::shared_ptr<SpriteRenderer> m_sprite;
};
}