#ifndef GAME_HH_
# define GAME_HH_

#include <memory>
#include <utility>
#include <map>
#include <functional>
#include <array>
#include <thread>
#include <chrono>
#include "Map.hh"
#include "GUI.hh"
#include "SnakePart.hh"
#include "Food.hh"
#include "IGame.hh"
#include "Sprite.hh"
#include "Sound.hh"

namespace arcade
{
  class   SnakeGame : public IGame
  {
    std::unique_ptr<Map>                          _map;
    std::unique_ptr<GUI>                          _gui;
    GameState                                     _state;
    std::vector<int>                              _soundsToPlay;
    std::list<std::unique_ptr<snake::SnakePart>>  _snake;
    std::unique_ptr<snake::Food>                  _food;
    size_t                                        _eaten;
    size_t                                        _score;
    std::vector<arcade::Event>                    _events;
    std::array<arcade::Event, 4>                  _eventsBound;
    double                                        _cd;
    double                                        _cdRemaining;
    std::vector<arcade::Sound>                    _sounds;

  public:
    SnakeGame(bool mode = true);
    virtual ~SnakeGame();

    virtual GameState                   getGameState() const;
    virtual void                        notifyEvent(std::vector<Event> &&events);
    virtual void                        notifyNetwork(std::vector<NetworkPacket> &&events);
    virtual std::vector<NetworkPacket>  getNetworkToSend();
    virtual void                        process();
    virtual std::vector<std::unique_ptr<ISprite>> getSpritesToLoad() const;
    virtual std::vector<std::pair<std::string, SoundType>> getSoundsToLoad() const;
    virtual std::vector<arcade::Sound>            getSoundsToPlay();
    virtual IMap const                  &getCurrentMap() const;
    virtual IGUI                        &getGUI();
    virtual bool                        hasNetwork() const;

    int                                 getActionToPerform(arcade::Event) const;
    void                       getMap() const;
    void                     getWhereAmI() const;
  };
}

#endif
