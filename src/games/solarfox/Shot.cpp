#include "Shot.hh"

sf::Shot::Shot(size_t layer,
               double x,
               double y,
               size_t lifeDuration,
               int direction,
               double moveSpeed,
               mvType mv,
               bool player)
{
  this->layer = layer;
  this->x = x;
  this->y = y;
  this->lifeDuration = lifeDuration;
  this->direction = direction;
  this->moveSpeed = moveSpeed;
  this->mv = mv;
  this->player = player;
}

sf::Shot::~Shot()
{

}

bool    sf::Shot::Collide(sf::Shot &other) const
{
  if (this->mv == other.mv &&
      this->direction == - other.direction &&
      this->player != other.player &&
      ((this->mv == VERTICAL && (this->x == other.x)) ||
       (this->mv == HORIZONTAL && (this->y == other.y))))
    {
      if (this->mv == VERTICAL)
        {
          if (this->y + 1.0 >= other.y && this->y - 1.0 <= other.y)
            return (true);
          else
            return (false);
        }
      else
        {
          if (this->x + 1.0 >= other.x && this->x - 1.0 <= other.x)
            return (true);
          else
            return (false);
        }
    }
  return (false);
}

bool    sf::Shot::destroyPLayer(std::unique_ptr<arcade::Map> &map) const
{
  if (this-> x < 0 || this-> y < 0 || this->x >= 20 || this->y >= 20)
    return (false);
  if (map->at(2, static_cast<int>(this->x), static_cast<int>(this->y)).getTypeEv() == arcade::TileTypeEvolution::PLAYER)
    return (true);
  else
    return (false);
}

void    sf::Shot::printOnMap(std::unique_ptr<arcade::Map> &map) const
{
  if (this-> x < 0 || this-> y < 0 || this->x >= 20 || this->y >= 20)
    return;
  map->at(this->layer, static_cast<size_t>(this->x), static_cast<size_t>(this->y)).
    set(arcade::TileType::EMPTY,
        arcade::TileTypeEvolution::SHOT_ENEMY,
        arcade::Color::Yellow,
        true,
        1,
        static_cast<int>(this->mv),
        this->x - 0.5 - static_cast<double>(static_cast<int>(this->x)),
        this->y - 0.5 - static_cast<double>(static_cast<int>(this->y)));
}

void    sf::Shot::eraseFromMap(std::unique_ptr<arcade::Map> &map) const
{
  if (this-> x < 0 || this-> y < 0 || this->x >= 20 || this->y >= 20)
    return;
  map->at(this->layer, static_cast<size_t>(this->x), static_cast<size_t>(this->y)).
    set(arcade::TileType::EMPTY,
        arcade::TileTypeEvolution::EMPTY,
        arcade::Color::Transparent,
        false,
        0,
        0,
        0.0,
        0.0);
}

int   sf::Shot::move(std::unique_ptr<arcade::Map> &map)
{
  this->eraseFromMap(map);
  if (this-> x < 0 || this-> y < 0 || this->x >= 20 || this->y >= 20)
    return (-1);
  if (this->mv == VERTICAL)
    this->y += this->moveSpeed * static_cast<double>(this->direction);
  else
    this->x += this->moveSpeed * static_cast<double>(this->direction);
  if (this->x < 0 || this->y < 0 || this->x >= 20 || this->y >= 20)
    return (-1);
  if (map->at(1, static_cast<size_t>(this->x), static_cast<size_t>(this->y)).getTypeEv() == arcade::TileTypeEvolution::FOOD && this->player)
    {
      map->at(1, static_cast<size_t>(this->x), static_cast<size_t>(this->y)).
        set(arcade::TileType::EMPTY,
            arcade::TileTypeEvolution::EMPTY,
            arcade::Color::Transparent,
            false,
            0,
            0,
            0.0,
            0.0);
      this->eraseFromMap(map);
      return (1);
    }
  this->lifeDuration--;
  this->printOnMap(map);
  return (0);
}

bool  sf::Shot::isAlive()
{
  return (this->lifeDuration > 0 && this->x >= 0 && this->y >= 0 && this->x < 40 && this->y < 40);
}

double  sf::Shot::getX() const
{
  return (this->x);
}

double  sf::Shot::getY() const
{
  return (this->y);
}
