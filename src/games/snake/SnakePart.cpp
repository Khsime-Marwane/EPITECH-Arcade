#include <iostream>
#include "SnakePart.hh"

snake::SnakePart::SnakePart(size_t x, size_t y, PartType type, Direction direction)
{
  this->x = x;
  this->y = y;
  this->type = type;
  this->direction = direction;
  this->pos[snake::Direction::NORTH] = std::pair<int, int>(0, -1);
  this->pos[snake::Direction::EAST] = std::pair<int, int>(1, 0);
  this->pos[snake::Direction::SOUTH] = std::pair<int, int>(0, 1);
  this->pos[snake::Direction::WEST] = std::pair<int, int>(-1, 0);
}

snake::SnakePart::~SnakePart()
{
}

// GETTERS
size_t  snake::SnakePart::getX() const
{
  return (this->x);
}

size_t  snake::SnakePart::getY() const
{
  return (this->y);
}

snake::PartType  snake::SnakePart::getType() const
{
  return (this->type);
}

snake::Direction  snake::SnakePart::getDirection() const
{
  return (this->direction);
}

int snake::SnakePart::getAssociatedSpriteId(const Direction &prev) const
{
  if (this->type == BODY)
    {
      if (prev == this->direction)
        return (1);
      else
        return (2);
    }
  else if (this->type == HEAD)
    return (3);
  else
    return (4);
}

int snake::SnakePart::getAssociatedSpritePos(const Direction &prev) const
{
  if (this->type == HEAD)
    return (static_cast<int>(this->direction));
  else if (this->type == TAIL)
    return (static_cast<int>(prev));
  else
    {
      if (prev == this->direction)
        return (static_cast<int>(this->direction) % 2 == 0);
      else if ((prev == EAST && this->direction == NORTH ) ||
               (prev == SOUTH && this->direction == WEST))
        return (0);
      else if ((prev == WEST && this->direction == NORTH) ||
               (prev == SOUTH && this->direction == EAST))
        return (1);
      else if ((prev == NORTH && this->direction == WEST) ||
               (prev == EAST && this->direction == SOUTH))
        return (2);
      else
        return (3);
    }
}

arcade::Color snake::SnakePart::getAssociatedColor() const
{
  if (this->type == snake::PartType::HEAD)
    return (arcade::Color::Red);
  else
    return (arcade::Color::Green);
}

//SETTERS
void  snake::SnakePart::setX(size_t x)
{
  this->x = x;
}

void  snake::SnakePart::setY(size_t y)
{
  this->y = y;
}

void  snake::SnakePart::setPartType(PartType type)
{
  this->type = type;
}

void  snake::SnakePart::setDirection(Direction direction)
{
  if (static_cast<int>(this->direction) + 2 == static_cast<int>(direction) ||
      static_cast<int>(this->direction) - 2 == static_cast<int>(direction))
    return;
  this->direction = direction;
}

// ACTIONS
void  snake::SnakePart::eraseFromMap(std::list<std::unique_ptr<SnakePart>> &list,
                                     std::unique_ptr<arcade::Map> &map)
{
  for (std::list<std::unique_ptr<SnakePart>>::iterator it = list.begin(); it != list.end(); it++)
    {
      map->at(1, it->get()->getX(), it->get()->getY()).set(arcade::TileType::EMPTY,
                                                 arcade::TileTypeEvolution::EMPTY,
                                                 arcade::Color::Transparent,
                                                 false,
                                                 0,
                                                 0,
                                                 0.0,
                                                 0.0);
    }
}

void  snake::SnakePart::printOnMap(std::list<std::unique_ptr<SnakePart>> &list,
                                     std::unique_ptr<arcade::Map> &map)
{
  snake::Direction  prev;

  for (std::list<std::unique_ptr<SnakePart>>::iterator it = list.begin(); it != list.end(); it++)
    {
      if (it != list.begin())
        prev = std::prev(it)->get()->getDirection();
      map->at(1, it->get()->getX(), it->get()->getY()).set(arcade::TileType::EMPTY,
                                                           arcade::TileTypeEvolution::PLAYER,
                                                           arcade::Color::Green,
                                                           true,
                                                           it->get()->getAssociatedSpriteId(prev),
                                                           it->get()->getAssociatedSpritePos(prev),
                                                           0.0,
                                                           0.0);
    }
}

void  snake::SnakePart::goLeft()
{
  int dir;

  dir = static_cast<int>(this->direction);
  if (dir == 0)
    dir = 3;
  else
    dir--;
  this->direction = static_cast<snake::Direction>(dir);
}

void  snake::SnakePart::goRight()
{
  int dir;

  dir = static_cast<int>(this->direction);
  if (dir == 3)
    dir = 0;
  else
    dir++;
  this->direction = static_cast<snake::Direction>(dir);
}

void  snake::SnakePart::follow(std::unique_ptr<snake::SnakePart> &prev)
{
  size_t  prev_x;
  size_t  prev_y;

  prev_x = prev->x - this->pos[prev->direction].first;
  prev_y = prev->y - this->pos[prev->direction].second;
  if (this->x == prev_x && this->y - 1 == prev_y)
    this->direction = snake::Direction::NORTH;
  else if (this->x + 1 == prev_x && this->y == prev_y)
    this->direction = snake::Direction::EAST;
  else if (this->x == prev_x && this->y + 1 == prev_y)
    this->direction = snake::Direction::SOUTH;
  else
    this->direction = snake::Direction::WEST;
  this->x = prev_x;
  this->y = prev_y;
}

int snake::SnakePart::lead(std::list<std::unique_ptr<SnakePart>> &list,
                           std::unique_ptr<arcade::Map> &map,
                           std::unique_ptr<snake::Food> &food)
{
  size_t  next_x = this->x + this->pos[this->direction].first;
  size_t  next_y = this->y + this->pos[this->direction].second;

  if (map->at(0, next_x, next_y).getTypeEv() == arcade::TileTypeEvolution::BLOCK ||
      (map->at(1, next_x, next_y).getTypeEv() == arcade::TileTypeEvolution::PLAYER &&
       (list.back()->getX() != next_x || list.back()->getY() != next_y)))
    return (-1);
  this->eraseFromMap(list, map);
  this->x += this->pos[this->direction].first;
  this->y += this->pos[this->direction].second;
  for (std::list<std::unique_ptr<snake::SnakePart>>::iterator it = list.begin(); it != list.end(); it++)
    {
      if (it != list.begin())
        it->get()->follow(*std::prev(it, 1));
    }
  if (this->x == food->getX() && this->y == food->getY())
    return (1);
  else
    return (0);
}

int snake::SnakePart::move(std::list<std::unique_ptr<SnakePart>> &list,
                           std::unique_ptr<arcade::Map> &map,
                           std::unique_ptr<snake::Food> &food)
{
  int ret;

  ret = this->lead(list, map, food);
  if (ret == -1)
    {
      this->printOnMap(list, map);
      return (-1);
    }
  if (ret == 1)
    {
      this->addToBack(list);
      this->printOnMap(list, map);
      if (food->beEaten(map) == 1)
        return (2);
    }
  else
    this->printOnMap(list, map);
  return (ret);
}

void  snake::SnakePart::addToBack(std::list<std::unique_ptr<SnakePart>> &list)
{
  list.back()->setPartType(BODY);
  list.push_back(std::make_unique<snake::SnakePart>(list.back()->x - list.back()->pos[list.back()->direction].first,
                                                    list.back()->y - list.back()->pos[list.back()->direction].second,
                                                    snake::PartType::TAIL,
                                                    list.back()->direction));
}
