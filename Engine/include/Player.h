#pragma once

#include "Entity.h"

namespace pacman
{
class Player : public engine::Entity
{
public:
    Player(std::string const& textDir, sf::RenderTarget* target);
    virtual ~Player();    
};
}