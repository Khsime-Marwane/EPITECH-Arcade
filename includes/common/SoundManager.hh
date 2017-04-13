//
// Author: Marwane Khsime 
// Date: 2017-04-03 23:05:30 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-04-03 23:05:30
//

#ifndef SOUND_MANAGER_HH
# define SOUND_MANAGER_HH

// UTILS
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
// OPENAL
#include <AL/al.h>
#include <AL/alc.h>
// SNDFILE
#include <sndfile.h>
// SOUND TYPES
#include "Sound.hh"

namespace arcade
{
    class   SoundManager {
        private:
            std::unordered_map<std::size_t, ALuint> _sounds;
            bool                                    _soundSupported;

        public:
            SoundManager();
            ~SoundManager();

            bool    doesSupportSound() const;
            void    soundControl(const Sound &sound);
            void    loadSounds(std::vector<std::pair<std::string, SoundType> > const &soundsToLoad);
    };
}

#endif  // SOUND_MANAGER_HH