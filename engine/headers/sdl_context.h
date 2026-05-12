#pragma once

#include <string>

#include <SDL3/SDL.h>

namespace bliss::core
{
	class SdlContext
	{
	public:
		SdlContext(const std::string& p_Title, int p_Width, int p_Height);
		~SdlContext();

	private:
		SDL_Window* m_Window {nullptr};
		SDL_Renderer* m_Renderer {nullptr};

	public:
		SDL_Window& GetWindow() const;
		SDL_Renderer& GetRenderer() const;
	};
}