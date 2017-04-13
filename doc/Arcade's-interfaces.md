The Arcade's Interfaces project is a side-project to achieve the Epitech's 2nd year C++ project "Arcade" in a very modular way.

# The Arcade

## Description

The Arcade project aim to create an "old school arcade" by creating a Core program (the arcade), and loading Games and Graphic lib dynamically, and using theses in an abstracted way.

To achieve this, the Game and Graphic lib must never communicate directly, the communication must always be between the **Game ⇄ Core** and the **Core ⇄ Lib**.

Here is a schema to illustrate that:
![The core communicating with Game and Graphic Lib](http://i.imgur.com/GCybpvS.png)

##

We also have to be compliant with others groups (at least one). To make it possible, we created some interfaces and basic struct and enums to use or games and lib in the same way, without sharing our implementation.

# The Interfaces

## Global operation

All the interfaces available will provide the minimum functionnalities required to make everything work.

> Note: If you want to add a method to an interface, ask yourself "Does this method **REALLY** belong here?". To be honest, in most case the answer is no :D

There are **two main interfaces** which will be `IGame` and `IGfxLib`. As there name can tell, `IGame` will allow everybody to handle a game in a generic way, and the same with `IGfxLib` to handle graphic library.

There will also be a Core program, but for this one, everybody is free on it's implementation, since the `IGame` and `IGfxLib` will be enough to use any game with any lib with any core implementing or using correctly these interfaces.

---
> **Note: All of these interfaces, structs, enums or unions will be located into the "arcade" namespace. (This does not include the dynamic libraries's entry points.)**
---

The Core program must be an executable, and the games and libs must be shared libraries (`*.so` on Unix, `*.dll` on Windows).

For compliance, these shared libraries must implement an unique entry point:

### IGame

For each game, the following function must be available. It will allocate, construct and return the game as a pointer to IGame (since it must implement that interface).

```c++
extern "C" arcade::IGame *getGame();
```

The `extern "C"` **must be used** to avoid **name mangling**.

### IGfxLib

For each graphic lib, the following function must be available. It will allocate, construct and return the library as a pointer to IGfxLib (since it must implement that interface).

```c++
extern "C" arcade::IGfxLib *getLib();
```

For the same reason as before, the `extern "C"` **must be used**.

---
> Note: In fact, your game must implement another entry point, which is the `Play()` function. We will not use it at all in our architecture, so everybody is free on it's implementation.
---

## Details

Some methods provided in the interfaces are "optionnal". This mean you **have to** implement these if you want to compile and don't crash while using someone else's Core, but if you don't want to implement the functionnality, you can make these simply as **empty method**. I repeat, **you have to create those methods** in you implementation, but if they do nothing, it's ok.

### Events

A structure and some enums are provided to use a common event system.
Every single event is get from the lib by the Core, and sent to the game.

### Network

Some network methods are "required" by some interfaces. Those are optionnal. **Careful**, don't forget, if you don't want to have network functionnalities, implement those methods with empty body.

### Sound

Not every lib does support sound, that is why the `IGfxLib` provide a method to know that information. That way, if you want to use another lib for it's sound functionnalities, while using a graphic lib without sound, you can (but you are not forced to, it's only a possibility).

### Sprites

The sprites are usually a little image (with multiple frame or not). Here we have different types of graphic library (ascii, 2D, and possibly 3D). For this, we will create a specific format to allow every lib to load the right sprite format, based on a sigle file.

> **Note: this format is not specified, but it will come very soon**