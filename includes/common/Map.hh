#ifndef MAP_HH_
# define MAP_HH_

# include <memory>
# include <vector>
# include "IMap.hh"
# include "Tile.hh"

namespace arcade
{
  class   Map : public IMap
  {
    size_t  _width;
    size_t  _height;
    size_t  _layersNb;
    std::vector<std::vector<std::vector<std::unique_ptr<Tile>>>> _layers;
    std::vector<std::vector<bool>> _level;

  public:
    Map(size_t, size_t, size_t, size_t);
    virtual ~Map();

    virtual ITile const &at(size_t layer, size_t x, size_t y) const;
    virtual size_t getLayerNb() const;
    virtual size_t getWidth() const;
    virtual size_t getHeight() const;

    void  createLayer(size_t);
    Tile &at(size_t layer, size_t x, size_t y);
  };
}

#endif
