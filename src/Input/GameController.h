#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "InputAction.h"
#include <vector>

class GameController
{
public:
    GameController();

    InputAction GetActionForKey(InputKey key) const;
    void AddInputActionForKey(const ButtonAction& buttonAction);
    void ClearAll();

    static bool IsPressed(InputState state);
    static bool IsReleased(InputState state);
    static InputKey ActionKey(); 
    static InputKey CancelKey(); 
    static InputKey LeftKey(); 
    static InputKey RightKey(); 
    static InputKey UpKey(); 
    static InputKey DownKey(); 

private:
    std::vector<ButtonAction> m_buttonActions{};

};

#endif