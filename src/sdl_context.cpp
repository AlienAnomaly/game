#include "sdl_context.h"

#include <stdexcept>

namespace bliss::core
{
	SdlContext::SdlContext(const std::string& p_Title, int p_Width, int p_Height)
	{
		if ((int)SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0)
		{	
			throw std::runtime_error("Failed to initialize SDL. Error: " + std::string(SDL_GetError()));
		}

		m_Window = SDL_CreateWindow(p_Title.c_str(), p_Width, p_Height, SDL_WINDOW_RESIZABLE);
		if (!m_Window)
		{	
			throw std::runtime_error("Failed to create window. Error: " + std::string(SDL_GetError()));
		}

		m_Renderer = SDL_CreateRenderer(m_Window, nullptr);
		if (!m_Renderer)
		{	
			throw std::runtime_error("Failed to create renderer. Error: " + std::string(SDL_GetError()));
		}
	}

	SdlContext::~SdlContext() 
	{
		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}

	SDL_Window& SdlContext::GetWindow() const
	{
		return *m_Window;
	}

	SDL_Renderer& SdlContext::GetRenderer() const
	{
		return *m_Renderer;
	}
}