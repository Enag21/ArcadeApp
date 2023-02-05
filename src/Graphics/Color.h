#pragma once

#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

struct SDL_PixelFormat;

class Color
{
public:

	static const SDL_PixelFormat* m_Format;
	static void InitColorFormat(const SDL_PixelFormat* format);

	// Blending equation
	// SourceRGB * sourceAlpha + DestinationRGB * (1 - sourceAlpha)

	static Color Evaluate1MinusSourceAlpha(const Color& source, const Color& destination);

	static Color Black() { return Color{ 0, 0, 0, 255 }; }
	static Color White() { return Color{ 255, 255, 255, 255 }; }
	static Color Red() { return Color{ 255, 0, 0, 255 }; }
	static Color Blue() { return Color{ 0, 0, 255, 255 }; }
	static Color Green() { return Color{ 0, 255, 0, 255 }; }
	static Color Yellow() { return Color{ 255, 255, 0, 255 }; }
	static Color Magenta() { return Color{ 255, 0, 255, 255 }; }
	static Color Cyan() { return Color{ 37, 240, 217, 255 }; }
	static Color Pink() { return Color{ 252, 197, 224, 255 }; }
	static Color Orange() { return Color{ 245, 190, 100, 255 }; }

	Color() : Color{0} {}
	Color(uint32_t color) : m_Color{ color } {}
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	inline bool operator==(const Color& rhs) const { return m_Color == rhs.m_Color; }
	inline uint32_t GetPixelColor() const { return m_Color; }
	
	void SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void SetRed(uint8_t red);
	void SetBlue(uint8_t blue);
	void SetGreen(uint8_t green);
	void SetAlpha(uint8_t alpha);

	uint8_t GetRed() const;
	uint8_t GetBlue() const;
	uint8_t GetGreen() const;
	uint8_t GetAlpha() const;

private:

	uint32_t m_Color{};
};

#endif // !COLOR_H
