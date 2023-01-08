#include "ScreenBuffer.h"
#include <SDL2/SDL.h>
#include <utility>




ScreenBuffer::ScreenBuffer(uint32_t format, int width, int height)
	:	m_Surface{ SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format) }
{
}

ScreenBuffer::ScreenBuffer(const ScreenBuffer& src)
{
	m_Surface.reset(SDL_CreateRGBSurfaceWithFormat(0, src.m_Surface->w, src.m_Surface->h, 0, src.m_Surface->format->format));

	SDL_BlitSurface(src.m_Surface.get(), nullptr, m_Surface.get(), nullptr);
}

ScreenBuffer::~ScreenBuffer()
{
	if (m_Surface)
	{
		SDL_FreeSurface(m_Surface.get());
		m_Surface.release();
	}
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& rhs)
{
	ScreenBuffer temp{ rhs };
	swap(temp);
	return *this;
}

void ScreenBuffer::Clear(const Color& color)
{
	if (m_Surface)
	{
		SDL_FillRect(m_Surface.get(), nullptr, color.GetPixelColor());
	}
}

void ScreenBuffer::SetPixel(const Color& color, int x, int y)
{
	if (m_Surface && (y < m_Surface->h && y >= 0 && x < m_Surface->w && x >= 0))
	{
		SDL_LockSurface(m_Surface.get());

		uint32_t* pixels = (uint32_t*)m_Surface->pixels;
		size_t index = GetIndex(y, x);

		pixels[index] = color.GetPixelColor();

		SDL_UnlockSurface(m_Surface.get());
	}
}

void ScreenBuffer::swap(ScreenBuffer& other) noexcept
{
	std::swap(m_Surface, other.m_Surface);
}

uint32_t ScreenBuffer::GetIndex(int r, int c)
{
	return r * m_Surface->w + c;
}

void swap(ScreenBuffer& first, ScreenBuffer& second) noexcept
{
	first.swap(second);
}
