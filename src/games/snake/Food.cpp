#include "Food.hh"

snake::Food::Food(std::unique_ptr<arcade::Map> &map)
{
  this->placeOnMap(map);
  this->printOnMap(map);
  this->type = snake::FoodType::APPLE;
}

snake::Food::~Food()
{
}

// GETTERS
size_t  snake::Food::getX() const
{
  return (this->x);
}

size_t  snake::Food::getY() const
{
  return (this->y);
}

snake::FoodType  snake::Food::getType() const
{
  return (this->type);
}

void  snake::Food::setX(size_t x)
{
  this->x = x;
}

void  snake::Food::setY(size_t y)
{
  this->y = y;
}

void  snake::Food::setType(snake::FoodType type)
{
  this->type = type;
}

void  snake::Food::eraseFromMap(std::unique_ptr<arcade::Map> &map)
{
  if (map->at(1, this->getX(), this->getY()).getTypeEv() == arcade::TileTypeEvolution::FOOD)
    {
      map->at(1, this->getX(), this->getY()).set(arcade::TileType::EMPTY,
                                                 arcade::TileTypeEvolution::EMPTY,
                                                 arcade::Color::Transparent,
                                                 false,
                                                 0,
                                                 0,
                                                 0.0,
                                                 0.0);
    }
}

void  snake::Food::printOnMap(std::unique_ptr<arcade::Map> &map)
{
  map->at(1, this->getX(), this->getY()).set(arcade::TileType::EMPTY,
                                             arcade::TileTypeEvolution::FOOD,
                                             arcade::Color::Red,
                                             true,
                                             0,
                                             0,
                                             0.0,
                                             0.0);
}

int snake::Food::placeOnMap(std::unique_ptr<arcade::Map> &map)
{
  size_t  nbFree = 0;
  size_t  pos;

  for (size_t y = 0; y < map->getHeight(); y++)
    for (size_t x = 0; x < map->getWidth(); x++)
      if (map->at(0, x, y).getTypeEv() == arcade::TileTypeEvolution::EMPTY &&
          map->at(1, x, y).getTypeEv() == arcade::TileTypeEvolution::EMPTY)
        nbFree++;
  if (nbFree == 0)
    return (1);
  pos = std::rand() % nbFree;
  for (size_t y = 0; y < map->getHeight(); y++)
    for (size_t x = 0; x < map->getWidth(); x++)
      if (map->at(0, x, y).getTypeEv() == arcade::TileTypeEvolution::EMPTY &&
          map->at(1, x, y).getTypeEv() == arcade::TileTypeEvolution::EMPTY)
        {
          if (pos == 0)
            {
              this->x = x;
              this->y = y;
              return (0);
            }
          else
            pos--;
        }
  return (0);
}

int snake::Food::beEaten(std::unique_ptr<arcade::Map> &map)
{
  this->eraseFromMap(map);
  if (this->placeOnMap(map) == 1)
    return (1);
  this->printOnMap(map);
  return (0);
}
