#ifndef SNAKEPART_H_
# define SNAKEPART_H_

# include <memory>
# include <cstddef>
# include <string>
# include <list>
# include <map>
# include <utility>
# include <iterator>
# include "Map.hh"
# include "Food.hh"

namespace   snake
{
  enum      PartType
    {
      HEAD,
      BODY,
      TAIL
    };

  enum      Direction
    {
      NORTH,
      EAST,
      SOUTH,
      WEST
    };

  class     SnakePart
  {
    size_t  x;
    size_t  y;
    PartType  type;
    Direction direction;
    std::map<Direction, std::pair<int, int>>  pos;

  public:
    SnakePart(size_t x, size_t y, PartType type, Direction direction);
    ~SnakePart();

    // GETTERS
    size_t  getX() const;
    size_t  getY() const;
    PartType  getType() const;
    Direction getDirection() const;
    int getAssociatedSpriteId(const Direction &) const;
    int getAssociatedSpritePos(const Direction &) const;
    arcade::Color getAssociatedColor() const;

    // SETTERS
    void  setX(size_t);
    void  setY(size_t);
    void  setPartType(PartType);
    void  setDirection(Direction);

    // ACTIONS
    void  eraseFromMap(std::list<std::unique_ptr<SnakePart>> &,
                       std::unique_ptr<arcade::Map> &);
    void  printOnMap(std::list<std::unique_ptr<SnakePart>> &,
                     std::unique_ptr<arcade::Map> &);
    void  goLeft();
    void  goRight();
    void  follow(std::unique_ptr<SnakePart> &prev);
    int   lead(std::list<std::unique_ptr<SnakePart>> &,
               std::unique_ptr<arcade::Map> &,
               std::unique_ptr<snake::Food> &);
    int   move(std::list<std::unique_ptr<SnakePart>> &,
               std::unique_ptr<arcade::Map> &,
               std::unique_ptr<snake::Food> &);
    void  addToBack(std::list<std::unique_ptr<SnakePart>> &);
  };
}

#endif
