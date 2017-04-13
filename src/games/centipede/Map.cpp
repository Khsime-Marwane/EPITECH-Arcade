#include "Map.hh"

arcade::Map::Map(size_t width, size_t height, size_t lnb, size_t)
{
  this->_width = width;
  this->_height = height;
  this->_layersNb = lnb;

  this->createLayer(0);
  this->createLayer(1);
}

arcade::Map::~Map()
{
}

arcade::ITile const &arcade::Map::at(size_t layer, size_t x, size_t y) const
{
  return (*this->_layers[layer][y][x]);
}

arcade::Tile &arcade::Map::at(size_t layer, size_t x, size_t y)
{
  return (*this->_layers[layer][y][x]);
}

size_t  arcade::Map::getLayerNb() const
{
  return (this->_layersNb);
}

size_t  arcade::Map::getWidth() const
{
  return (this->_width);
}

size_t  arcade::Map::getHeight() const
{
  return (this->_height);
}

void arcade::Map::createLayer(size_t layer)
{
  this->_layers.push_back(std::vector<std::vector<std::unique_ptr<Tile>>>());
  for (size_t y = 0; y < this->_height; y++)
    {
      this->_layers[layer].push_back(std::vector<std::unique_ptr<arcade::Tile>>());
      for (size_t x = 0; x < this->_width; x++)
        {
          if (layer == 0)
            {
              if (y < this->_height - 8 && rand() % 20 == 0 && (y != 0 || x != 20))
                this->_layers[layer][y].push_back(std::make_unique<arcade::Tile>(arcade::TileType::OBSTACLE,
                                                                                 arcade::TileTypeEvolution::OBSTACLE,
                                                                                 arcade::Color::White,
                                                                                 true,
                                                                                 4,
                                                                                 3,
                                                                                 0.0,
                                                                                 0.0));
              else
                this->_layers[layer][y].push_back(std::make_unique<arcade::Tile>((y < this->_height - 8) ? arcade::TileType::BLOCK : arcade::TileType::EMPTY,
                                                                                 (y < this->_height - 8) ? arcade::TileTypeEvolution::BLOCK : arcade::TileTypeEvolution::EMPTY,
                                                                                 arcade::Color::Black,
                                                                                 false,
                                                                                 0,
                                                                                 0,
                                                                                 0.0,
                                                                                 0.0));
            }
          else
            this->_layers[layer][y].push_back(std::make_unique<arcade::Tile>(arcade::TileType::EMPTY,
                                                                             arcade::TileTypeEvolution::EMPTY,
                                                                             arcade::Color::Transparent,
                                                                             false,
                                                                             0,
                                                                             0,
                                                                             0.0,
                                                                             0.0));
        }
    }
}
