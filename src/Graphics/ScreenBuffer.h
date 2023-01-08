#pragma once

#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <cstdint>
#include <memory>
#include "Color.h"

struct SDL_Surface;

class ScreenBuffer
{
public:
	ScreenBuffer() = default;
	ScreenBuffer(uint32_t format, int width, int height);
	ScreenBuffer(const ScreenBuffer& src);
	~ScreenBuffer();

	ScreenBuffer& operator=(const ScreenBuffer& rhs);

	inline SDL_Surface* GetSurface() { return m_Surface.get(); }

	void Clear(const Color& color = Color::Black());
	void SetPixel(const Color& color, int x, int y);
	void swap(ScreenBuffer& other) noexcept;

private:

	std::unique_ptr< SDL_Surface> m_Surface{ nullptr };
	uint32_t GetIndex(int r, int c);
};

void swap(ScreenBuffer& first, ScreenBuffer& second) noexcept;


#endif // !SCREEN_BUFFER_H
