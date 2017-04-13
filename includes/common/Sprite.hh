//
// Author: Marwane Khsime
// Date: 2017-04-04 05:51:10
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-04-04 05:51:10
//

#ifndef SPRITE_HH_
# define SPRITE_HH_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "ISprite.hh"

namespace arcade
{
  class   Sprite : public ISprite
  {
  private:
    std::vector<std::pair<std::string, char>> _sprites;

  public:
    Sprite(const std::vector<std::pair<std::string, char>> &);
    ~Sprite();

    virtual std::size_t spritesCount() const;
    virtual std::string getGraphicPath(std::size_t pos) const;
    virtual char getAscii(std::size_t pos) const;
  };
}

#endif /* !SPRITE_HH_ */