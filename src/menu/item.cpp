//
// Created by maud on 26/03/17.
//

#include <iostream>
#include "AItem.hh"

arcade::AItem::AItem(double const x, double const y, double const width, double const height, std::size_t backgroundId, arcade::Color const &backgroundColor, std::string const &text)
:   _x(x),
    _y(y),
    _width(width),
    _height(height),
    _backgroundId(backgroundId),
    _backgroundColor(backgroundColor),
    _text(text)
{
}

arcade::AItem::~AItem()
{
}

double  arcade::AItem::getX() const
{
    return (_x);
}

double  arcade::AItem::getY() const
{
    return (_y);
}

double  arcade::AItem::getWidth() const
{
    return (_width);
}

double  arcade::AItem::getHeight() const
{
    return (_height);
}

std::size_t arcade::AItem::getBackgroundId() const
{
    return (_backgroundId);
}

arcade::Color   arcade::AItem::getBackgroundColor() const
{
    return (_backgroundColor);
}

std::string const   &arcade::AItem::getText() const
{
    return (_text);
}

bool                arcade::AItem::hasSprite() const
{
    return (true);
}

void    arcade::AItem::setClicked()
{
}