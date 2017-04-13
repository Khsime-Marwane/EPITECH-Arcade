//
// Author: Maud Marel 
// Date: 2017-03-31 23:08:16 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-03-31 23:08:16
//

#include "gameButton.hh"

arcade::gameButton::gameButton(double const x, double const y, double const width, double const height, std::size_t backgroundId, arcade::Color const &backgroundColor, std::string const &text, std::string const &name)
:   AItem(x, y, width, height, backgroundId, backgroundColor, text), _name(name)
{
}

arcade::gameButton::~gameButton()
{
}

std::string arcade::gameButton::getName()
{
    return (_name);
}

void    arcade::gameButton::onclick()
{
}