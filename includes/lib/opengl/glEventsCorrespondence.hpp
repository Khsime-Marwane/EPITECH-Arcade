//
// Author: Marwane Khsime 
// Date: 2017-03-29 05:35:00 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-03-29 05:35:00
//

#ifndef GL_EVENT_CORRESPONDENCE_HPP_
# define GL_EVENT_CORRESPONDENCE_HPP_

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <map>
#include "Event.hh"

namespace arcade
{
    static const std::map<const int, const int>   _glKeyboardKeys = {
        { GLFW_KEY_UNKNOWN, KB_NONE },
        { GLFW_KEY_A, KB_A },
        { GLFW_KEY_B, KB_B },
        { GLFW_KEY_C, KB_C },
        { GLFW_KEY_D, KB_D },
        { GLFW_KEY_E, KB_E },
        { GLFW_KEY_F, KB_F },
        { GLFW_KEY_G, KB_G },
        { GLFW_KEY_H, KB_H },
        { GLFW_KEY_I, KB_I },
        { GLFW_KEY_J, KB_J },
        { GLFW_KEY_K, KB_K },
        { GLFW_KEY_L, KB_L },
        { GLFW_KEY_M, KB_M },
        { GLFW_KEY_N, KB_N },
        { GLFW_KEY_O, KB_O },
        { GLFW_KEY_P, KB_P },
        { GLFW_KEY_Q, KB_Q },
        { GLFW_KEY_R, KB_R },
        { GLFW_KEY_S, KB_S },
        { GLFW_KEY_T, KB_T },
        { GLFW_KEY_U, KB_U },
        { GLFW_KEY_V, KB_V },
        { GLFW_KEY_W, KB_W },
        { GLFW_KEY_X, KB_X },
        { GLFW_KEY_Y, KB_Y },
        { GLFW_KEY_Z, KB_Z },
        { GLFW_KEY_0, KB_0 },
        { GLFW_KEY_1, KB_1 },
        { GLFW_KEY_2, KB_2 },
        { GLFW_KEY_3, KB_3 },
        { GLFW_KEY_4, KB_4 },
        { GLFW_KEY_5, KB_5 },
        { GLFW_KEY_6, KB_6 },
        { GLFW_KEY_7, KB_7 },
        { GLFW_KEY_8, KB_8 },
        { GLFW_KEY_9, KB_9 },
        { GLFW_KEY_LEFT, KB_ARROW_LEFT },
        { GLFW_KEY_RIGHT, KB_ARROW_RIGHT },
        { GLFW_KEY_UP, KB_ARROW_UP },
        { GLFW_KEY_DOWN, KB_ARROW_DOWN },
        { GLFW_KEY_SPACE, KB_SPACE },
        { GLFW_KEY_ENTER, KB_ENTER },
        { GLFW_KEY_BACKSPACE, KB_BACKSPACE },
        { GLFW_KEY_LEFT_CONTROL, KB_LCTRL },
        { GLFW_KEY_RIGHT_CONTROL, KB_RCTRL },
        { GLFW_KEY_LEFT_ALT, KB_LALT },
        { GLFW_KEY_RIGHT_ALT, KB_RALT },
        { GLFW_KEY_LEFT_SHIFT, KB_LSHIFT },
        { GLFW_KEY_RIGHT_SHIFT, KB_RSHIFT },
        { GLFW_KEY_CAPS_LOCK, KB_CAPSLOCK },
        { GLFW_KEY_TAB, KB_TAB },
        { GLFW_KEY_ESCAPE, KB_ESCAPE },
        { GLFW_KEY_PAGE_UP, KB_PAGEUP },
        { GLFW_KEY_PAGE_DOWN, KB_PAGEDOWN },
        { GLFW_KEY_HOME, KB_HOME },
        { GLFW_KEY_END, KB_END },
        { GLFW_KEY_F1, KB_FN1 },
        { GLFW_KEY_F2, KB_FN2 },
        { GLFW_KEY_F3, KB_FN3 },
        { GLFW_KEY_F4, KB_FN4 },
        { GLFW_KEY_F5, KB_FN5 },
        { GLFW_KEY_F6, KB_FN6 },
        { GLFW_KEY_F7, KB_FN7 },
        { GLFW_KEY_F8, KB_FN8 },
        { GLFW_KEY_F9, KB_FN9 },
        { GLFW_KEY_F10, KB_FN10 },
        { GLFW_KEY_F11, KB_FN11 },
        { GLFW_KEY_F12, KB_FN12 },
        { GLFW_KEY_COMMA, KB_COLON },
        { GLFW_KEY_PERIOD, KB_DOT },  // '.'
        { GLFW_KEY_SLASH, KB_SLASH },
        { GLFW_KEY_WORLD_1, KB_INFERIOR }, // '<'
        { GLFW_KEY_WORLD_2, KB_SUPERIOR }, // '>'
        { GLFW_KEY_SEMICOLON, KB_SEMICOLON },
        { GLFW_KEY_APOSTROPHE, KB_SIMPLEQUOTE },
        { GLFW_KEY_LEFT_BRACKET, KB_LEFTBRACKET },
        { GLFW_KEY_RIGHT_BRACKET, KB_RIGHTBRACKET },
        { GLFW_KEY_BACKSLASH, KB_BACKSLASH },
        { GLFW_KEY_MINUS, KB_MINUS },
        { GLFW_KEY_KP_ADD, KB_PLUS },
        { GLFW_KEY_KP_EQUAL, KB_EQUALS },
        { GLFW_KEY_DELETE, KB_DELETE },
        { GLFW_KEY_KP_MULTIPLY, KB_ASTERISK } // '*'

        // '?' Not supported
        // ':' Not supported
        // '"' Not supported
        // '{' and '}' Not supported
        // '(' and ')' Not supported
        // '|' Not supported
        // '!' Not supported
        // '@' Not supported
        // '#' Not supported
        // '$' Not supported
        // '*' Not supported
        // '%' Not supported
        // '^' Not supported
        // '&' Not supported
        // '_' Not supported
        //
    };

    static const std::map<const int, const int>   _glMouseKey = {
        { GLFW_KEY_UNKNOWN, M_NONE },
        { GLFW_MOUSE_BUTTON_LEFT, M_LEFT_CLICK },
        { GLFW_MOUSE_BUTTON_RIGHT, M_RIGHT_CLICK },
        { GLFW_MOUSE_BUTTON_MIDDLE, M_MIDDLE_CLICK },
        { GLFW_MOUSE_BUTTON_1, M_BT0 },
        { GLFW_MOUSE_BUTTON_2, M_BT1 },
        { GLFW_MOUSE_BUTTON_3, M_BT2 },
        { GLFW_MOUSE_BUTTON_4, M_BT3 },
        { GLFW_MOUSE_BUTTON_5, M_BT4 },
        { GLFW_MOUSE_BUTTON_6, M_BT5 },
        { GLFW_MOUSE_BUTTON_7, M_BT6 },
        { GLFW_MOUSE_BUTTON_8, M_BT7 }

        // Scroll is not supported
    };

    static const std::map<const int, const int>   _glControllerKey = {
        { GLFW_KEY_UNKNOWN, C_NONE }
    };
}

# endif // GL_EVENT_CORRESPONDENCE_HPP_