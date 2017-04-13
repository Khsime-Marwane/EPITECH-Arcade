#ifndef CENTIPEDE_HH_
# define CENTIPEDE_HH_

# include <map>
# include "Map.hh"
# include "CentipedePart.hh"

namespace centipede
{
  enum    Direction
    {
      NORTH,
      EAST,
      SOUTH,
      WEST
    };

  class Shot
  {
    int x;
    int y;
    Direction direction;
    std::map<Direction, std::pair<int, int>>  &pos;
    arcade::Map &map;
    size_t  initialMoveCD;
    size_t  moveCD;

  public:
    Shot(int,
         int,
         std::map<Direction, std::pair<int, int>> &,
         arcade::Map &);
    ~Shot();

    void  eraseFromMap();
    void  printOnMap();
    int   move(std::vector<std::shared_ptr<centipede::CentipedePart>> &);
    int   checkCollisions(std::vector<std::shared_ptr<centipede::CentipedePart>> &);
  };
}

#endif
