#ifndef GAME_HH_
# define GAME_HH_

#include <memory>
#include <utility>
#include <map>
#include <functional>
#include <array>
#include "Map.hh"
#include "GUI.hh"
#include "Scrap.hh"
#include "Player.hh"
#include "Enemy.hh"
#include "Shot.hh"
#include "IGame.hh"
#include "Sprite.hh"

namespace arcade
{
  class   SfGame : public IGame
  {
    std::unique_ptr<Map>                          _map;
    std::unique_ptr<GUI>                          _gui;
    GameState                                     _state;
    std::unique_ptr<sf::Player>                   _player;
    std::vector<std::unique_ptr<sf::Enemy>>       _enemies;
    std::vector<std::unique_ptr<sf::Shot>>        _shots;
    size_t                                        _score;
    std::vector<arcade::Event>                    _events;
    std::array<arcade::Event, 5>                  _eventsBound;
    size_t                                        _initialInputCD;
    size_t                                        _inputCD;
    size_t                                        _remainingScrap;
    std::vector<arcade::Sound>                    _sounds;

  public:
    SfGame();
    virtual ~SfGame();

    virtual GameState                   getGameState() const;
    virtual void                        notifyEvent(std::vector<Event> &&events);
    virtual void                        notifyNetwork(std::vector<NetworkPacket> &&events);
    virtual std::vector<NetworkPacket>  getNetworkToSend();
    virtual void                        process();
    virtual std::vector<std::unique_ptr<ISprite>> getSpritesToLoad() const;
    virtual std::vector<std::pair<std::string, SoundType>> getSoundsToLoad() const;
    virtual std::vector<arcade::Sound>  getSoundsToPlay();
    virtual bool                        hasNetwork() const;
    virtual IMap const                  &getCurrentMap() const;
    virtual IGUI                        &getGUI();

    Map                                 &getMap();
    int                                 getActionToPerform(arcade::Event) const;
    void                                checkShots(std::unique_ptr<arcade::Map> &);
    void                                setLevel(size_t lvl);
  };
}

#endif
