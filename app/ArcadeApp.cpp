#include <SDL2/SDL.h>
#include <iostream>

#include "Color.h"
#include "ScreenBuffer.h"
#include "Screen.h"
#include "Line2D.h"

const int SCREEN_WIDTH{ 224 };
const int SCREEN_HEIGHT{ 288 };
const int MAGNIFICATION{ 2 };

int main(int argc, char* argv[])
{
	Screen mainScreen{ SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION };

	Line2D line{ Vector2D{ 0.0, 0.0 }, Vector2D{SCREEN_WIDTH, SCREEN_HEIGHT}};
	mainScreen.Draw(line, Color::Cyan());
	// mainScreen.Draw(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Color::Cyan());
	mainScreen.SwapScreen();

	SDL_Event sdlEvent;
	bool running{ true };

	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}
	}

	return 0;
}

