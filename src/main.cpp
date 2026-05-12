#include "sdl_context.h"
#include "game_context.h"

#include "entity.h"

int main(int argc, char** argv)
{
	bliss::core::SdlContext sdl_context("Game Window", 800, 600);
	bliss::core::GameContext game_context(sdl_context);
}