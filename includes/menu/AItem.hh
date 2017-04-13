//
// Created by maud on 21/03/17.
//

#ifndef AITEM_HH
#define AITEM_HH

#include <string>
#include "Color.hh"
#include "GameState.hh"
#include "IComponent.hh"

namespace arcade
{
    class AItem : public IComponent
    {
    protected:
        double          _x;
        double          _y;
        double          _width;
        double          _height;
        std::size_t     _backgroundId;
        arcade::Color   _backgroundColor;
        std::string     _text;

    public:
        AItem(double const, double const, double const, double const, std::size_t const, arcade::Color const &, std::string const &);

        virtual ~AItem();

        double  getX() const;
        double  getY() const;

        double  getWidth() const;
        double  getHeight() const;

        bool                hasSprite() const;
        std::size_t         getBackgroundId() const;
        arcade::Color       getBackgroundColor() const;
        std::string const   &getText() const;
        void                setClicked();
    };
}

#endif //IBUTTON_HH
