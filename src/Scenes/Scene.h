#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <cstdint>

class Screen;

// Interface
class Scene
{
public: 
    virtual ~Scene() {}

    virtual void Update(uint64_t dt) = 0;
    virtual void Draw(Screen& theScreen) = 0;
    virtual const std::string& GetSceneName() const = 0;
};

#endif