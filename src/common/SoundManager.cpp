//
// Author: Marwane Khsime
// Date: 2017-04-03 23:05:27
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-04-03 23:05:27
//

#include "SoundManager.hh"

arcade::SoundManager::SoundManager() : _sounds(), _soundSupported(true) {

    // We suppose that we support sound, if it's not true, we set the value to false

    // Open Device
    ALCdevice* Device = alcOpenDevice(NULL);
    if (Device == nullptr) {
        this->_soundSupported = false;
        std::cerr << "No sound device found" << std::endl;
    }

    // Create Context
    ALCcontext* Context = alcCreateContext(Device, NULL);
    if (Context == nullptr) {
        this->_soundSupported = false;
        std::cerr << "Failed to create context for sound" << std::endl;
    }

    // Active Context
    if (!alcMakeContextCurrent(Context)) {
        this->_soundSupported = false;
        std::cerr << "Failed to active context for sound" << std::endl;
    }
}

arcade::SoundManager::~SoundManager() {
    // Get context and device
    ALCcontext  *Context = alcGetCurrentContext();
    ALCdevice   *Device  = alcGetContextsDevice(Context);

    // Desable context
    alcMakeContextCurrent(NULL);

    // Destroy context
    if (Context) alcDestroyContext(Context);

    // Close device
    if (Device) alcCloseDevice(Device);

    // Delete sources
    for (size_t i = 0; i < this->_sounds.size(); i++) {
        alSourcei(this->_sounds[i], AL_BUFFER, 0);
        alDeleteSources(1, &this->_sounds[i]);
    }

    this->_sounds.clear();
}

bool    arcade::SoundManager::doesSupportSound() const {
    return this->_soundSupported;
}

void    arcade::SoundManager::loadSounds(std::vector<std::pair<std::string, arcade::SoundType> > const &soundsToLoad) {

    // Check if sound is supported
    if (!this->_soundSupported) {
        std::cerr << "Sound is not supported." << std::endl;
        return ;
    }

    // Delete old sounds
    for (size_t i = 0; i < this->_sounds.size(); i++) {
        alSourcei(this->_sounds[i], AL_BUFFER, 0);
        alDeleteSources(1, &this->_sounds[i]);
    }

    // Loop sounds to load
    for (size_t i = 0, x = 0; i < soundsToLoad.size(); i++) {

        // Open audio file with libsndfile
        SF_INFO     FileInfos;
        SNDFILE     *File = sf_open(soundsToLoad[i].first.c_str(), SFM_READ, &FileInfos);

        if (File == nullptr) {
            std::cerr << "Error: failed to load '" + soundsToLoad[i].first + "'." << std::endl;
            continue;
        }

        // Reading the number of samples and the sampling rate (number of samples to be read per second)
        ALsizei NbSamples = static_cast<ALsizei>(FileInfos.channels * FileInfos.frames);
        ALsizei SampleRate = static_cast<ALsizei>(FileInfos.samplerate);

        // Play audio samples in signed 16-bit integer format (the most common)
        std::vector<ALshort>    Samples(NbSamples);
        if (sf_read_short(File, &Samples[0], NbSamples) < NbSamples) {
            continue;
        }

        // Close file
        sf_close(File);

        // Determining the format according to the number of channels
        ALenum Format;
        switch (FileInfos.channels) {
            case 1 :  Format = AL_FORMAT_MONO16;   break;
            case 2 :  Format = AL_FORMAT_STEREO16; break;
            default : return ;
        }

        // Create OpenAL buffer
        ALuint Buffer;

        alGenBuffers(1, &Buffer);

        // Fill with samples read
        alBufferData(Buffer, Format, &Samples[0], NbSamples * sizeof(ALushort), SampleRate);

        // Check errors
        if (alGetError() != AL_NO_ERROR) {
            std::cerr << "Error : An error has occured with file '" + soundsToLoad[i].first + "'" << std::endl;
            continue;
        }

        ALuint  Source;
        alGenSources(1, &Source);
        alSourcei(Source, AL_BUFFER, Buffer);

        // push sound in map
        this->_sounds.insert(std::pair<size_t, ALuint>(x, Source));
        x++;
    }
}

void    arcade::SoundManager::soundControl(const Sound &sound) {

    // Check if sound is supported
    if (!this->_soundSupported) {
        std::cerr << "Sound is not supported." << std::endl;
        return ;
    }

    if (this->_sounds.find(sound.id) != this->_sounds.end()) {
        switch (sound.mode)
        {
            case arcade::SoundAction::UNIQUE:
                alSourcef(this->_sounds[sound.id], AL_GAIN, sound.volume);
                alSourcePlay(this->_sounds[sound.id]);
                break;

            case arcade::SoundAction::REPEAT:
                alSourcef(this->_sounds[sound.id], AL_GAIN, sound.volume);
                alSourcei(this->_sounds[sound.id], AL_LOOPING, AL_TRUE);
                alSourcePlay(this->_sounds[sound.id]);
                break;

            case arcade::SoundAction::VOLUME:
                alSourcef(this->_sounds[sound.id], AL_GAIN, sound.volume);
                break;

            case arcade::SoundAction::PLAY:
                alSourcef(this->_sounds[sound.id], AL_GAIN, sound.volume);
                alSourcePlay(this->_sounds[sound.id]);
                break;

            case arcade::SoundAction::PAUSE:
                alSourcePause(this->_sounds[sound.id]);
                break;

            case arcade::SoundAction::RESUME:
                alSourcef(this->_sounds[sound.id], AL_GAIN, sound.volume);
                alSourcePlay(this->_sounds[sound.id]);
                break;

            case arcade::SoundAction::STOP:
                alSourceStop(this->_sounds[sound.id]);
                break;

            default:
                std::cerr << "Sound : mode not found." << std::endl;
                break;
            }
    } else {
        std::cerr << "Sound not found." << std::endl;
    }
}
