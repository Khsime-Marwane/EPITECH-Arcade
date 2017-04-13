//
// Author: Maud Marel 
// Date: 2017-04-03 10:10:55 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-04-03 10:10:55
//

#ifndef LOADER_HH_
# define LOADER_HH_

#include <vector>
#include <string>

namespace arcade
{
    class Loader
    {
    public:
        static Loader   &getInstance()
        {
            static Loader  instance;
            return instance;
        }
    protected:
        std::vector<std::string>    _libPath;
        std::string                     _currentLib;
        std::vector<std::string>    _gamePath;
        std::string                     _currentGame;
        
    public:
        Loader();
        virtual ~Loader();
        Loader(const arcade::Loader &);
        Loader &operator=(const arcade::Loader &);

        void                        setCurrentLib(std::string const &);
        void    setCurrentGame(std::string const &);
        std::vector<std::string> getLibPath() const;
        std::string                 getCurrentLib() const;
        std::vector<std::string> getGamePath() const;
        std::string                 getCurrentGame() const;
        void    getPrevLib();
        void    getNextLib();
        void    getPrevGame();
        void    getNextGame();
        void                        *getSym(std::string const &, std::string const &) const;
    };
}

#endif /* !LOADER_HH_ */