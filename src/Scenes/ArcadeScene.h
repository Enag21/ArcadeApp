#ifndef ARCADE_SCENE_H
#define ARCADE_SCENE_H

#include "Scene.h"
#include <memory>

enum class eGAME
{
    TETRIS = 0,
    BREAK_OUT,
    ASTEROIDS,
    PACMAN,
    NUM_GAMES
};

class ArcadeScene : public Scene
{
public:
    ArcadeScene();
    virtual void Update(uint64_t dt) override;
    virtual void Draw(Screen& theScreen) override;
    virtual const std::string& GetSceneName() const override;

private:
    std::unique_ptr<Scene> GetScene(eGAME game);
};

#endif  // ARCADE_SCENE_H