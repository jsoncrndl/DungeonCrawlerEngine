#pragma once

#include <cinttypes>
#include <EASTL/unordered_map.h>
#include <EASTL/vector.h>

#include "engine/input/keys.h"
#include "engine/math_types.h"

namespace Engine::Game::ECS
{
    class InputSystem
    {
        enum class InputAction : uint8_t
        {
            Walk,
            Interact   
        };
        enum class BindingType : uint8_t
        {
            Button,
            Axis,
            Axis2D,
            Composite,
            Composite2D
        };
        enum class ButtonType : uint8_t
        {
            Key,
            Button
        };

        struct ButtonBinding
        {
            ButtonType type;
            union {
                Input::Key key;
            };
        };

        struct CompositeAxisBinding
        {
            ButtonBinding positiveButton;
            ButtonBinding negativeButton;
        };

        struct CompositeAxisBinding2D
        {
            CompositeAxisBinding horizontal;
            CompositeAxisBinding vertical;
        };

        struct InputBinding
        {
            BindingType type;

            union
            {
                ButtonBinding button;
                CompositeAxisBinding axis;
                CompositeAxisBinding2D axis2D;
            };
        };

        class InputContext
        {
            eastl::vector<InputBinding> bindings;
            eastl::unordered_map<Input::Key, eastl::function<InputAction(Input::Key)>> map;

            // Input Context needs to be able to take a key event and update the associated binding state
            /*
            * Options:
                For each input just loop through every binding to check if it is pressed
                Keep track of what buttons were pushed each frame, then loop through all of those buttons
                Needs to be checked at the end, not after each input
                Copying the keyboard state into a buffer could be good
            */
        };

        // Current input context and an array of callback functions for each input action

        // An input context has a map of key events to input actions
        // An input action describes something in the game, like jump, move, etc.
        // Input actions callbacks have a state, information
    };
}