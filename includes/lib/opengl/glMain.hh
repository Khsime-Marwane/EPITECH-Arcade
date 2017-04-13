//
// Author: Marwane Khsime
// Date: 2017-03-27 23:34:59
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-03-27 23:34:59
//

#ifndef GL_MAIN_HPP
# define GL_MAIN_HPP

// GLEW
#include <GL/glew.h>
# define GLEW_STATIC
// GL
#include <GL/gl.h>
// GLFW
#include <GLFW/glfw3.h>
// SYSTEM
#include <sstream>
#include <functional>
#include <exception>
#include <memory>
#include <algorithm>
// SOIL
#include <SOIL/SOIL.h>
// SOUND
#include "SoundManager.hh"
// EVENTS
#include "Event.hh"
#include "glEventsCorrespondence.hpp"
// GAME STATE
#include "GameState.hh"
// IGFX
#include "IGfxLib.hh"

# define WIDTH_RATIO        this->_tileWidth
# define HEIGHT_RATIO       this->_tileHeight

namespace arcade {

    // EVENTS
    static std::vector<arcade::Event> _lastEvents;

    class LibOpenGl : public IGfxLib {

        private:
            // GRAPHIC
            std::size_t                 _tileWidth;
            std::size_t                 _tileHeight;
            std::unordered_map<std::size_t, std::vector<GLuint> >   _sprites;

            // GLFW
            GLFWwindow      *_window;
            const GLuint    _width;
            const GLuint    _height;
            // SOUND
            SoundManager    _soundManager;
            // Member Functions (For gfx essentially)
            void            drawTileColor(ITile const &tile, std::size_t x, std::size_t y, arcade::IMap const &map);
            void            drawTileSprite(ITile const &tile, std::size_t x, std::size_t y, arcade::IMap const &map);
            void            drawComponent(const IComponent &component);
            void            drawComponentSprite(const IComponent &component);
            void            drawComponentColor(const IComponent &component);
            GLuint          loadGLTexture(const std::string &filepath);

        public:

            // Constructor / Destructor
            LibOpenGl();
            virtual ~LibOpenGl();

            // Keyboard Management
            static void     keyCallback(GLFWwindow *, int key, int scancode, int action, int mode);
            static void     mouseCallback(GLFWwindow *,  int button, int action, int mode);

            // Event manager
            virtual bool    pollEvent(Event &);

            // Sound Manager
            virtual bool    doesSupportSound() const;
            virtual void    soundControl(const Sound &soundToControl);
            virtual void    loadSounds(std::vector<std::pair<std::string, SoundType > > const &sounds);

            // Graphic
            virtual void    loadSprites(std::vector<std::unique_ptr<ISprite>> &&sprites);
            virtual void    updateGUI(IGUI &GUI);
            virtual void    updateMap(IMap const &map);
            virtual void    clear();
            virtual void    display();

        };
}

#endif // GL_MAIN_HPP
