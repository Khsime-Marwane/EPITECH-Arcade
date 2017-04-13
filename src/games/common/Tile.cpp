#include "Tile.hh"

arcade::Tile::Tile()
{
  this->_type = arcade::TileType::EMPTY;
  this->_typeEv = arcade::TileTypeEvolution::EMPTY;
  this->_color = arcade::Color::Black;
  this->_hasSprite = false;
  this->_spriteId = 0;
  this->_spritePos = 0;
  this->_shiftX = 0;
  this->_shiftY = 0;
}

arcade::Tile::Tile(TileType type,
                   TileTypeEvolution typeEv,
                   Color color,
                   bool hasSprite,
                   size_t spriteId,
                   size_t spritePos,
                   double shiftX,
                   double shiftY)
{
  this->_type = type;
  this->_typeEv = typeEv;
  this->_hasSprite = hasSprite;
  this->_color = color;
  this->_spriteId = spriteId;
  this->_spritePos = spritePos;
  this->_shiftX = shiftX;
  this->_shiftY = shiftY;
}

arcade::Tile::~Tile()
{
}

arcade::TileType arcade::Tile::getType() const
{
  return (this->_type);
}

void  arcade::Tile::setType(TileType type)
{
  this->_type = type;
}

arcade::TileTypeEvolution arcade::Tile::getTypeEv() const
{
  return (this->_typeEv);
}

void  arcade::Tile::setTypeEv(TileTypeEvolution typeEv)
{
  this->_typeEv = typeEv;
}

arcade::Color arcade::Tile::getColor() const
{
  return (this->_color);
}

void  arcade::Tile::setColor(union Color color)
{
  this->_color = color;
}

bool  arcade::Tile::hasSprite() const
{
  return (this->_hasSprite);
}

void  arcade::Tile::setHasSprite(bool hasSprite)
{
  this->_hasSprite = hasSprite;
}

size_t  arcade::Tile::getSpriteId() const
{
  return (this->_spriteId);
}

void  arcade::Tile::setSpriteId(size_t spriteId)
{
  this->_spriteId = spriteId;
}

size_t  arcade::Tile::getSpritePos() const
{
  return (this->_spritePos);
}

void  arcade::Tile::setSpritePos(size_t spritePos)
{
  this->_spritePos = spritePos;
}

double  arcade::Tile::getShiftX() const
{
  return (this->_shiftX);
}

void  arcade::Tile::setShiftX(double shiftX)
{
  this->_shiftX = shiftX;
}

double  arcade::Tile::getShiftY() const
{
  return (this->_shiftY);
}

void  arcade::Tile::setShiftY(double shiftY)
{
  this->_shiftY = shiftY;
}

void arcade::Tile::set(arcade::TileType type,
                       arcade::TileTypeEvolution typeEv,
                       arcade::Color color,
                       bool hasSprite,
                       size_t spriteId,
                       size_t spritePos,
                       double shiftX,
                       double shiftY)
{
  this->_type = type;
  this->_typeEv = typeEv;
  this->_color = color;
  this->_hasSprite = hasSprite;
  this->_spriteId = spriteId;
  this->_spritePos = spritePos;
  this->_shiftX = shiftX;
  this->_shiftY = shiftY;
}
