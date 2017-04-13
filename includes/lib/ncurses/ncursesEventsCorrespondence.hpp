//
// Author: Marwane Khsime 
// Date: 2017-04-08 05:10:30 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-04-08 05:10:30
//

#ifndef NCURSES_EVENTS_CORRESPONDENCE_HPP
# define NCURSES_EVENTS_CORRESPONDENCE_HPP

#include <ncurses.h>
#include <map>

#include "Event.hh"

namespace arcade
{
    static const std::map<const int, const int>   _ncursesKeyboardKeys = {
        { -1, KB_NONE },
        { 65, KB_A },
        { 66, KB_B },
        { 67, KB_C },
        { 68, KB_D },
        { 69, KB_E },
        { 70, KB_F },
        { 71, KB_G },
        { 72, KB_H },
        { 73, KB_I },
        { 74, KB_J },
        { 75, KB_K },
        { 76, KB_L },
        { 77, KB_M },
        { 78, KB_N },
        { 79, KB_O },
        { 80, KB_P },
        { 81, KB_Q },
        { 82, KB_R },
        { 83, KB_S },
        { 84, KB_T },
        { 85, KB_U },
        { 86, KB_V },
        { 87, KB_W },
        { 88, KB_X },
        { 89, KB_Y },
        { 90, KB_Z },
        { 48, KB_0 },
        { 49, KB_1 },
        { 50, KB_2 },
        { 51, KB_3 },
        { 52, KB_4 },
        { 53, KB_5 },
        { 54, KB_6 },
        { 55, KB_7 },
        { 56, KB_8 },
        { 57, KB_9 },
        { KEY_LEFT, KB_ARROW_LEFT },
        { KEY_RIGHT, KB_ARROW_RIGHT },
        { KEY_UP, KB_ARROW_UP },
        { KEY_DOWN, KB_ARROW_DOWN },
        { 32, KB_SPACE },
        { KEY_ENTER, KB_ENTER },
        { KEY_BACKSPACE, KB_BACKSPACE },
        { 9, KB_TAB },
        { 27, KB_ESCAPE },
        { 339, KB_PAGEUP },
        { 338, KB_PAGEDOWN },
        { KEY_HOME, KB_HOME },
        { KEY_END, KB_END },
        { 265, KB_FN1 },
        { 266, KB_FN2 },
        { 267, KB_FN3 },
        { 268, KB_FN4 },
        { 269, KB_FN5 },
        { 270, KB_FN6 },
        { 271, KB_FN7 },
        { 272, KB_FN8 },
        { 273, KB_FN9 },
        { 274, KB_FN10 },
        { 275, KB_FN11 },
        { 276, KB_FN12 },
        { 58, KB_COLON },
        { 46, KB_DOT },  // '.'
        { 47, KB_SLASH },
        { 59, KB_SEMICOLON },
        { 39, KB_SIMPLEQUOTE },
        { 45, KB_MINUS },
        { 43, KB_PLUS },
        { 61, KB_EQUALS },
        { 62, KB_ASTERISK } // '*'

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
}

#endif // SFML_EVENTS_CORRESPONDENCE_HPP