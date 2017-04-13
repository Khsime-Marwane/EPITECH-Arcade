#include "CentipedeGame.hh"
#include <ctime>
#include <cstdlib>
#include <iostream>

arcade::CentipedeGame::CentipedeGame()
{
  srand(time(NULL));
  this->_map = std::unique_ptr<Map>(new Map(40, 40, 2, 0));
  this->_gui = std::unique_ptr<GUI>(new GUI());
  this->_state = arcade::GameState::LOADING;
  this->_score = 0;
  this->_initialInputCD = 5;
  this->_inputCD = 0;
  this->_initialCentipedeCD = 1000;
  this->_centipedeCD = 0;
  this->_player = std::make_unique<centipede::Player>(*this->_map);
  this->_player->printOnMap();
  this->_killed = 0;
  this->_timer = 0;

  // EVENTS
  arcade::Event event;
  event.type = arcade::EventType::ET_KEYBOARD;
  event.action = arcade::ActionType::AT_PRESSED;
  event.kb_key = arcade::KeyboardKey::KB_ARROW_UP;
  this->_eventsBound[0] = event;
  event.kb_key = arcade::KeyboardKey::KB_ARROW_RIGHT;
  this->_eventsBound[1] = event;
  event.kb_key = arcade::KeyboardKey::KB_ARROW_DOWN;
  this->_eventsBound[2] = event;
  event.kb_key = arcade::KeyboardKey::KB_ARROW_LEFT;
  this->_eventsBound[3] = event;
  event.kb_key = arcade::KeyboardKey::KB_SPACE;
  this->_eventsBound[4] = event;

  // GUI
  std::unique_ptr<Component> comp = std::unique_ptr<Component>(new Component(0,
                                                                             0,
                                                                             1,
                                                                             0.1,
                                                                             false,
                                                                             0,
                                                                             arcade::Color::Black,
                                                                             arcade::Color::White,
                                                                             "Score : 0"));
  this->_gui->addComponent(std::move(comp));
}

arcade::CentipedeGame::~CentipedeGame()
{
}

arcade::GameState arcade::CentipedeGame::getGameState() const
{
  return (_state);
}

void  arcade::CentipedeGame::notifyEvent(std::vector<arcade::Event> &&events)
{
  for (std::vector<arcade::Event>::iterator it = events.begin(); it != events.end(); it++)
    this->_events.push_back(std::move(*it));
}

void  arcade::CentipedeGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&)
{
}

std::vector<arcade::NetworkPacket> arcade::CentipedeGame::getNetworkToSend()
{
  return (std::move(std::vector<arcade::NetworkPacket>()));
}

int arcade::CentipedeGame::getActionToPerform(arcade::Event event) const
{
  for (size_t i = 0; i < 5; i++)
    {
      if (event.type == this->_eventsBound[i].type &&
          event.action == this->_eventsBound[i].action &&
          event.kb_key == this->_eventsBound[i].kb_key)
        return (i);
    }
  return (-1);
}

void  arcade::CentipedeGame::createCentipede(size_t nb)
{
  static int  id = 0;
  int direction = (rand() % 2 == 0) ? -1 : 1;

  for (size_t i = 0; i < nb; i++)
    {
      this->_centipedes.push_back(std::make_shared<centipede::CentipedePart>(20,
                                                                             -i,
                                                                             id,
                                                                             i == 0,
                                                                             i == nb - 1,
                                                                             *this->_map,
                                                                             10,
                                                                             direction));
      this->_centipedes.back()->printOnMap();
      if (i != 0)
        {
          this->_centipedes[this->_centipedes.size() - 2]
            ->setFollower(this->_centipedes[this->_centipedes.size() - 1]);
        }
    }
  id++;
}

void  arcade::CentipedeGame::killCentipede(int ret)
{
  bool  wasLast = true;

  this->_player->deleteShot();
  if (ret > 0)
    {
      this->_centipedes[ret]->die();
      if (static_cast<size_t>(ret + 1) < this->_centipedes.size() && this->_centipedes[ret]->getId() == this->_centipedes[ret + 1]->getId())
        wasLast = false;
      else if (ret > 0 && this->_centipedes[ret]->getId() == this->_centipedes[ret - 1]->getId())
        wasLast = false;
      this->_score += 600;
      this->_gui->getComponent(0).setText("Score : " + std::to_string(this->_score));
      if (wasLast == true)
        this->_killed++;
      this->_centipedes.erase(this->_centipedes.begin() + ret);
    }
}

void  arcade::CentipedeGame::process()
{
  int actionNb = -1;
  int ret;
  bool  moveShot = true;

  if (this->_state == MENU)
    return;
  if (this->_state != INGAME)
    this->_state = INGAME;
  if (this->_events.size() > 0)
    {
      if (this->_inputCD == 0)
        {
          actionNb = this->getActionToPerform(this->_events.front());
          this->_events.clear();
          this->_inputCD = this->_initialInputCD;
          if (actionNb >= 0 && actionNb < 4)
            this->_player->move(static_cast<centipede::Direction>(actionNb));
          else if (actionNb == 4)
            if (this->_player->hasShot() == false)
              {
                moveShot = false;
                if ((ret = this->_player->fire(this->_centipedes)) != 0)
                  this->killCentipede(ret);
              }
        }
    }
  if (this->_player->hasShot() && moveShot == true && this->_timer % 2 == 0)
    if ((ret = this->_player->getShot().move(this->_centipedes)) != 0)
      this->killCentipede(ret);
  if (this->_killed == 10)
    this->_state = QUIT;
  if (this->_timer % 15 == 0)
    {
      for (size_t i = 0; i < this->_centipedes.size(); i++)
        {
          ret = this->_centipedes[i]->move();
          if (ret == -1)
            {
              this->_state = MENU;
              return;
            }
          else if (ret == 1)
            {
              this->_score -= 200;
              this->_gui->getComponent(0).setText("Score : " + std::to_string(this->_score));
              this->_centipedes.erase(this->_centipedes.begin() + i);
            }
        }
    }
  this->_timer++;
  if (this->_centipedeCD == 0)
    {
      this->_initialCentipedeCD *= 0.95;
      this->createCentipede(rand() % 4 + 3);
      this->_centipedeCD = this->_initialCentipedeCD;
    }
  else
    this->_centipedeCD--;
  if (this->_inputCD != 0)
    this->_inputCD--;
}

std::vector<std::unique_ptr<arcade::ISprite>> arcade::CentipedeGame::getSpritesToLoad() const
{
  std::vector<std::unique_ptr<arcade::ISprite>> vec;

  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/centipede/player.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/centipede/shot.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/centipede/body_east.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/centipede/body_west.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/centipede/head_east.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/centipede/head_west.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/centipede/obstacle_1.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/centipede/obstacle_2.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/centipede/obstacle_3.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/centipede/obstacle_4.png", ' ')}))));
  return (vec);
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::CentipedeGame::getSoundsToLoad() const
{
  std::vector<std::pair<std::string, SoundType>>  sounds;

  return (sounds);
}

std::vector<arcade::Sound> arcade::CentipedeGame::getSoundsToPlay()
{
  return (std::vector<arcade::Sound>());
}

arcade::IMap const &arcade::CentipedeGame::getCurrentMap() const
{
  return (*this->_map);
}

arcade::IGUI &arcade::CentipedeGame::getGUI()
{
  return (*this->_gui);
}

bool  arcade::CentipedeGame::hasNetwork() const
{
  return (true);
}

extern "C" arcade::IGame *getGame()
{
  return (new arcade::CentipedeGame());
}
