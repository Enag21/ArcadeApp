#include "Screen.h"
#include <Vector2D.h>
#include <Line2D.h>
#include <SDL2/SDL.h>
#include <stdexcept>
#include <cmath>

Screen::Screen(uint32_t width, uint32_t height, uint32_t mag) : m_Width{ width }, m_Height{ height }
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		throw "Error SDL_Init Failed";
	}

	m_Window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
		, m_Width * mag, m_Height * mag, 0);

	if (!m_Window)
	{
		throw "Could not create window. Error: ";
	}

	m_Surface = SDL_GetWindowSurface(m_Window);

	Color::InitColorFormat(m_Surface->format);

	m_ClearColor = Color::Black();
	m_BackBuffer = ScreenBuffer(m_Surface->format->format, m_Width, m_Height);
	m_BackBuffer.Clear(m_ClearColor);
}

Screen::~Screen()
{
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
	}
	SDL_Quit();
}

void Screen::SwapScreen()
{
	ClearScreen();
	SDL_BlitScaled(m_BackBuffer.GetSurface(), nullptr, m_Surface, nullptr);
	SDL_UpdateWindowSurface(m_Window);

	m_BackBuffer.Clear(m_ClearColor);
}

void Screen::Draw(int x, int y, const Color& color)
{
	m_BackBuffer.SetPixel(color, x, y);
}

void Screen::Draw(const Vector2D& point, const Color& color)
{
	m_BackBuffer.SetPixel(color, point.getX(), point.getY());
}

void Screen::Draw(const Line2D& line, const Color& color)
{
	uint32_t deltaX{};
	uint32_t deltaY{};

	uint32_t x0 = roundf(line.GetP0().getX());
	uint32_t y0 = roundf(line.GetP0().getY());
	uint32_t x1 = roundf(line.GetP1().getX());
	uint32_t y1 = roundf(line.GetP1().getY());

	deltaX = x1 - x0;
	deltaY = y1 - y0;

	signed const char incrementX( (deltaX > 0) - (deltaX < 0) ); // Evaluate to 1 -> (delta > 0) or -1 -> (delta < 0)
	signed const char incrementY( (deltaY > 0) - (deltaY < 0) );

	deltaX = fabs(deltaX) * 2;
	deltaY = fabs(deltaY) * 2;

	// Draw first point
	Draw(x0, x1, color);

	if (deltaX >= deltaY)
	{
		// Go along in the x

		uint32_t d{ deltaY - deltaX / 2 };

		while (x0 != x1)
		{
			if (d >= 0)
			{
				d -= deltaX;
				y0 += incrementY;
			}
			d += deltaY;
			x0 += incrementX;

			Draw(x0, y0, color);
		}
	}
	else
	{
		// Go along in the y

		uint32_t d{ deltaX - deltaY / 2 };

		while (y0 != y1)
		{
			if (d >= 0)
			{
				d -= deltaY;
				x0 += incrementX;
			}
			d += deltaX;
			y0 += incrementY;

			Draw(x0, y0, color);
		}
	}
}

void Screen::ClearScreen()
{
	SDL_FillRect(m_Surface, nullptr, m_ClearColor.GetPixelColor());
}
