#include "Player.hh"

centipede::Player::Player(arcade::Map &map) : x(20), y(35), map(map)
{
  this->pos[centipede::Direction::NORTH] = std::pair<int, int>(0, -1);
  this->pos[centipede::Direction::EAST] = std::pair<int, int>(1, 0);
  this->pos[centipede::Direction::SOUTH] = std::pair<int, int>(0, 1);
  this->pos[centipede::Direction::WEST] = std::pair<int, int>(-1, 0);
}

centipede::Player::~Player()
{
}

void  centipede::Player::eraseFromMap() const
{
  this->map.at(1, this->x, this->y).set(arcade::TileType::EMPTY,
                                        arcade::TileTypeEvolution::EMPTY,
                                        arcade::Color::Transparent,
                                        false,
                                        0,
                                        0,
                                        0.0,
                                        0.0);
}

void  centipede::Player::printOnMap() const
{
  this->map.at(1, this->x, this->y).set(arcade::TileType::EMPTY,
                                        arcade::TileTypeEvolution::PLAYER,
                                        arcade::Color::Green,
                                        true,
                                        0,
                                        0,
                                        0.0,
                                        0.0);
}

void  centipede::Player::move(centipede::Direction direction)
{
  int  next_x = this->x + this->pos[direction].first;
  int  next_y = this->y + this->pos[direction].second;

  if (next_x < 0 || next_x > 39 || next_y < 0 || next_y > 39 ||
      this->map.at(0, next_x, next_y).getTypeEv() != arcade::TileTypeEvolution::EMPTY)
    return;
  this->eraseFromMap();
  this->x = next_x;
  this->y = next_y;
  this->printOnMap();
}

int centipede::Player::fire(std::vector<std::shared_ptr<centipede::CentipedePart>> &centipedes)
{
  int ret;

  this->shot = std::make_unique<centipede::Shot>(this->x, this->y - 1, this->pos, this->map);
  if ((ret = this->shot->checkCollisions(centipedes)) != 0)
    {
      this->deleteShot();
      return (ret);
    }
  this->shot->printOnMap();
  return (0);
}

void  centipede::Player::deleteShot()
{
  centipede::Shot *shot;

  shot = this->shot.release();
  delete shot;
}

centipede::Shot &centipede::Player::getShot() const
{
  return (*this->shot.get());
}

bool  centipede::Player::hasShot() const
{
  if (this->shot.get() == nullptr)
    return (false);
  else
    return (true);
}
