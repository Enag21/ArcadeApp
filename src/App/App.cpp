#include "App.h"
#include <SDL2/SDL.h>
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "Color.h"

App& App::Singleton()
{
    static App theApp;
    return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    m_noptrWindow = m_Screen.Init(width, height, mag);
    return m_noptrWindow != nullptr;
}

void App::Run()
{
    if (m_noptrWindow)
    {
        uint64_t lastTick{ SDL_GetTicks64() };
        uint64_t curretnTick{ lastTick };
        uint64_t dt{ 10 };
        uint64_t accumulator{ 0 };

        SDL_Event sdlEvent;
        bool running{ true };

        while (running)
        {
            curretnTick = SDL_GetTicks64();
            uint64_t frameTime{ curretnTick - lastTick };

            if (frameTime > 300)
            {
                frameTime = 300;
            }
            
            lastTick = curretnTick;
            accumulator += frameTime;

            // Input
            while (SDL_PollEvent(&sdlEvent))
            {
                switch (sdlEvent.type)
                {
                case SDL_QUIT:
                    running = false;
                    break;
                }
            }

            // Update
            while (accumulator >= dt)
            {
                // update curretn scene by dt
                accumulator -= dt;
            }

            // Render
            m_Screen.DrawBoard(20);
            m_Screen.SwapScreens();
        }
    }
}