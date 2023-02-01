#pragma once

#ifndef SCREEN_H
#define SCREEN_H

#include <cstdint>
#include <memory>
#include "ScreenBuffer.h"
#include "Color.h"

class Vector2D;
class Line2D;
class Triangle;
class Circle;
class AARectangle;
struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:

	Screen() = default;
	Screen(uint32_t width, uint32_t height, uint32_t mag);
	~Screen();

	// Copy assignmetn or construction is not allowed
	Screen(const Screen& src) = delete;
	Screen(Screen&& src) = delete;
	Screen& operator=(const Screen& rhs) = delete;
	Screen& operator=(Screen&& rhs) = delete;

	void SwapScreen();
	inline void SetClearColor(const Color& clearColor) { m_ClearColor = clearColor; }
	inline uint32_t Width() const { return m_Width; }
	inline uint32_t Height() const { return m_Height; }

	// Draw methods
	void Draw(int x, int y, const Color& color);
	void Draw(const Vector2D& point, const Color& color);
	void Draw(const Line2D& line, const Color& color);
	void Draw(const Triangle& triangle, const Color& color);
	void Draw(const Circle& circle, const Color& color);
	void Draw(const AARectangle& rect, const Color& color);

private:

	void ClearScreen();

	uint32_t m_Width{};
	uint32_t m_Height{};

	Color m_ClearColor{};
	ScreenBuffer m_BackBuffer{};

	SDL_Window* m_Window{ nullptr };
	SDL_Surface* m_Surface{ nullptr };
};

#endif // !SCREEN_H
