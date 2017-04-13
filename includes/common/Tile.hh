#ifndef TILE_HH_
# define TILE_HH_

#include "ITile.hh"

namespace arcade
{
  class   Tile : public ITile
  {
    TileType  _type;
    TileTypeEvolution _typeEv;
    Color     _color;
    bool      _hasSprite;
    size_t    _spriteId;
    size_t    _spritePos;
    double    _shiftX;
    double    _shiftY;

  public:
    Tile();
    Tile(TileType, TileTypeEvolution, Color, bool, size_t, size_t, double, double);
    virtual ~Tile();

    TileType getType() const;
    void setType(TileType type);

    TileTypeEvolution getTypeEv() const;
    void setTypeEv(TileTypeEvolution type);

    virtual Color getColor() const;
    void setColor(union Color color);

    virtual bool hasSprite() const;
    void  setHasSprite(bool);

    virtual size_t getSpriteId() const;
    void setSpriteId(size_t id);

    virtual size_t getSpritePos() const;
    void setSpritePos(size_t pos);

    virtual double getShiftX() const;
    void setShiftX(double shift);

    virtual double getShiftY() const;
    void setShiftY(double shift);

    void set(TileType, TileTypeEvolution, Color, bool, size_t, size_t, double, double);
  };
}

#endif /* TILE_HH_ */
