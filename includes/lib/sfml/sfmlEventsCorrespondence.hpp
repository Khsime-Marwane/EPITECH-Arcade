//
// Author: Marwane Khsime 
// Date: 2017-04-08 05:10:30 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-04-08 05:10:30
//

#ifndef SFML_EVENTS_CORRESPONDENCE_HPP
# define SFML_EVENTS_CORRESPONDENCE_HPP

#include <SFML/Graphics.hpp>
#include <map>

#include "Event.hh"

namespace arcade
{
    static const std::map<const int, const int>   _sfmlKeyboardKeys = {
        { sf::Keyboard::Unknown, KB_NONE },
        { sf::Keyboard::A, KB_A },
        { sf::Keyboard::B, KB_B },
        { sf::Keyboard::C, KB_C },
        { sf::Keyboard::D, KB_D },
        { sf::Keyboard::E, KB_E },
        { sf::Keyboard::F, KB_F },
        { sf::Keyboard::G, KB_G },
        { sf::Keyboard::H, KB_H },
        { sf::Keyboard::I, KB_I },
        { sf::Keyboard::J, KB_J },
        { sf::Keyboard::K, KB_K },
        { sf::Keyboard::L, KB_L },
        { sf::Keyboard::M, KB_M },
        { sf::Keyboard::N, KB_N },
        { sf::Keyboard::O, KB_O },
        { sf::Keyboard::P, KB_P },
        { sf::Keyboard::Q, KB_Q },
        { sf::Keyboard::R, KB_R },
        { sf::Keyboard::S, KB_S },
        { sf::Keyboard::T, KB_T },
        { sf::Keyboard::U, KB_U },
        { sf::Keyboard::V, KB_V },
        { sf::Keyboard::W, KB_W },
        { sf::Keyboard::X, KB_X },
        { sf::Keyboard::Y, KB_Y },
        { sf::Keyboard::Z, KB_Z },
        { sf::Keyboard::Num0, KB_0 },
        { sf::Keyboard::Num1, KB_1 },
        { sf::Keyboard::Num2, KB_2 },
        { sf::Keyboard::Num3, KB_3 },
        { sf::Keyboard::Num4, KB_4 },
        { sf::Keyboard::Num5, KB_5 },
        { sf::Keyboard::Num6, KB_6 },
        { sf::Keyboard::Num7, KB_7 },
        { sf::Keyboard::Num8, KB_8 },
        { sf::Keyboard::Num9, KB_9 },
        { sf::Keyboard::Left, KB_ARROW_LEFT },
        { sf::Keyboard::Right, KB_ARROW_RIGHT },
        { sf::Keyboard::Up, KB_ARROW_UP },
        { sf::Keyboard::Down, KB_ARROW_DOWN },
        { sf::Keyboard::Space, KB_SPACE },
        { sf::Keyboard::Return, KB_ENTER },
        { sf::Keyboard::BackSpace, KB_BACKSPACE },
        { sf::Keyboard::LControl, KB_LCTRL },
        { sf::Keyboard::RControl, KB_RCTRL },
        { sf::Keyboard::LAlt, KB_LALT },
        { sf::Keyboard::RAlt, KB_RALT },
        { sf::Keyboard::LShift, KB_LSHIFT },
        { sf::Keyboard::RShift, KB_RSHIFT },
        { sf::Keyboard::Tab, KB_TAB },
        { sf::Keyboard::Escape, KB_ESCAPE },
        { sf::Keyboard::PageUp, KB_PAGEUP },
        { sf::Keyboard::PageDown, KB_PAGEDOWN },
        { sf::Keyboard::Home, KB_HOME },
        { sf::Keyboard::End, KB_END },
        { sf::Keyboard::F1, KB_FN1 },
        { sf::Keyboard::F2, KB_FN2 },
        { sf::Keyboard::F3, KB_FN3 },
        { sf::Keyboard::F4, KB_FN4 },
        { sf::Keyboard::F5, KB_FN5 },
        { sf::Keyboard::F6, KB_FN6 },
        { sf::Keyboard::F7, KB_FN7 },
        { sf::Keyboard::F8, KB_FN8 },
        { sf::Keyboard::F9, KB_FN9 },
        { sf::Keyboard::F10, KB_FN10 },
        { sf::Keyboard::F11, KB_FN11 },
        { sf::Keyboard::F12, KB_FN12 },
        { sf::Keyboard::SemiColon, KB_COLON },
        { sf::Keyboard::Period, KB_DOT },  // '.'
        { sf::Keyboard::Slash, KB_SLASH },
        { sf::Keyboard::SemiColon, KB_SEMICOLON },
        { sf::Keyboard::Quote, KB_SIMPLEQUOTE },
        { sf::Keyboard::LBracket, KB_LEFTBRACKET },
        { sf::Keyboard::RBracket, KB_RIGHTBRACKET },
        { sf::Keyboard::BackSlash, KB_BACKSLASH },
        { sf::Keyboard::Subtract, KB_MINUS },
        { sf::Keyboard::Add, KB_PLUS },
        { sf::Keyboard::Equal, KB_EQUALS },
        { sf::Keyboard::Delete, KB_DELETE },
        { sf::Keyboard::Multiply, KB_ASTERISK } // '*'

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

    static const std::map<const int, const int>   _sfmlMouseKeys = {
        { sf::Mouse::Left, M_LEFT_CLICK },
        { sf::Mouse::Right, M_RIGHT_CLICK },
        { sf::Mouse::Middle, M_MIDDLE_CLICK },
        { sf::Mouse::XButton1, M_BT0 },
        { sf::Mouse::XButton2, M_BT1 }
        // Scroll is not supported
    };

    static const std::map<const int, const int>   _sfmlControllerKey = {
        { -1, C_NONE }
    };
}

#endif // SFML_EVENTS_CORRESPONDENCE_HPP