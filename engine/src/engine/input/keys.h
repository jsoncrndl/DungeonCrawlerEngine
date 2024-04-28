#pragma once

#include <cinttypes>
#include <SDL.h>

namespace Engine::Input
{
    // These keys will suffice for now. If more are needed they can be added here in the future
    enum class Key : uint32_t
    {
        Key_0 = SDL_KeyCode::SDLK_0,
        Key_1 = SDL_KeyCode::SDLK_1,
        Key_2 = SDL_KeyCode::SDLK_2,
        Key_3 = SDL_KeyCode::SDLK_3,
        Key_4 = SDL_KeyCode::SDLK_4,
        Key_5 = SDL_KeyCode::SDLK_5,
        Key_6 = SDL_KeyCode::SDLK_6,
        Key_7 = SDL_KeyCode::SDLK_7,
        Key_8 = SDL_KeyCode::SDLK_8,
        Key_9 = SDL_KeyCode::SDLK_9,

        Key_A = SDL_KeyCode::SDLK_a,
        Key_B = SDL_KeyCode::SDLK_b,
        Key_C = SDL_KeyCode::SDLK_c,
        Key_D = SDL_KeyCode::SDLK_d,
        Key_E = SDL_KeyCode::SDLK_e,
        Key_F = SDL_KeyCode::SDLK_f,
        Key_G = SDL_KeyCode::SDLK_g,
        Key_H = SDL_KeyCode::SDLK_h,
        Key_I = SDL_KeyCode::SDLK_i,
        Key_J = SDL_KeyCode::SDLK_j,
        Key_K = SDL_KeyCode::SDLK_k,
        Key_L = SDL_KeyCode::SDLK_l,
        Key_M = SDL_KeyCode::SDLK_m,
        Key_N = SDL_KeyCode::SDLK_n,
        Key_O = SDL_KeyCode::SDLK_o,
        Key_P = SDL_KeyCode::SDLK_p,
        Key_Q = SDL_KeyCode::SDLK_q,
        Key_R = SDL_KeyCode::SDLK_r,
        Key_S = SDL_KeyCode::SDLK_s,
        Key_T = SDL_KeyCode::SDLK_t,
        Key_U = SDL_KeyCode::SDLK_u,
        Key_V = SDL_KeyCode::SDLK_v,
        Key_W = SDL_KeyCode::SDLK_w,
        Key_X = SDL_KeyCode::SDLK_x,
        Key_Y = SDL_KeyCode::SDLK_y,
        Key_Z = SDL_KeyCode::SDLK_z,

        Key_F1 = SDL_KeyCode::SDLK_F1,
        Key_F2 = SDL_KeyCode::SDLK_F2,
        Key_F3 = SDL_KeyCode::SDLK_F3,
        Key_F4 = SDL_KeyCode::SDLK_F4,
        Key_F5 = SDL_KeyCode::SDLK_F5,
        Key_F6 = SDL_KeyCode::SDLK_F6,
        Key_F7 = SDL_KeyCode::SDLK_F7,
        Key_F8 = SDL_KeyCode::SDLK_F8,
        Key_F9 = SDL_KeyCode::SDLK_F9,
        Key_F10 = SDL_KeyCode::SDLK_F10,
        Key_F11 = SDL_KeyCode::SDLK_F11,
        Key_F12 = SDL_KeyCode::SDLK_F12,

        KEY_Enter = SDL_KeyCode::SDLK_RETURN,
        KEY_Backspace = SDL_KeyCode::SDLK_BACKSPACE,
        KEY_SpaceBar = SDL_KeyCode::SDLK_SPACE,
        KEY_Tab = SDL_KeyCode::SDLK_TAB,
        KEY_LeftShift = SDL_KeyCode::SDLK_LSHIFT,
        KEY_RightShift = SDL_KeyCode::SDLK_RSHIFT,
    };

    enum KeyModifier
    {
        Shift = SDL_Keymod::KMOD_SHIFT,
        Control = SDL_Keymod::KMOD_CTRL,
        Alt = SDL_Keymod::KMOD_ALT
    };
}