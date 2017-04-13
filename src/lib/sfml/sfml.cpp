//
// Created by maud on 26/03/17.
//

#include <chrono>
#include <thread>
#include <iostream>
#include "Sfml.hh"
 
/*
 * Constructor
 */
arcade::LibSfml::LibSfml() : _width(800), _height(600)
{
    std::cout << "Lib Sfml Launched" << std::endl;

    if (!this->_font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cout << "Warning : couldn't load font" << std::endl;
    }

    _window.create(sf::VideoMode(_width, _height), "Arcade SFML", sf::Style::Close);
}

/*
 * Destructor
 */
arcade::LibSfml::~LibSfml() {}

bool    arcade::LibSfml::pollEvent(arcade::Event &e)
{
    sf::Event           event;


    if (this->_window.pollEvent(event)) {

        arcade::MousePos    current;
        arcade::MousePos    last;

        sf::Vector2i mposition = sf::Mouse::getPosition();

        current.x = mposition.x;
        current.y = mposition.y;

        last.x = event.mouseButton.x;
        last.y = event.mouseButton.y;

        e.pos_rel = last;
        e.pos_abs = current;

        // If we have pressed a key
        if (event.type == sf::Event::KeyPressed) {
            e.action = arcade::ActionType::AT_PRESSED;
            e.type = arcade::EventType::ET_KEYBOARD;

            e.kb_key = (arcade::KeyboardKey)arcade::_sfmlKeyboardKeys.find(event.key.code)->second;    

        } else if (event.type == sf::Event::MouseButtonPressed) {
            e.action = arcade::ActionType::AT_PRESSED;
            e.type = arcade::EventType::ET_MOUSE;

            e.m_key = (arcade::MouseKey)arcade::_sfmlMouseKeys.find(event.mouseButton.button)->second;

        }

        return true;
    }

    return false;
}

void    arcade::LibSfml::updateMap(arcade::IMap const &map)
{

    if (map.getWidth() != 0 && map.getHeight() != 0) {

        // Save Map properties
        size_t  nbLayers = map.getLayerNb();
        size_t  height = map.getHeight();
        size_t  width = map.getWidth();

        // Adjust the ratio between the game map and de window
        _tileWidth = _width / map.getWidth();
        _tileHeight = _height / map.getHeight();

        for (std::size_t layer = 0; layer < nbLayers; layer++) {

                for (std::size_t x = 0; x < width; x++) {

                    for (std::size_t y = 0; y < height; y++) {

                        // Check if the tile is a sprite
                        if (map.at(layer, x, y).hasSprite())
                            drawTileSprite(map.at(layer, x, y), x, y);
                        // If not, get the color
                        else {
                            drawTileColor(map.at(layer, x, y), x, y);
                        }
                    }
                }
        }
    }
}   

void    arcade::LibSfml::drawTileColor(arcade::ITile const &tile, size_t x, size_t y) {

    // Adapt the coordinates for the viewport
    double  x_begin = (x * WIDTH_RATIO);
    double  x_end = (x + 1) * WIDTH_RATIO;
    double  y_begin = (y * HEIGHT_RATIO);
    double  y_end = (y + 1) * HEIGHT_RATIO;

    sf::RectangleShape rectangle(sf::Vector2f(x_end - x_begin, y_end - y_begin));
    rectangle.setPosition(x_begin, y_begin);

    // Set Color
    rectangle.setFillColor(sf::Color((double)tile.getColor().r,
                            (double)tile.getColor().g,
                            (double)tile.getColor().b,
                            (double)tile.getColor().a));

    _window.draw(rectangle);
}

void    arcade::LibSfml::drawTileSprite(arcade::ITile const &tile, size_t x, size_t y) {

    if (this->_sprites.find(tile.getSpriteId()) == this->_sprites.end()) {
        std::cout << "not found for " << "[" << tile.getSpriteId() << "]" << "[" << tile.getSpritePos() << "]" << std::endl;
        return ;
    }

    // Adapt the coordinates for the viewport
    double  x_begin = (x + tile.getShiftX()) * WIDTH_RATIO;
    double  x_end = (x + 1 + tile.getShiftX()) * WIDTH_RATIO;
    double  y_begin = (y + tile.getShiftY()) * HEIGHT_RATIO;
    double  y_end = (y + 1 + tile.getShiftY()) * HEIGHT_RATIO;

    sf::Sprite      sprite;
    sf::Vector2f    pos(x_end - x_begin, y_end - y_begin);

    sprite.setTexture(this->_sprites[tile.getSpriteId()].at(tile.getSpritePos()));
    sprite.setScale(pos.x / sprite.getLocalBounds().width, pos.y / sprite.getLocalBounds().height);
    sprite.setPosition(x_begin, y_begin + tile.getShiftY());

    _window.draw(sprite);
}


void    arcade::LibSfml::updateGUI(arcade::IGUI &GUI)
{
    for (size_t i = 0; i < GUI.size(); i++) {
        this->drawComponent(GUI.at(i));
    }
}

void    arcade::LibSfml::drawComponent(const arcade::IComponent &component) {
    // If component has a sprite
    if (component.hasSprite()) {
        this->drawComponentSprite(component);
    } else { // If component is juste a block of color
        this->drawComponentColor(component);
    }

    this->drawComponentText(component);
}

void    arcade::LibSfml::drawComponentSprite(const arcade::IComponent &component) {

    if (this->_sprites.find(component.getBackgroundId()) == this->_sprites.end()) {
        return ;
    }

    sf::Sprite      sprite;
    sprite.setTexture(this->_sprites[component.getBackgroundId()].at(0));

    sprite.setScale(component.getWidth(), component.getHeight());
    sprite.setPosition(component.getX() * this->_width, component.getY() * this->_height);

    _window.draw(sprite);

}

void    arcade::LibSfml::drawComponentColor(const arcade::IComponent &component) {

    sf::RectangleShape rectangle(sf::Vector2f(component.getWidth(), component.getHeight()));
    rectangle.setPosition(component.getX(), component.getY());

    // Set Color
    arcade::Color color = component.getBackgroundColor();
    rectangle.setFillColor(sf::Color((double)color.r,
                            (double)color.g,
                            (double)color.b,
                            (double)color.a));

    this->_window.draw(rectangle);
}

void    arcade::LibSfml::drawComponentText(const arcade::IComponent &component) {

    sf::Text    text;

    text.setFont(this->_font);

    text.setString(component.getText());
    text.setCharacterSize(14);
    text.setColor(sf::Color::Black);

    text.setPosition(component.getX() + component.getWidth() / 4, component.getY() + component.getHeight() / 4);

    this->_window.draw(text);
}

void    arcade::LibSfml::display()
{
    // ICI
    _window.display();
}

void    arcade::LibSfml::loadSprites(std::vector<std::unique_ptr<arcade::ISprite> > &&sprites)
{
    // Delete old sprites
    this->_sprites.clear();

    // Load news
    for (std::size_t i = 0; i < sprites.size(); i++) {
        for (std::size_t nSprite = 0; nSprite < sprites[i]->spritesCount(); nSprite++) {

            sf::Texture texture;

            if (!texture.loadFromFile(sprites[i]->getGraphicPath(nSprite))) {
                std::cout << "Warning, " << sprites[i]->getGraphicPath(nSprite) << " couldn't be load." << std::endl;
            } else {
                this->_sprites[i].push_back(texture);
            }
        }
    }
}

// Clear Screen
void    arcade::LibSfml::clear()
{
    _window.clear(sf::Color::Black);
}

/*
**  SOUND
*/
bool    arcade::LibSfml::doesSupportSound() const
{ 
    return (true);
}

void    arcade::LibSfml::loadSounds(std::vector<std::pair<std::string, arcade::SoundType>> const &soundsToLoad)
{
    this->_soundManager.loadSounds(soundsToLoad);
}

void    arcade::LibSfml::soundControl(const Sound &soundToControl)
{
    this->_soundManager.soundControl(soundToControl);
}

extern "C" arcade::IGfxLib  *getLib()
{
    return (new arcade::LibSfml());
}
