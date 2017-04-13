//
// Author: Maud Marel 
// Date: 2017-04-01 13:31:16 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-04-01 13:31:16
//

#include "settingsButton.hh"

arcade::settingsButton::settingsButton(double const x, double const y, double const width, double const height, std::size_t backgroundId, arcade::Color const &backgroundColor, std::string const &text)
: AItem(x, y, width, height, backgroundId, backgroundColor, text)
{
}

arcade::settingsButton::~settingsButton()
{
}

void    arcade::settingsButton::display()
{
}