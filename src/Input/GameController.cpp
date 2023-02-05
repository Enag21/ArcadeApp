#include "GameController.h"

GameController::GameController()
{

}

InputAction GameController::GetActionForKey(InputKey key) const
{
    for(const auto& buttonAction : m_buttonActions)
    {
        if (key == buttonAction.key)
        {
            return buttonAction.action;
        }
    }
    return [](uint64_t, InputState){};
}

void GameController::AddInputActionForKey(const ButtonAction& buttonAction)
{
    m_buttonActions.push_back(buttonAction);
}

void GameController::ClearAll()
{
    m_buttonActions.clear();
}

bool GameController::IsPressed(InputState state)
{

}

bool GameController::IsReleased(InputState state)
{

}

InputKey GameController::ActionKey()
{

}

InputKey GameController::CancelKey()
{

}

InputKey GameController::LeftKey()
{

}

InputKey GameController::RightKey()
{

}

InputKey GameController::UpKey()
{

}

InputKey GameController::DownKey()
{

}
