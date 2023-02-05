#include "App.h"
#include <SDL2/SDL.h>
#include "ArcadeScene.h"

App& App::Singleton()
{
    static App theApp;
    return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    m_noptrWindow = m_Screen.Init(width, height, mag);

    auto arcadeScene{ std::make_unique<ArcadeScene>() };
    PushScene(std::move(arcadeScene));

    return m_noptrWindow != nullptr;
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
    //m_SceneStack.push_back(std::move(scene));
    if (scene)
    {
        m_SceneStack.emplace_back(std::move(scene));
        SDL_SetWindowTitle(m_noptrWindow, TopScene()->GetSceneName().c_str());
    }
}

void App::PopScene()
{
    if (m_SceneStack.size() > 1)
    {
        m_SceneStack.pop_back();
    }

    SDL_SetWindowTitle(m_noptrWindow, TopScene()->GetSceneName().c_str());
}

Scene* App::TopScene()
{
    if (m_SceneStack.empty())
    {
        return nullptr;
    }
    
    return m_SceneStack.back().get();
} 

void App::Run()
{
    if (m_noptrWindow)
    {
        SDL_Event sdlEvent;
        bool running{ true };

        uint64_t lastTick{ SDL_GetTicks64() };
        uint64_t curretnTick{ lastTick };
        uint64_t dt{ 10 };
        uint64_t accumulator{ 0 };

        

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

            Scene* topScene{ App::TopScene() };

            if (topScene)
            {
                // Update
                while (accumulator >= dt)
                {
                    // update curretn scene by dt
                    topScene->Update(dt);
                    accumulator -= dt;
                }

                // Render
                topScene->Draw(m_Screen);
            }
            
            m_Screen.SwapScreens();
        }
    }
}