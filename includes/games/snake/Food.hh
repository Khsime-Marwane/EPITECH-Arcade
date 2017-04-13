#ifndef FOOD_H_
# define FOOD_H_

# include <cstddef>
# include <cstdlib>
# include <ctime>
# include "Map.hh"

namespace   snake
{
  enum    FoodType
    {
      BANANA,
      APPLE,
      BERRY
    };

  class   Food
  {
    size_t  x;
    size_t  y;
    FoodType  type;

  public:
    Food(std::unique_ptr<arcade::Map> &);
    ~Food();
    // GETTERS
    size_t  getX() const;
    size_t  getY() const;
    FoodType  getType() const;

    //SETTERS
    void  setX(size_t);
    void  setY(size_t);
    void  setType(FoodType);

    //ACTIONS
    void  eraseFromMap(std::unique_ptr<arcade::Map> &);
    void  printOnMap(std::unique_ptr<arcade::Map> &);
    int   placeOnMap(std::unique_ptr<arcade::Map> &);
    int   beEaten(std::unique_ptr<arcade::Map> &);
  };
}

#endif
