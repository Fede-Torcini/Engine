#pragma once
#include <string>
#include "Constants.h"

namespace engine
{
namespace constants
{
namespace componentNames 
{
	const std::string ANIMATION_CONTROLLER = "AnimatorController";
	const std::string MOVEMENT_COMPONENT = "MovementController";
	const std::string SPRITE_RENDERER = "SpriteRenderer";
};
	const std::string TITLE = "ENGINE";
	const int WINDOW_SIZE_X = 800;
	const int WINDOW_SIZE_Y = 600;
	const unsigned int FRAME_LIMIT = 60;
	const bool FULLSCREEN = false;
	const bool VSYNC = false;
	const unsigned int ANTIALIASING = false;

	const std::string PLAYER_TEXTURE_DIR = "src/resources/player_texture.png";
}
}