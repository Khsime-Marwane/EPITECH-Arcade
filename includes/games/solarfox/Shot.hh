#ifndef SHOT_HH_
# define SHOT_HH_

# include <cstddef>
# include "Map.hh"

namespace sf
{
  enum      mvType
    {
      VERTICAL,
      HORIZONTAL
    };

  class   Shot
  {
    size_t  layer;
    double  x;
    double  y;
    size_t  lifeDuration;
    int     direction;
    double  moveSpeed;
    mvType  mv;
    bool    player;

  public:
    Shot(size_t,
         double,
         double,
         size_t,
         int,
         double,
         mvType,
         bool);
    ~Shot();

    int     getAssociatedSpritePos() const;
    bool    Collide(sf::Shot &) const;
    bool    destroyPLayer(std::unique_ptr<arcade::Map> &) const;
    void    printOnMap(std::unique_ptr<arcade::Map> &) const;
    void    eraseFromMap(std::unique_ptr<arcade::Map> &) const;
    int     move(std::unique_ptr<arcade::Map> &);
    bool    isAlive();
    double  getX() const;
    double  getY() const;
  };
}

#endif
