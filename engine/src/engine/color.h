#pragma once

#include <cinttypes>

namespace Engine
{
	struct Color
	{
		float r;
		float g;
		float b;
		float a;

		Color();
		Color(float r, float g, float b);
		Color(float r, float g, float b, float a);

		void clamp01();
		uint32_t getHex();
		static Color fromHex(uint32_t color);
		static Color fromHSV(uint16_t h, float s, float v);

		Color operator+(const Color& other);
		Color operator-(const Color& other);
		Color operator*(const Color& other);
		Color& operator+=(const Color& other);
		Color& operator-=(const Color& other);
		Color& operator*=(const Color& other);
	};
}