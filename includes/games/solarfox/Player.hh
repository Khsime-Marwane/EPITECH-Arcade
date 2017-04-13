#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <map>
# include "Map.hh"
# include "Shot.hh"

namespace sf
{
  enum    Direction
    {
      NORTH,
      EAST,
      SOUTH,
      WEST
    };

  class   Player
  {
    double  x;
    double  y;
    int     xCell;
    int     yCell;
    Direction direction;
    std::map<Direction, std::pair<double, double>>  pos;
    size_t  fire_cd;
    size_t  fcd;
    std::unique_ptr<sf::Shot> shot;

  public:
    Player();
    ~Player();

    double  getX() const;
    double  getY() const;

    Direction getDirection() const;
    void    setDirection(Direction);

    void    printOnMap(std::unique_ptr<arcade::Map> &) const;
    void    eraseFromMap(std::unique_ptr<arcade::Map> &) const;

    bool    fire();
    int     move(std::unique_ptr<arcade::Map> &);

    bool    hasShot() const;
    sf::Shot  &getShot() const;
    bool    checkShotDuration(std::unique_ptr<arcade::Map> &);
    void    deleteShot();
  };
}

#endif
