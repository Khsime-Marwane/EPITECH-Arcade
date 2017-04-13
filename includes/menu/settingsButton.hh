//
// Author: Maud Marel 
// Date: 2017-04-01 09:31:23 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-04-01 09:31:23
//

#ifndef SETTINGSBUTTON_HH_
# define SETTINGSBUTTON_HH_

#include "AItem.hh"

namespace arcade
{
    class settingsButton : public AItem
    {
    public:
        settingsButton(double const, double const, double const, double const, std::size_t const, arcade::Color const &, std::string const &);
        virtual ~settingsButton();

        void display();        
    };
}

#endif /* !SETTINGSBUTTON_HH_ */