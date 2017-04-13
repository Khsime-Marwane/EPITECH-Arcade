//
// Created by maud on 26/03/17.
//

#ifndef CPP_ARCADE_SFML_HH
# define CPP_ARCADE_SFML_HH

// SFML
#include <SFML/Graphics.hpp>
// UTILS
#include <vector>
#include <algorithm>
#include <memory>
// SOUND
#include "SoundManager.hh"
// EVENT
#include "Event.hh"
#include "sfmlEventsCorrespondence.hpp"
// GAME STATE
#include "GameState.hh"
// IGFX
#include "IGfxLib.hh"

# define WIDTH_RATIO        _tileWidth
# define HEIGHT_RATIO       _tileHeight

namespace arcade
{
    class LibSfml : public IGfxLib
    {

    private:

        // PROPERTIES
        sf::RenderWindow    _window;
        size_t              _tileWidth;
        size_t              _tileHeight;
        size_t              _width;
        size_t              _height;

        // SPRITES
        std::unordered_map<std::size_t, std::vector<sf::Texture> >   _sprites;

        // SOUND
        SoundManager        _soundManager;

        // FONT
        sf::Font            _font;

        // Member Functions (For gfx essentially)
        void                drawTileColor(ITile const &tile, size_t x, size_t y);
        void                drawTileSprite(ITile const &tile, size_t x, size_t y);
        void                drawComponent(const IComponent &component);
        void                drawComponentSprite(const IComponent &component);
        void                drawComponentColor(const IComponent &component);
        void                drawComponentText(const IComponent &component);

    public:
        //Constructor / Destructor
        LibSfml();
        virtual ~LibSfml();

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

#endif //CPP_ARCADE_SFML_HH
