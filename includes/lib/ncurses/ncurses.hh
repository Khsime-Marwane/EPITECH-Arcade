//
// Author: Marwane Khsime 
// Date: 2017-04-08 22:38:11 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-04-08 22:38:11
//


#ifndef CPP_ARCADE_NCURSES_HH
# define CPP_ARCADE_NCURSES_HH

// NCURSES
#include <ncurses.h>
// UTILS
#include <vector>
#include <algorithm>
#include <memory>
#include <sys/poll.h>
// SOUND
#include "SoundManager.hh"
// EVENTS
#include "Event.hh"
#include "ncursesEventsCorrespondence.hpp"
// GAME STATE
#include "GameState.hh"
// IGFX
#include "IGfxLib.hh"

# define START_X    10
# define START_Y    10

namespace arcade
{
    class LibNcurses : public IGfxLib
    {

    private:

        // PROPERTIES
        SCREEN              *_screen;
        size_t              _width;
        size_t              _height;

        // SPRITES
        std::unordered_map<std::size_t, std::vector<char> >   _sprites;

        // SOUND
        SoundManager        _soundManager;

        // Member Functions (For gfx essentially)
        void                drawTileColor(ITile const &tile, std::size_t x, std::size_t y);
        void                drawTileSprite(ITile const &tile, std::size_t x, std::size_t y, std::size_t bgColorSprite);
        void                drawComponent(const IComponent &component);
        void                drawComponentText(const IComponent &component);
        std::size_t         getColorInCurses(const arcade::Color &color);

    public:
        //Constructor / Destructor
        LibNcurses();
        virtual ~LibNcurses();

        // Event
        virtual bool pollEvent(Event &e);

        // Sound
        virtual bool doesSupportSound() const;
        virtual void loadSounds(std::vector<std::pair<std::string, SoundType> > const &sounds);
        virtual void soundControl(const Sound &sound);

        // Graphic
        virtual void loadSprites(std::vector<std::unique_ptr<ISprite> > &&sprites);
        virtual void updateMap(IMap const &map);
        virtual void updateGUI(IGUI &gui);
        virtual void display();
        virtual void clear();
    };
}

#endif //CPP_ARCADE_NCURSES_HH
