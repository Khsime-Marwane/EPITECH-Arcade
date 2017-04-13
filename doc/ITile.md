The ITile interface is used by the Graphic lib to get informations on a specific tile of the map.

## Description

The Tile contain different informations like:
- a type (for the moulinette)
- a type evolution (for the graphic lib)
- a color
- a sprite id
- a sprite pos (the position in the sprite animation, if it's animated)
- a shift on x and y (if x is 2.0, the tile is drawn on the 2nd tile on it's right)

## Methods

### Getters:
- **`TileType getType() const`**: Moulinette type
- **`TileTypeEvolution getTypeEv() const`**: Our type
- **`Color getColor() const`**: Color of the tile
- **`size_t getSpriteId() const`**: Id of the sprite
- **`size_t getSpritePos() const`**: Position of the sprite in it's animation
- **`size_t getShiftX() const`**: Shift on x
- **`size_t getShiftY() const`**: Shift on y