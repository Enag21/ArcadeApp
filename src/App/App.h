#ifndef APP_H
#define APP_H

#include "Screen.h"
#include <cstdint>
#include <memory>
#include <vector>

struct SDL_Window;
class Scene;

class App
{
public:
    static App& Singleton();
    bool Init(uint32_t width, uint32_t height, uint32_t mag);
    void Run();

    inline uint32_t Width() const { return m_Screen.Width(); }
    inline uint32_t Height() const { return m_Screen.Height(); }

    void PushScene(std::unique_ptr<Scene> scene);
    void PopScene();
    Scene* TopScene(); // Current scene

private:
    Screen m_Screen;
    SDL_Window* m_noptrWindow{ nullptr };

    std::vector<std::unique_ptr<Scene>> m_SceneStack{};
};

#endif  // APP_H