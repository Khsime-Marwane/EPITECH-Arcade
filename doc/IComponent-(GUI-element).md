The IComponent is an element of the GUI.

## Description

The IComponent describe a GUI element and allow accessing to it's differents properties which are:
- Width and Height
- Position (x and y)
- A color
- An image
- A text

All these values are optionnal, but it's completely useless to create an empty element.

The position and sizes are between 0.0 and 1.0 to allow dynamic positionning, without knowing the size of the display.

## Methods

### Getters
- **`virtual double getX() const`**: X position
- **`virtual double getY() const`**: Y position
- **`virtual double getWidth() const`**: Width
- **`virtual double getHeight() const`**: Height
- **`virtual size_t getBackgroundId() const`**: Id of the background sprite
- **`virtual Color getBackgroundColor() const`**: Color of the element
- **`virtual std::string const &getText() const`**: Text value

### virtual void setClicked()

Allow any graphic lib to tell an element was clicked.