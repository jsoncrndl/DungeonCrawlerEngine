#include "color.h"

#include <cmath>
#include <tuple>

namespace Engine
{
    Color::Color() : r(0), g(0), b(0), a(1)
    {
    }
    Color::Color(float r, float g, float b) : r(r), g(g), b(b), a(1)
    {
    }
    Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a)
    {
    }

    void Color::clamp01()
    {
        r = std::min(1.0F, std::max(0.0F, r));
        g = std::min(1.0F, std::max(0.0F, g));
        b = std::min(1.0F, std::max(0.0F, b));
        a = std::min(1.0F, std::max(0.0F, a));
    }

    uint32_t Engine::Color::getHex()
    {
        uint32_t hex = 0;
        uint8_t rByte = static_cast<uint8_t>(r * 255);
        uint8_t gByte = static_cast<uint8_t>(g * 255);
        uint8_t bByte = static_cast<uint8_t>(b * 255);

        hex |= rByte;
        hex = hex << 8;
        hex |= gByte;
        hex = hex << 8;
        hex |= bByte;

        return hex;
    }

    Color Engine::Color::fromHex(uint32_t color)
    {
        float r = static_cast<float>((color >> 16) & 0xFF) / 255;
        float g = static_cast<float>((color >> 8) & 0xFF) / 255;
        float b = static_cast<float>(color & 0xFF) / 255;

        return Color(r, g, b);
    }

    /// <summary>
    /// Calculate the RGB color from the given hue, saturation, and brightness
    /// </summary>
    /// <param name="hue">Hue in the range 0-360</param>
    /// <param name="saturation">Saturation in the range 0-1</param>
    /// <param name="value">Value in the range 0-1</param>
    /// <returns></returns>
    Color Engine::Color::fromHSV(uint16_t hue, float saturation, float value)
    {
        float chroma = value * saturation; // RGB range
        float minRGB = value - chroma; // Minimum rgb value (Value is max rgb value)

        float gradient = chroma * (1 - std::abs(std::fmodf(static_cast<float>(hue) / 60.0f, 2) - 1)); // This is essentially a lerp in the chroma range

        std::tuple<float, float, float> deltaRGB; // How far from the minRGB this color is

        switch (hue / 60)
        {
        case 0:
            deltaRGB = { chroma, gradient, 0};
            break;
        case 1:
            deltaRGB = { gradient, chroma, 0 };
            break;
        case 2:
            deltaRGB = { 0, chroma, gradient };
            break;
        case 3:
            deltaRGB = { 0, gradient, chroma };
            break;
        case 4:
            deltaRGB = { gradient, 0, chroma };
            break;
        case 5:
            deltaRGB = { chroma, 0, gradient };
        }

        return Color(std::get<0>(deltaRGB) + minRGB, std::get<1>(deltaRGB) + minRGB, std::get<2>(deltaRGB) + minRGB);
    }

    Color Engine::Color::operator+(const Color& other)
    {
        return Color(r + other.r, g + other.g, b + other.b, a + other.a);
    }

    Color Engine::Color::operator-(const Color& other)
    {
        return Color(r - other.r, g - other.g, b - other.b, a - other.a);
    }

    Color Engine::Color::operator*(const Color& other)
    {
        return Color(r * other.r, g * other.g, b * other.b, a * other.a);
    }

    Color& Engine::Color::operator+=(const Color& other)
    {
        r += other.r;
        g += other.g;
        b += other.b;
        a += other.a;

        return *this;
    }

    Color& Engine::Color::operator-=(const Color& other)
    {
        r -= other.r;
        g -= other.g;
        b -= other.b;

        return *this;
    }

    Color& Engine::Color::operator*=(const Color& other)
    {
        r *= other.r;
        g *= other.g;
        b *= other.b;

        return *this;
    }
}
