#pragma once
#include <string>

namespace engine
{
namespace constants
{
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