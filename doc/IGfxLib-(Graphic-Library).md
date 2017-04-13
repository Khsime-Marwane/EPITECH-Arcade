The graphic library's interface (named IGfxLib) is an interface used to manipulate a graphic library in the Core without knowing which library is currently used to display game and GUI.

# Description

The IGfxLib provides method to allow the Core to send and/or request some data or ask the lib to do an action (like updating the displayed map).

The lib must **never communicate directly** with the Core. It must only do something **on demand** from an outside entity.

# Methods

### bool pollEvent(Event &e)

This method allow the Core to get events from the lib, like keyboard or mouse input event, or exiting signal (user clicked on the cross), etc.

If there is an event waiting, `pollEvent` return `true` and `e` is filled with the good data. Else it return `false`.

Example:
```c++
Event e;

while (lib->pollEvent(e))
{
    // Process event here...
}
```

### bool doesSupportSound() const

This method allow the Core to ask to the lib if it does support sound. This allow the Core to possibly use another lib to manage sound.

### void loadSounds(std::vector<<std::string>> const &sounds)

This method allow the core to load sounds (if supported) in the lib. The parameter `sounds` is a `std::vector<std::string>` which contains the list of all the sound file to load.

```c++
std::vector<std::string> soundsToLoad = { "lazer.mp3", "footstep.mp3", "death.mp3", "music.mp3" };

lib->loadSounds(soundsToLoad);
```

> Note: using this method should erase all previously loaded sound

### void playSound(Sound s)

```c++
struct Sound
{
    enum SoundMode
    {
        UNIQUE,
        REPEAT
    };

    Sound(int id, SoundMode mode);

    int id;
    SoundMode mode;
};
```

This method allow the core to ask to the lib to play a sound by giving it's id as parameter.

The index of a sound is the position of it's file in the given parameter in the previous loadSounds() method.

If `loadSounds()` receive a `std::vector<string>` containing `{ "sound0.mp3", "sound1.mp3", "sound2.mp3" }` and the `playSound()` receive `1`, the lib should play "sound1.mp3".

```c++
std::vector<std::string> soundsToLoad = { "lazer.mp3", "footstep.mp3", "death.mp3", "music.mp3" };
std::vector<Sound> sounds;

lib->loadSounds(soundsToLoad);

sounds->emplace_back(2); // 2 is the id of "death.mp3"
sounds->emplace_back(3, Sound::SoundMode::REPEAT);

for (Sound const &s : sounds)
    lib->play(s);
```

### void updateMap(IMap const &map)

This method allow the Core to update the "graphic version" of the map (it can be an array containing all the character to display, or a texture containing a rendering of the current map, etc).

You should always avoid storing a pointer directly on the map to render it later in the `display()` method, and this to avoid dangling pointer.

### void updateGUI(IGUI &gui)

This method allow the Core to update the "graphic version" of the GUI (it can be an array containing all the character to display, or a texture containing a rendering of the current GUI, etc).

You should always avoid storing a pointer directly on the GUI to render later it in the `display()` method, and this to avoid dangling pointer.

### void display()

This method allow the Core to ask to the lib for a full render on the screen of the current informations stored in the lib.

In most cases, it should be done after updating the map with `updateMap()` or updating the GUI with `updateGUI()`.