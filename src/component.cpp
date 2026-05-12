#include "component.h"

#include <SDL3_image/SDL_image.h>

namespace bliss::ecs
{
	Transform::Transform(float p_X, float p_Y, float p_W, float p_H)
		: m_Position(p_X, p_Y)
		, m_Scale(p_W, p_H)
	{

	}

	math::Vec2 Transform::GetPosition() const
	{
		return m_Position;
	}

	math::Vec2 Transform::GetScale() const
	{
		return m_Scale;
	}

	Texture::Texture(SDL_Renderer& p_SdlRendererRef, const std::filesystem::path& p_TexturePath)
		: m_Texture(IMG_LoadTexture(&p_SdlRendererRef, p_TexturePath.string().c_str()))
	{
		if (!m_Texture)
		{
			throw std::runtime_error("Failed to load texture atlas. Error: " + std::string(SDL_GetError()));
		}
	}

	Texture::~Texture()
	{
		if (m_Texture) SDL_DestroyTexture(m_Texture);
	}
}
