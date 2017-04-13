#include "Enemy.hh"

sf::Enemy::Enemy(size_t layer,
                 double x,
                 double y,
                 double firstBoundary,
                 double secondBoundary,
                 int    direction,
                 int    fireDirection,
                 double moveSpeed,
                 mvType mv,
                 size_t ammos_max,
                 size_t ammos,
                 size_t reload_cd,
                 size_t fire_cd)
{
  this->layer = layer;
  this->x = x;
  this->y = y;
  this->firstBoundary = firstBoundary;
  this->secondBoundary = secondBoundary;
  this->direction = direction;
  this->fireDirection = fireDirection;
  this->moveSpeed = moveSpeed;
  this->mv = mv;
  this->ammos_max = ammos_max;
  this->ammos = ammos;
  this->reload_cd = reload_cd;
  this->fire_cd = fire_cd;
  this->rcd = reload_cd;
  this->fcd = 0;
}

sf::Enemy::~Enemy()
{
}

int     sf::Enemy::getAssociatedSpritePos() const
{
  if (this->mv == HORIZONTAL && this->fireDirection == -1)
    return (0);
  else if (this->mv == VERTICAL && this->fireDirection == 1)
    return (1);
  else if (this->mv == HORIZONTAL)
    return (2);
  else
    return (3);

}

void    sf::Enemy::printOnMap(std::unique_ptr<arcade::Map> &map) const
{
  map->at(this->layer, static_cast<size_t>(this->x), static_cast<size_t>(this->y)).
    set(arcade::TileType::EMPTY,
        arcade::TileTypeEvolution::ENEMY,
        arcade::Color::Green,
        true,
        3,
        this->getAssociatedSpritePos(),
        this->x - 0.5 - static_cast<double>(static_cast<int>(this->x)),
        this->y - 0.5 - static_cast<double>(static_cast<int>(this->y)));
}

void    sf::Enemy::eraseFromMap(std::unique_ptr<arcade::Map> &map) const
{
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

bool    sf::Enemy::fire(std::vector<std::unique_ptr<sf::Shot>> &shots)
{
  bool  openFire = false;

  if (this->rcd == 0)
    {
      this->ammos = this->ammos_max;
      this->rcd = this->reload_cd;
      this->fcd = 0;
      openFire = false;
    }
  else if (ammos == 0)
    {
      this->rcd--;
      openFire = false;
    }
  else if (this->fcd == 0)
    {
      this->ammos--;
      this->fcd = this->fire_cd;
      openFire = true;
    }
  else
    {
      this->fcd--;
      openFire = false;
    }
  if (openFire)
    {
      shots.push_back(std::make_unique<sf::Shot>(this->layer,
                                                 this->x,
                                                 this->y,
                                                 500,
                                                 this->fireDirection,
                                                 0.075,
                                                 (this->mv == VERTICAL) ? HORIZONTAL : VERTICAL,
                                                 false));
    }
  return (openFire);
}

void    sf::Enemy::move(std::unique_ptr<arcade::Map> &map)
{
  this->eraseFromMap(map);
  if (this->mv == VERTICAL)
    {
      if (this->y <= this->firstBoundary ||
          this->y >= this->secondBoundary)
        this->direction = -this->direction;
      this->y += this->moveSpeed * static_cast<double>(this->direction);
    }
  else
    {
      if (this->x <= this->firstBoundary ||
          this->x >= this->secondBoundary)
        this->direction = -this->direction;
      this->x += this->moveSpeed * static_cast<double>(this->direction);
    }
  this->printOnMap(map);
}

bool    sf::Enemy::isInRange(std::unique_ptr<sf::Player> &player) const
{
  return ((this->mv == VERTICAL && player->getY() + 2 > this->y && player->getY() - 2 < this->y) ||
          (this->mv == HORIZONTAL && player->getX() + 2 > this->x && player->getX() - 2 < this->x));
}
