//
// Author: Maud Marel 
// Date: 2017-03-31 19:45:40 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-03-31 19:45:40
//

#ifndef TEXT_HH_
# define TEXT_HH_

#include "AItem.hh"

namespace arcade
{
    class Text : public AItem
    {
    private:
        int     _sizetext;
    public:
        Text(double const, double const, double const, double const, std::size_t const, arcade::Color const &, std::string const &, int const);
        virtual ~Text();

        void display();        
    };
}

#endif /* !TEXT_HH_ */