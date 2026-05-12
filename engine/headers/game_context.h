#pragma once

#include "sdl_context.h"

namespace bliss::core
{
	class GameContext
	{
	public:
		GameContext(const SdlContext& p_SdlContextRef);
		~GameContext() = default;

	private:
		const SdlContext& m_SdlContextRef;
		bool m_Running { true };

	private:
		void Run();
		void Update();
		void Render();
		void PollEvents();
	};
}