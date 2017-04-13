//
// Created by maud on 22/03/17.
//

#include <memory>
#include <iostream>
#include "Menu.hh"

arcade::Menu::Menu() : _map(), _gui(), _state(), _soundsToPlay {}, _score(), _events {}, _eventsBound {}, _cd(), _cdRemaining(), _sounds(), _pos()
{
    this->_gui = std::unique_ptr<GUI>(new GUI());
    _pos = 1;

    std::unique_ptr<Component> comp = std::unique_ptr<Component>(new Component(0.30, 0.02, 1, 1, true, 0, arcade::Color::Blue, arcade::Color::White, "ARCADE"));
    this->_gui->addComponent(std::move(comp));
    std::unique_ptr<Component> comp2 = std::unique_ptr<Component>(new Component(0.40, 0.22, 0.5, 0.5, true, 6, arcade::Color::Blue, arcade::Color::White, "SNAKE"));
    this->_gui->addComponent(std::move(comp2));
    std::unique_ptr<Component> comp3 = std::unique_ptr<Component>(new Component(0.40, 0.37, 0.5, 0.5, true, 2, arcade::Color::Blue, arcade::Color::White, "SOLAR FOX"));
    this->_gui->addComponent(std::move(comp3));
    std::unique_ptr<Component> comp4 = std::unique_ptr<Component>(new Component(0.40, 0.52, 0.5, 0.5, true, 3, arcade::Color::Blue, arcade::Color::White, "CENTIPEDE"));
    this->_gui->addComponent(std::move(comp4));
    std::unique_ptr<Component> comp5 = std::unique_ptr<Component>(new Component(0.40, 0.67, 0.5, 0.5, true, 4, arcade::Color::Blue, arcade::Color::White, "QUIT"));
    this->_gui->addComponent(std::move(comp5));
    std::unique_ptr<Component> comp6 = std::unique_ptr<Component>(new Component(0.20, 0.95, 0.5, 0.5, true, 5, arcade::Color::Blue, arcade::Color::White, "Made By : Khsime Marwane, Marel Maud & Samuel Romain - Epitech"));
    this->_gui->addComponent(std::move(comp6));   
                                           
}

arcade::Menu::~Menu()
{
}

arcade::GameState arcade::Menu::getGameState() const
{
  return (_state);
}

void  arcade::Menu::notifyEvent(std::vector<arcade::Event> &&events)
{
  for (std::vector<arcade::Event>::iterator it = events.begin(); it != events.end(); it++)
    this->_events.push_back(std::move(*it));
}

void  arcade::Menu::notifyNetwork(std::vector<arcade::NetworkPacket> &&)
{
}

std::vector<arcade::NetworkPacket> arcade::Menu::getNetworkToSend()
{
  return (std::move(std::vector<arcade::NetworkPacket>()));
}

int arcade::Menu::getActionToPerform(arcade::Event event) const
{
  for (size_t i = 0; i < 4; i++)
    {
      if (event.type == this->_eventsBound[i].type &&
          event.action == this->_eventsBound[i].action &&
          event.kb_key == this->_eventsBound[i].kb_key)
        return (i);
    }
  return (-1);
}

void  arcade::Menu::process()
{
}

std::vector<std::unique_ptr<arcade::ISprite>> arcade::Menu::getSpritesToLoad() const
{
  std::vector<std::unique_ptr<arcade::ISprite>> vec;

  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/arcade.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/snake.png", ' ')}))));                                                                                                                      
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/solarfox.png", ' ')}))));                                                           
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/centipede.png", ' ')}))));                                                           
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/quit.png", ' ')}))));                                                           
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/author.png", ' ')}))));                                                           
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/snake_select.png", ' ')}))));                                                                                                                      
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/solarfox_select.png", ' ')}))));                                                           
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/centipede_select.png", ' ')}))));                                                           
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/menu/quit_select.png", ' ')}))));                                                                                                                   
  return (vec);
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::Menu::getSoundsToLoad() const
{
  std::vector<std::pair<std::string, SoundType>>  sounds;

  return (sounds);
}

std::vector<arcade::Sound> arcade::Menu::getSoundsToPlay()
{
  return (std::vector<arcade::Sound>());
}

arcade::IMap const &arcade::Menu::getCurrentMap() const
{
  return (*this->_map);
}

arcade::IGUI &arcade::Menu::getGUI()
{
  return (*this->_gui);
}

bool  arcade::Menu::hasNetwork() const
{
  return (true);
}

int arcade::Menu::getPos() const
{
    return (_pos);
}

void    arcade::Menu::setPos(int pos)
{
    if (pos > 4)
        pos = 4;
    else if (pos < 1)
        pos = 1;
    _pos = pos;
}

void    arcade::Menu::updateGUI()
{
     this->_gui = std::unique_ptr<GUI>(new GUI());
    
    switch (_pos)
    {
        case 1 :
        {
            std::unique_ptr<Component> comp = std::unique_ptr<Component>(new Component(0.30, 0.02, 1, 1, true, 0, arcade::Color::Blue, arcade::Color::White, "ARCADE"));
            this->_gui->addComponent(std::move(comp));
            std::unique_ptr<Component> comp2 = std::unique_ptr<Component>(new Component(0.40, 0.22, 0.5, 0.5, true, 6, arcade::Color::Red, arcade::Color::White, "SNAKE"));
            this->_gui->addComponent(std::move(comp2));
            std::unique_ptr<Component> comp3 = std::unique_ptr<Component>(new Component(0.40, 0.37, 0.5, 0.5, true, 2, arcade::Color::Blue, arcade::Color::White, "SOLAR FOX"));
            this->_gui->addComponent(std::move(comp3));
            std::unique_ptr<Component> comp4 = std::unique_ptr<Component>(new Component(0.40, 0.52, 0.5, 0.5, true, 3, arcade::Color::Blue, arcade::Color::White, "CENTIPEDE"));
            this->_gui->addComponent(std::move(comp4));
            std::unique_ptr<Component> comp5 = std::unique_ptr<Component>(new Component(0.40, 0.67, 0.5, 0.5, true, 4, arcade::Color::Blue, arcade::Color::White, "QUIT"));
            this->_gui->addComponent(std::move(comp5));
            std::unique_ptr<Component> comp6 = std::unique_ptr<Component>(new Component(0.20, 0.95, 0.5, 0.5, true, 5, arcade::Color::Blue, arcade::Color::White, "Made By : Khsime Marwane, Marel Maud & Samuel Romain - Epitech"));
            this->_gui->addComponent(std::move(comp6));
            break;
        }
        case 2 :
        {
            std::unique_ptr<Component> comp = std::unique_ptr<Component>(new Component(0.30, 0.02, 1, 1, true, 0, arcade::Color::Blue, arcade::Color::White, "ARCADE"));
            this->_gui->addComponent(std::move(comp));
            std::unique_ptr<Component> comp2 = std::unique_ptr<Component>(new Component(0.40, 0.22, 0.5, 0.5, true, 1, arcade::Color::Blue, arcade::Color::White, "SNAKE"));
            this->_gui->addComponent(std::move(comp2));
            std::unique_ptr<Component> comp3 = std::unique_ptr<Component>(new Component(0.40, 0.37, 0.5, 0.5, true, 7, arcade::Color::Red, arcade::Color::White, "SOLAR FOX"));
            this->_gui->addComponent(std::move(comp3));
            std::unique_ptr<Component> comp4 = std::unique_ptr<Component>(new Component(0.40, 0.52, 0.5, 0.5, true, 3, arcade::Color::Blue, arcade::Color::White, "CENTIPEDE"));
            this->_gui->addComponent(std::move(comp4));
            std::unique_ptr<Component> comp5 = std::unique_ptr<Component>(new Component(0.40, 0.67, 0.5, 0.5, true, 4, arcade::Color::Blue, arcade::Color::White, "QUIT"));
            this->_gui->addComponent(std::move(comp5));
            std::unique_ptr<Component> comp6 = std::unique_ptr<Component>(new Component(0.20, 0.95, 0.5, 0.5, true, 5, arcade::Color::Blue, arcade::Color::White, "Made By : Khsime Marwane, Marel Maud & Samuel Romain - Epitech"));
            this->_gui->addComponent(std::move(comp6)); 
            break;
        }
        case 3 :    
        {
             std::unique_ptr<Component> comp = std::unique_ptr<Component>(new Component(0.30, 0.02, 1, 1, true, 0, arcade::Color::Blue, arcade::Color::White, "ARCADE"));
            this->_gui->addComponent(std::move(comp));
            std::unique_ptr<Component> comp2 = std::unique_ptr<Component>(new Component(0.40, 0.22, 0.5, 0.5, true, 1, arcade::Color::Blue, arcade::Color::White, "SNAKE"));
            this->_gui->addComponent(std::move(comp2));
            std::unique_ptr<Component> comp3 = std::unique_ptr<Component>(new Component(0.40, 0.37, 0.5, 0.5, true, 2, arcade::Color::Blue, arcade::Color::White, "SOLAR FOX²"));
            this->_gui->addComponent(std::move(comp3));
            std::unique_ptr<Component> comp4 = std::unique_ptr<Component>(new Component(0.40, 0.52, 0.5, 0.5, true, 8, arcade::Color::Red, arcade::Color::White, "CENTIPEDE"));
            this->_gui->addComponent(std::move(comp4));
            std::unique_ptr<Component> comp5 = std::unique_ptr<Component>(new Component(0.40, 0.67, 0.5, 0.5, true, 4, arcade::Color::Blue, arcade::Color::White, "QUIT"));
            this->_gui->addComponent(std::move(comp5));
            std::unique_ptr<Component> comp6 = std::unique_ptr<Component>(new Component(0.20, 0.95, 0.5, 0.5, true, 5, arcade::Color::Blue, arcade::Color::White, "Made By : Khsime Marwane, Marel Maud & Samuel Romain - Epitech"));
            this->_gui->addComponent(std::move(comp6));  
            break;
        }
    case 4 :
            {
            std::unique_ptr<Component> comp = std::unique_ptr<Component>(new Component(0.30, 0.02, 1, 1, true, 0, arcade::Color::Blue, arcade::Color::White, "ARCADE"));
            this->_gui->addComponent(std::move(comp));
            std::unique_ptr<Component> comp2 = std::unique_ptr<Component>(new Component(0.40, 0.22, 0.5, 0.5, true, 1, arcade::Color::Blue, arcade::Color::White, "SNAKE"));
            this->_gui->addComponent(std::move(comp2));
            std::unique_ptr<Component> comp3 = std::unique_ptr<Component>(new Component(0.40, 0.37, 0.5, 0.5, true, 2, arcade::Color::Blue, arcade::Color::White, "SOLAR FOX"));
            this->_gui->addComponent(std::move(comp3));
            std::unique_ptr<Component> comp4 = std::unique_ptr<Component>(new Component(0.40, 0.52, 0.5, 0.5, true, 3, arcade::Color::Blue, arcade::Color::White, "CENTIPEDE"));
            this->_gui->addComponent(std::move(comp4));
            std::unique_ptr<Component> comp5 = std::unique_ptr<Component>(new Component(0.40, 0.67, 0.5, 0.5, true, 9, arcade::Color::Red, arcade::Color::White, "QUIT"));
            this->_gui->addComponent(std::move(comp5));
            std::unique_ptr<Component> comp6 = std::unique_ptr<Component>(new Component(0.20, 0.95, 0.5, 0.5, true, 5, arcade::Color::Blue, arcade::Color::White, "Made By : Khsime Marwane, Marel Maud & Samuel Romain - Epitech"));
            this->_gui->addComponent(std::move(comp6)); 
            break;  
            }
        default :
            break;
    }

}
