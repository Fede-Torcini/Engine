#include "MovementComponent.h"

namespace engine
{
    MovementComponent::MovementComponent(Transform const& transform, float speed) : Component (transform)
    {
        m_speed = speed;
    }
    MovementComponent::~MovementComponent()
    {
    }
    void MovementComponent::update(float deltaTime)
    {
    }
    void MovementComponent::move(float const dir_x, float const dir_y)
    {
        m_velocity.x = m_speed * dir_x;
        m_velocity.y = m_speed * dir_y;
    }
}