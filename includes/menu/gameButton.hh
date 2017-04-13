//
// Author: Maud Marel 
// Date: 2017-03-31 23:04:42 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-03-31 23:04:42
//

#ifndef GAMEBUTTON_HH_
# define GAMEBUTTON_HH_

#include "AItem.hh"

namespace arcade
{
    class gameButton : public AItem
    {
    protected:
        std::string _name;
    public:
        gameButton(double const, double const, double const, double const, std::size_t const, arcade::Color const &, std::string const &, std::string const &);
        virtual ~gameButton();

        std::string getName();
        void onclick();        
    };
}

#endif /* !GAMEBUTTON_HH_ */