#include "Color.h"
#include <SDL2/SDL.h>


const SDL_PixelFormat* Color::m_Format = nullptr;
void Color::InitColorFormat(const SDL_PixelFormat* format)
{
	Color::m_Format = format;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SetRGBA(r, g, b, a);
}

void Color::SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	m_Color = SDL_MapRGBA(m_Format, r, g, b, a);
}


void Color::SetRed(uint8_t red)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_Color, m_Format, &r, &g, &b, &a);
	SetRGBA(red, g, b, a);
}
void Color::SetBlue(uint8_t blue)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_Color, m_Format, &r, &g, &b, &a);
	SetRGBA(r, g, blue, a);
}
void Color::SetGreen(uint8_t green)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_Color, m_Format, &r, &g, &b, &a);
	SetRGBA(r, green, b, a);
}
void Color::SetAlpha(uint8_t alpha)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_Color, m_Format, &r, &g, &b, &a);
	SetRGBA(r, g, b, alpha);
}

uint8_t Color::GetRed() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_Color, m_Format, &r, &g, &b, &a);
	return r;
}
uint8_t Color::GetBlue() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_Color, m_Format, &r, &g, &b, &a);
	return b;
}
uint8_t Color::GetGreen() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_Color, m_Format, &r, &g, &b, &a);
	return g;
}
uint8_t Color::GetAlpha() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_Color, m_Format, &r, &g, &b, &a);
	return a;
}