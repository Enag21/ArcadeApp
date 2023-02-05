#include "ArcadeScene.h"
#include "../Graphics/Screen.h"

ArcadeScene::ArcadeScene()
{

}

void ArcadeScene::Update(uint64_t dt) 
{

}

void ArcadeScene::Draw(Screen& theScreen) 
{
    theScreen.DrawBoard(20);
}

const std::string& ArcadeScene::GetSceneName() const 
{
    static std::string sceneName { "Arcade Scene" };
    return sceneName;
}

std::unique_ptr<Scene> GetScene(eGAME game)
{
    switch (game)
    {
        case eGAME::TETRIS:
        {
            
        }
        break;

        case eGAME::ASTEROIDS:
        {

        }
        break;

        case eGAME::PACMAN:
        {

        }
        break;

        case eGAME::BREAK_OUT:
        {

        }
        break;

        default:
        {

        }
        break;
    }
    return nullptr;
}