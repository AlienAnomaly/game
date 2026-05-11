#pragma once

namespace bliss::math
{
	class Vec2
	{
	public:
		Vec2() = default;
		Vec2(float p_X, float p_Y) : x(p_X), y(p_Y) {};
		~Vec2() = default;

	public:
		float x {0.0f}, y {0.0f};

	public:
		inline Vec2 operator+(const Vec2& v)
		{	
			return { this->x + v.x, this->y + v.y };
		}

		inline Vec2 operator-(const Vec2& v)
		{
			return { this->x - v.x, this->y - v.y };
		}

		inline Vec2 operator*(const Vec2& v)
		{
			return { this->x * v.x, this->y * v.y };
		}

		inline Vec2& operator+=(const Vec2& v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}

		inline Vec2& operator-=(const Vec2& v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}

		inline Vec2& operator*=(const Vec2& v)
		{
			x *= v.x;
			y *= v.y;
			return *this;
		}
	};
}