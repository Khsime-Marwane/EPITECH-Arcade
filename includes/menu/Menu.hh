//
// Created by maud on 23/03/17.
//

#ifndef MENU_HH_
#define MENU_HH_

#include "Map.hh"
#include "GUI.hh"
#include "IGame.hh"
#include "Sprite.hh"
#include "Sound.hh"

namespace arcade
{
    class Menu : public IGame
    {
    protected:
        std::unique_ptr<Map>                          _map;
        std::unique_ptr<GUI>                          _gui;
        GameState                                     _state;
        std::vector<int>                              _soundsToPlay;
        size_t                                        _score;
        std::vector<arcade::Event>                    _events;
        std::array<arcade::Event, 4>                  _eventsBound;
        double                                        _cd;
        double                                        _cdRemaining;
        std::vector<arcade::Sound>                    _sounds;
        int                                           _pos;

    public:
        Menu();
        virtual ~Menu();

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
        int                                 getPos() const;
        void                                setPos(int);
        void                                updateGUI();
    
    };
}

#endif //MENU_HH_
