#ifndef CORE_HH_
# define CORE_HH_

#include <string>
#include <memory>
#include <chrono>
#include <thread>
#include "Loader.hh"
#include "GameState.hh"
#include "IGfxLib.hh"
#include "IGame.hh"
#include "Menu.hh"

namespace arcade
{
    class Core
    {
    private:
        std::string         _lib;
        int                 _volume;
        arcade::GameState   _gameState;
        arcade::Loader      _loader;
        arcade::IGfxLib     *_libLoad;
        arcade::IGame       *_gameLoad;
        arcade::Menu        _menu;

    public:
        Core(const std::string &, const int);
        ~Core();

        Core(Core const &);
        Core    &operator=(Core const &);
        arcade::Loader  getLoader() const;
        int getVolume() const;
        void setVolume(const int);
        arcade::GameState getGameState() const;
        void setGameState(const arcade::GameState);
        void display();
        void menu();
        void play();
        void    loadLib();
        void    loadGame();
        void    getEventGame();
        void    getEventMenu();
    };
}

#endif // !CORE_HH_
