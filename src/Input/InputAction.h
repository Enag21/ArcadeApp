#ifndef INPUT_ACTION_H
#define INPUT_ACTION_H

#include <functional>
#include <cstdint>

using InputKey = uint8_t;
using InputState = uint8_t;

using InputAction = std::function<void(uint64_t dt, InputState)>;

struct ButtonAction
{
    InputKey key;
    InputAction action;
};

#endif  