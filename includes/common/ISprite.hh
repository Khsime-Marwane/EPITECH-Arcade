//
// Author: Maud Marel 
// Date: 2017-04-09 18:50:57 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-04-09 18:50:57
//

#ifndef ISPRITE_HH_
# define ISPRITE_HH_

# include <string>

namespace arcade
{
  ///
  /// \class ISprite
  /// \brief Interface to use in order to generate the sprite loading list
  ///
  class ISprite
  {
  public:
    ///
    /// \fn virtual ~ISprite()
    /// \brief virtual destructor
    ///
    virtual ~ISprite() {};

    ///
    /// \fn virtual size_t spritesCount() const = 0
    /// \brief returns the numbers of sprites
    ///
    virtual size_t spritesCount() const = 0;

    ///
    /// \fn virtual std::string getGraphicPath(size_t id) const = 0
    /// \brief generates on-the-fly the path to the sprite at position pos to load
    ///
    virtual std::string getGraphicPath(size_t pos) const = 0;

    ///
    /// \fn virtual std::string const& getAscii() const = 0
    /// \brief returns the ascii character at position pos from the animation sequence
    ///
    virtual char getAscii(size_t pos) const = 0;
  };
}

#endif // !ISPRITE_HH_
