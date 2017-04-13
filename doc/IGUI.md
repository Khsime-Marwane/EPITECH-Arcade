The IGUI interface is used to manipulate a the GUIs (Graphical User Interface) which constitute the menus and the ingame interface.

## Description

The GUI is in fact a set of differents components with a width, a height, and a position in x and y. It can also contains a color, an image, and a text value.

The IGUI provide methods to access those elements only.

## Methods

### virtual size_t size() const

Return the number of components in the GUI

### virtual IComponent &at(size_t n)

Allow the graphic lib to access to the nth element, and modify it (by making it clicked).