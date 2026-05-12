#include "game_context.h"

namespace bliss::core
{
	GameContext::GameContext(const SdlContext& p_SdlContextRef)
		: m_SdlContextRef(p_SdlContextRef)
	{
		Run();
	}

	void GameContext::Run()
	{
		while (m_Running)
		{
			PollEvents();
			Update();
			Render();
		}
	}

	void GameContext::Update()
	{

	}

	void GameContext::Render()
	{
		SDL_Renderer& renderer = m_SdlContextRef.GetRenderer();

		SDL_SetRenderDrawColor(&renderer, 20, 20, 20, 255);
		SDL_RenderClear(&renderer);
		SDL_RenderPresent(&renderer);
	}

	void GameContext::PollEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{	
			switch (event.type)
			{	
			case SDL_EVENT_QUIT:
				m_Running = false;
				break;

			default:
				break;
			}
		}
	}
}