The map is what is used to describe the differents elements on the game map, for the game itself and for the graphic library.

## Description

The map is 3 different properties:
- Width
- Height
- Number of layers

The layers are like layers on a photo editing tools. The layer 0 is the bottom one, while the nth is the top one. Every layer is displayed, but the top one's are displayed **over** the bottom ones.

You can use different layers for differentiate the map itself (floor, walls) and dynamic elements (player, shoot, ennemies, etc).

If possible, when displayed in 3D, it's even better to make a different in height, like if it were 3D layers.

## Methods

### Getters

- `size_t getLayerNb() const`: Number of layers
- `size_t getWidth() const`: Width
- `size_t getHeight() const`: Height

### ITile const &at(size_t layer, size_t x, size_t y) const

This method allow to access to a specific tile from a specific layer. The 