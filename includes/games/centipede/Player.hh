#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <map>
# include <Map.hh>
# include "Shot.hh"

namespace   centipede
{
  class     Player
  {
    int     x;
    int     y;
    std::map<Direction, std::pair<int, int>> pos;
    arcade::Map &map;
    std::unique_ptr<centipede::Shot>  shot;

  public:
    Player(arcade::Map &);
    ~Player();

    centipede::Shot &getShot() const;
    void  deleteShot();
    bool  hasShot() const;
    int   fire(std::vector<std::shared_ptr<centipede::CentipedePart>> &);
    void  move(Direction);
    void  printOnMap() const;
    void  eraseFromMap() const;
  };
}

#endif
