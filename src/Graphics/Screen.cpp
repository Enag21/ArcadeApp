#include "Screen.h"
#include <Vector2D.h>
#include <Line2D.h>
#include <Triangle.h>
#include <Circle.h>
#include <AARectangle.h>
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
	int dx, dy;

	int x0 = roundf(line.GetP0().getX());
	int y0 = roundf(line.GetP0().getY());
	int x1 = roundf(line.GetP1().getX());
	int y1 = roundf(line.GetP1().getY());

	dx = x1 - x0;
	dy = y1 - y0;

	signed const char ix((dx > 0) - (dx < 0)); // evaluate to 1 or -1
	signed const char iy((dy > 0) - (dy < 0));

	dx = abs(dx) * 2;
	dy = abs(dy) * 2;

	Draw(x0, y0, color);

	if(dx >= dy)
	{
		//go along in the x

		int d = dy - dx/2;

		while(x0 != x1)
		{
			if(d >= 0)
			{
				d -= dx;
				y0 += iy;
			}

			d += dy;
			x0 += ix;

			Draw(x0, y0, color);
		}
	}
	else
	{
		//go along in y
		int d = dx - dy/2;

		while(y0 != y1)
		{
			if(d >= 0)
			{
				d -= dy;
				x0 += ix;
			}

			d += dx;
			y0 += iy;

			Draw(x0, y0, color);
		}
	}
}

void Screen::Draw(const Triangle& triangle, const Color& color)
{
	Line2D segment01{ triangle.GetP0(), triangle.GetP1() };
	Line2D segment12{ triangle.GetP1(), triangle.GetP2() };
	Line2D segment20{ triangle.GetP2(), triangle.GetP0() };

	Draw(segment01, color);
	Draw(segment12, color);
	Draw(segment20, color);
}

void Screen::Draw(const Circle& circle, const Color& color)
{

}

void Screen::Draw(const AARectangle& rect, const Color& color)
{
	auto points{ rect.GetPoints() };

	Line2D segment01{ points[0], points[1] };	
	Line2D segment12{ points[1], points[2] };	
	Line2D segment23{ points[2], points[3] };	
	Line2D segment34{ points[3], points[0] };

	Draw(segment01, color);
	Draw(segment12, color);
	Draw(segment23, color);
	Draw(segment34, color);
}

void Screen::ClearScreen()
{
	SDL_FillRect(m_Surface, nullptr, m_ClearColor.GetPixelColor());
}
