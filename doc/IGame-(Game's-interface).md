The game's interface (named IGame) is an interface used to manipulate a game in the Core without knowing which game is currently played.

# Description

The IGame provides method to allow the Core to send and/or request some data or ask the game to do an action (like playing a game loop).

The game must **never communicate directly** with the Core. It must only do something **on demand** from an outside entity.

# Methods

### void notifyEvent(std::vector\<Event\> &&events)

This method allow the Core to send the events get from the lib, like keyboard input, exiting event (clicked on the cross), mouse input, etc.

All the events get between this moment and the last event notification (last game loop), are stored and buffered in the `std::vector<Event>` passed as parameter.

### void notifyNetwork(std::vector\<NetworkPacket\> &&packets)

This method allow the Core to send the network packets get from the Network (if implemented).

All the packets get between this moment and the last network notification (last game loop), are stored and buffered in the `std::vector<NetworkPacket>` passed as parameter.

### std::vector\<NetworkPacket\> &&getNetworkToSend()

This method allow the Core to ask to the game the network packets to send to the server.

### void process()

This method allow the Core to ask to the game to compute a game loop, after having notified the Events and possibly the Network.

### std::vector\<std::string\> getSoundsToLoad() const

This method allow the Core to request the sounds the game would like to use. The method return a `std::vector<string>` containing the list of the sound files to load.

### std::vector\<int\> &&getSoundsToPlay()

This method allow the Core to get the sounds the game would play. It return a `std::vector<int>` containing the indexes of the sound to play.

The index of a sound is the position of it's file in the previous `getSoundsToLoad()` method.

If `getSoundsToLoad()` return a `std::vector<string>` containing `{ "sound0.mp3", "sound1.mp3", "sound2.mp3" }` and the `getSoundsToPlay()` return a `std::vector<int>` containing `{ 2, 0 }`, the game is asking to play `"sound2.mp3"` and `"sound0.mp3"`.

### IMap const &getCurrentMap() const

This method allow the Core to get the current version of the map stored by the game.

### IGUI &getGUI() const

This method allow the Core to get the current GUI the game want to display.
The GUI can be an in-game menu, or a "HUD" (like printing the score, the life, etc)

### GameState getGameState() const

This method return the current game state. If the game is playing, it return `INGAME`, if the players asked the game to quit, it will return `QUIT`, etc. There is also the `MENU` value to go back to the Arcade's main menu.