//
// Author: Maud Marel 
// Date: 2017-03-31 19:45:58 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-03-31 19:45:58
//

#include "Text.hh"

arcade::Text::Text(double const x, double const y, double const width, double const height, std::size_t backgroundId, arcade::Color const &backgroundColor, std::string const &text, int const sizetext)
:   AItem(x, y, width, height, backgroundId, backgroundColor, text), _sizetext(sizetext)
{
}

arcade::Text::~Text()
{
}

void    arcade::Text::display()
{
}