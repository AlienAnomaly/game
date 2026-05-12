#pragma once

#include <filesystem>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "vec2.h"

namespace bliss::ecs
{
	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;
	};

	class Transform : public Component
	{
	public:
		Transform() = default;
		Transform(float p_X, float p_Y, float p_W, float p_H);
		virtual ~Transform() = default;

	private:
		math::Vec2 m_Position{ 0.0f, 0.0f };
		math::Vec2 m_Scale{ 0.0f, 0.0f };

	public:
		math::Vec2 GetPosition() const;
		math::Vec2 GetScale() const;
	};

	class Texture : public Component
	{
	public:
		Texture(SDL_Renderer& p_SdlRendererRef, const std::filesystem::path& p_TexturePath);
		virtual ~Texture();

	private:
		SDL_Texture* m_Texture {nullptr};
	};

	class TextureAtlas : public Component
	{
	public:
	    TextureAtlas(SDL_Renderer& p_SdlRendererRef, const std::filesystem::path& p_TextureAtlasPath);
		~TextureAtlas();

	private:
	    SDL_Texture* m_TextureAtlas {nullptr};
	};
}
