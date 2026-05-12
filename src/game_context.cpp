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
	    uint64_t start{0}, end{0};
		uint64_t current{0}, previous{SDL_GetPerformanceCounter()};

		while (m_Running)
		{
		    start = SDL_GetPerformanceCounter();

			PollEvents();
			Update();
			Render();

			end = SDL_GetPerformanceCounter();
			double frame_time = static_cast<double>(end - start) / SDL_GetPerformanceFrequency();

			if (frame_time < (1.0f / 60.0f))
			{
			    SDL_Delay(((1.0f / 60.0f) - frame_time) * 1000.0f);
			}

			current = SDL_GetPerformanceCounter();
			m_DeltaTime = static_cast<double>(current - previous) / SDL_GetPerformanceFrequency();
			previous = current;
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
