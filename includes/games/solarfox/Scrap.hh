#ifndef SCRAP_HH_
# define SCRAP_HH_

# include <cstddef>
# include "Map.hh"

namespace   sf
{
  class     Scrap
  {
    size_t  x;
    size_t  y;

  public:
    Scrap(size_t, size_t);
    ~Scrap();

    size_t  getX() const;
    size_t  getY() const;
    void    printOnMap(std::unique_ptr<arcade::Map> &) const;
    void    eraseFromMap(std::unique_ptr<arcade::Map> &) const;
  };
}

#endif
