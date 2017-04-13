#ifndef CENTIPEDEPART
# define CENTIPEDEPART

#include "Map.hh"

namespace   centipede
{
  class     CentipedePart
  {
    int                                           x;
    int                                           y;
    int                                           id;
    bool                                          isLeader;
    bool                                          isFollowed;
    arcade::Map                                   &map;
    size_t                                        initialMoveCD;
    size_t                                        moveCD;
    int                                           direction;
    std::shared_ptr<CentipedePart>                follower;

  public:
    CentipedePart(int x,
                  int y,
                  int id,
                  bool isLeader,
                  bool isFollowed,
                  arcade::Map &map,
                  size_t initialMoveCD,
                  int direction);
    ~CentipedePart();

    int  getX() const;
    int  getY() const;
    int  getId() const;

    void  setFollower(std::shared_ptr<CentipedePart> &);
    void  deleteFollower();

    void  die();
    void  printOnMap();
    void  eraseFromMap();
    int   move();
  };
}

#endif
