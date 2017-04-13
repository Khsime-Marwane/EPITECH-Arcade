#include "Shot.hh"

centipede::Shot::Shot(int x,
                      int y,
                      std::map<Direction,std::pair<int, int>> &pos,
                      arcade::Map &map)
  : x(x), y(y), pos(pos), map(map)
{
  this->initialMoveCD = 1;
  this->moveCD = 1;
  this->direction = centipede::Direction::NORTH;
}

centipede::Shot::~Shot()
{
}

void  centipede::Shot::eraseFromMap()
{
  this->map.at(0, this->x, this->y).set(arcade::TileType::EMPTY,
                                        arcade::TileTypeEvolution::EMPTY,
                                        arcade::Color::Transparent,
                                        false,
                                        0,
                                        0,
                                        0.0,
                                        0.0);
}

void  centipede::Shot::printOnMap()
{
  this->map.at(0, this->x, this->y).set(arcade::TileType::EMPTY,
                                        arcade::TileTypeEvolution::SHOT_PLAYER,
                                        arcade::Color::Yellow,
                                        true,
                                        1,
                                        0,
                                        0.0,
                                        0.0);
}
#include <iostream>
int centipede::Shot::move(std::vector<std::shared_ptr<centipede::CentipedePart>> &centipedes)
{
  if (this->moveCD == 0)
    {
      this->moveCD = this->initialMoveCD;
      this->eraseFromMap();
      this->x += this->pos[this->direction].first;
      this->y += this->pos[this->direction].second;
      if (this->x < 0 || this->x > 39 || this->y < 0 || this->y > 39)
        return (-1);
      if (this->x < 0 || this->x > 39 || this->y < 0 || this->y > 39)
        return (-1);
      else if (this->map.at(0, this->x, this->y).getTypeEv() == arcade::TileTypeEvolution::OBSTACLE)
        {
          if (this->map.at(0, this->x, this->y).getSpritePos() == 0)
            this->map.at(0, this->x, this->y).set(arcade::TileType::EMPTY,
                                                  arcade::TileTypeEvolution::EMPTY,
                                                  arcade::Color::Black,
                                                  false,
                                                  0,
                                                  0,
                                                  0.0,
                                                  0.0);
          else
            this->map.at(0, this->x, this->y).setSpritePos(this->map.at(0, this->x, this->y).getSpritePos() - 1);
          return (-1);
        }
      else if (this->map.at(1, this->x, this->y).getTypeEv() == arcade::TileTypeEvolution::ENEMY)
        {
          for (size_t i = 0; i < centipedes.size(); i++)
            {
              if (centipedes[i]->getX() == this->x && centipedes[i]->getY() == this->y)
                return (i);
            }
        }
      this->printOnMap();
    }
  else
    this->moveCD--;
  return (0);
}

int centipede::Shot::checkCollisions(std::vector<std::shared_ptr<centipede::CentipedePart>> &centipedes)
{
  if (this->x < 0 || this->x > 39 || this->y < 0 || this->y > 39)
    {
      this->eraseFromMap();
      return (-1);
    }
  else if (this->map.at(0, this->x, this->y).getTypeEv() == arcade::TileTypeEvolution::OBSTACLE)
    {
      if (this->map.at(0, this->x, this->y).getSpritePos() == 1)
        this->map.at(0, this->x, this->y).set(arcade::TileType::EMPTY,
                                              arcade::TileTypeEvolution::EMPTY,
                                              arcade::Color::Black,
                                              false,
                                              0,
                                              0,
                                              0.0,
                                              0.0);
      else
        this->map.at(0, this->x, this->y).setSpritePos(this->map.at(0, this->x, this->y).getSpritePos() - 1);
      this->eraseFromMap();
      return (-1);
    }
  else if (this->map.at(1, this->x, this->y).getTypeEv() == arcade::TileTypeEvolution::ENEMY)
    {
      for (size_t i = 0; i < centipedes.size(); i++)
        {
          if (centipedes[i]->getX() == this->x && centipedes[i]->getY() == this->y)
            return (i);
        }
    }
  return (0);
}
