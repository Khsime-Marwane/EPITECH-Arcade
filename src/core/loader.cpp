//
// Author: Maud Marel 
// Date: 2017-04-03 10:09:45 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-04-03 10:09:45
//

#include <iostream>
#include <dirent.h>
#include <dlfcn.h>
#include "Loader.hh"
#include "Exceptions.hh"

arcade::Loader::Loader()
:   _libPath {},
    _currentLib(),
    _gamePath {},
    _currentGame()
{
    DIR *dir;
    dirent  *entry;
    std::size_t  pos;

    if ((dir = opendir("lib")) == nullptr)
        throw arcade::Error("Failed to open lib directory");
    while ((entry = readdir(dir)) != nullptr)
    {
        pos = std::string(entry->d_name).find(".so");
        if (pos != std::string::npos)
            _libPath.push_back("lib/" + std::string(entry->d_name));
    }
    closedir(dir);
    if ((dir = opendir("games")) == nullptr)
        throw arcade::Error("Failed to open games directory");
    while ((entry = readdir(dir)) != nullptr)
    {
        pos = std::string(entry->d_name).find(".so");
        if (pos != std::string::npos)
            _gamePath.push_back("games/" + std::string(entry->d_name));
    }
    closedir(dir);
}

arcade::Loader::~Loader()
{
}

arcade::Loader::Loader(const arcade::Loader &copy)
:   _libPath(copy.getLibPath()),
    _currentLib(copy.getCurrentLib()),
    _gamePath(copy.getGamePath()),
    _currentGame(copy.getCurrentGame())
{
}

arcade::Loader  &arcade::Loader::operator=(const arcade::Loader &copy)
{
    (void) copy;
    return (*this);
}

void    arcade::Loader::setCurrentLib(std::string const &lib)
{
    _currentLib = lib;
}

void    arcade::Loader::setCurrentGame(std::string const &game)
{
    _currentGame = game;
}

std::vector<std::string>    arcade::Loader::getLibPath() const
{
    return (_libPath);
}

std::string     arcade::Loader::getCurrentLib() const
{
    return (_currentLib);
}

std::vector<std::string>    arcade::Loader::getGamePath() const
{
    return (_gamePath);
}
 
std::string     arcade::Loader::getCurrentGame() const
{
    return (_currentGame);
}

void    arcade::Loader::getPrevLib()
{
    std::vector<std::string>::const_iterator prev = _libPath.begin();
    int i = 0;
    int present = 0;

     for (std::vector<std::string>::const_iterator it = _libPath.begin(); it != _libPath.end(); it++)
    {
        if (_currentLib == *it && i != 0)
        {
            setCurrentLib(*prev);
            present = 1;
        }
        prev = it;
        i++;
    }
    if (present == 0)
        setCurrentLib(*prev);
}

void    arcade::Loader::getNextLib()
{
   std::vector<std::string>::const_iterator prev = _libPath.begin();
    int i = 0;
    int present = 0;

     for (std::vector<std::string>::const_iterator it = _libPath.end() - 1; it >= _libPath.begin(); it--)
    {
        if (_currentLib == *it && i != 0)
        {
            setCurrentLib(*prev);
            present = 1;
        }
        prev = it;
        i++;
    }
    if (present == 0)
        setCurrentLib(*prev);
}

void    arcade::Loader::getPrevGame()
{
    std::vector<std::string>::const_iterator prev = _gamePath.begin();
    int i = 0;
    int present = 0;

     for (std::vector<std::string>::const_iterator it = _gamePath.begin(); it != _gamePath.end(); it++)
    {
        if (_currentGame == *it && i != 0)
        {
            setCurrentGame(*prev);
            present = 1;
        }
        prev = it;
        i++;
    }
    if (present == 0)
        setCurrentGame(*prev);    
}

void    arcade::Loader::getNextGame()
{
    std::vector<std::string>::const_iterator prev = _gamePath.begin();
    int i = 0;
    int present = 0;

     for (std::vector<std::string>::const_iterator it = _gamePath.end() - 1; it >= _gamePath.begin(); it--)
    {
        if (_currentGame == *it && i != 0)
        {
            setCurrentGame(*prev);
            present = 1;
        }
        prev = it;
        i++;
    }
    if (present == 0)
        setCurrentGame(*prev);    
}

void    *arcade::Loader::getSym(std::string const &lib, std::string const &sym) const
{
    void    *mkr;
    void    *handle;

    if ((handle = dlopen(lib.c_str(), RTLD_NOW)) == NULL)
        throw arcade::Error("dlopen Failed");
    if ((mkr = dlsym(handle, sym.c_str())) == NULL)
        throw arcade::Error("dlsym Failed");
    return (mkr);
}