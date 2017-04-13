#include "Sprite.hh"

arcade::Sprite::Sprite(const std::vector<std::pair<std::string, char>> &sprites) : _sprites(sprites)
{
}

arcade::Sprite::~Sprite()
{
}

std::size_t arcade::Sprite::spritesCount() const
{
  return (this->_sprites.size());
}

std::string arcade::Sprite::getGraphicPath(std::size_t pos) const
{
  return (this->_sprites[pos].first);
}

char  arcade::Sprite::getAscii(std::size_t pos) const
{
  return (this->_sprites[pos].second);
}
