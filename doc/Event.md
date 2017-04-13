The Event structure is used to transmit events in a uniform way between the different libs and the games/core.

## Description

The Event structure is defined as follow:

```c++
struct Event
{
  EventType     type; /// Type of the event
  ActionType    action; /// Action of the event
  union {
    KeyboardKey   kb_key; /// Keyboard key 
    MouseKey      m_key; /// Mouse key
    ControllerKey c_key; /// Controller key
  };
  MousePos	pos_rel; /// Relative position (since last event)
  MousePos	pos_abs; /// Absolute position
};
```

The `EventType` and `ActionType` are two simple enum used to know which value to use among `kb_key`, `m_key`, or `c_key`.

> For more information, don't forget to look at the doxygen documentation on the repository

## Important notes

### Keys

The enumeration to describe the keys in the different graphic libraries are all different. You **have to make ~america great again~ the conversion** between the graphic lib event keys and our common event key enum if you want it to work.

If you are **a bit lazy** and/or doesn't have much time for that, you can make the conversion for the basic keys, like a, b, .. z, 0, 1, .. 9, ctrl, alt, shift, enter, space and some other keys like arrows, etc.

### Mouse

If the mouse is implemented, it must be done in **a very specific way**.

The mouse position values are **not in pixels**, but in **tile unit**. That is to say, if the cursor is in the middle of the tile (6, 9), it's position should be (6.5, 9.5) or something like that. Even if the tile is 12 pixel wide.