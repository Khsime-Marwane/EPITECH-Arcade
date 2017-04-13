#include "SnakeGame.hh"
#include <iostream>

arcade::SnakeGame::SnakeGame(bool mode)
{
  std::srand(std::time(NULL));
  this->_map = std::unique_ptr<Map>(new Map(20, 20, 2, 0));
  this->_gui = std::unique_ptr<GUI>(new GUI());
  this->_state = arcade::GameState::LOADING;
  this->_snake.push_back(std::make_unique<snake::SnakePart>(9, 9, snake::PartType::HEAD, snake::Direction::WEST));
  this->_snake.push_back(std::make_unique<snake::SnakePart>(10, 9, snake::PartType::BODY, snake::Direction::WEST));
  this->_snake.push_back(std::make_unique<snake::SnakePart>(11, 9, snake::PartType::BODY, snake::Direction::NORTH));
  this->_snake.push_back(std::make_unique<snake::SnakePart>(11, 10, snake::PartType::TAIL, snake::Direction::NORTH));
  this->_snake.front()->printOnMap(this->_snake, this->_map);
  this->_food = std::unique_ptr<snake::Food>(new snake::Food(this->_map));
  this->_eaten = 0;
  this->_score = 0;
  this->_cd = (mode) ? 70 : 0;
  this->_cdRemaining = (mode) ? 70 : 0;

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

arcade::SnakeGame::~SnakeGame()
{
}

arcade::GameState arcade::SnakeGame::getGameState() const
{
  return (_state);
}

void  arcade::SnakeGame::notifyEvent(std::vector<arcade::Event> &&events)
{
  for (std::vector<arcade::Event>::iterator it = events.begin(); it != events.end(); it++)
    this->_events.push_back(std::move(*it));
}

void  arcade::SnakeGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&)
{
}

std::vector<arcade::NetworkPacket> arcade::SnakeGame::getNetworkToSend()
{
  return (std::vector<arcade::NetworkPacket>());
}

int arcade::SnakeGame::getActionToPerform(arcade::Event event) const
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

void  arcade::SnakeGame::process()
{
  int actionNb = -1;
  int ret;

  this->_sounds.clear();
  this->_cdRemaining -= (1.5 + static_cast<double>(this->_eaten) * 0.10);
  if (this->_cdRemaining <= 0)
    {
      this->_cdRemaining = this->_cd;
      if (this->_state != INGAME)
        this->_state = INGAME;
      if (this->_events.size() > 0)
        {
          actionNb = this->getActionToPerform(this->_events.front());
          this->_events.erase(this->_events.begin());
        }
      if (actionNb >= 0 && actionNb < 4)
        this->_snake.front()->setDirection(static_cast<snake::Direction>(actionNb));
      ret = this->_snake.front()->move(this->_snake, this->_map, this->_food);
      if (ret == -1 || ret == 2)
        {
          std::this_thread::sleep_for(std::chrono::milliseconds(1000));
          this->_state = MENU;
        }
      else if (ret == 1)
        {
          this->_sounds.push_back(arcade::Sound(0));
          this->_eaten++;
          this->_score += 100 * this->_eaten;
          this->_gui->getComponent(0).setText("Score : " + std::to_string(this->_score));
        }
    }
}

std::vector<std::unique_ptr<arcade::ISprite>> arcade::SnakeGame::getSpritesToLoad() const
{
  std::vector<std::unique_ptr<arcade::ISprite>> vec;

  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/snake/apple.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/snake/snake_body_horizontal.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_body_vertical.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/snake/snake_corner_1.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_corner_2.png", ' '),
                                                                std::pair<std::string, char>("./resources/games/sprites/snake/snake_corner_3.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_corner_4.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/snake/snake_head_north.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_head_east.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_head_south.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_head_west.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/snake/snake_tail_north.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_tail_east.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_tail_south.png", ' '),
                                                               std::pair<std::string, char>("./resources/games/sprites/snake/snake_tail_west.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/snake/empty.png", ' ')}))));
  vec.push_back(std::unique_ptr<arcade::Sprite>(new Sprite(std::vector<std::pair<std::string, char>>
                                                           ({std::pair<std::string, char>("./resources/games/sprites/snake/wall.png", ' ')}))));
  return (vec);
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::SnakeGame::getSoundsToLoad() const
{
  std::vector<std::pair<std::string, SoundType>>  sounds;

  sounds.push_back(std::pair<std::string, SoundType>("./resources/games/sounds/snake/snake_eat.ogg", SoundType::SOUND));
  return (sounds);
}

std::vector<arcade::Sound> arcade::SnakeGame::getSoundsToPlay()
{
  return (_sounds);
}

arcade::IMap const &arcade::SnakeGame::getCurrentMap() const
{
  return (*this->_map);
}

arcade::IGUI &arcade::SnakeGame::getGUI()
{
  return (*this->_gui);
}

bool        arcade::SnakeGame::hasNetwork() const
{
  return (true);
}

void arcade::SnakeGame::getMap() const
{
  struct  arcade::GetMap  gm;
  size_t  i = 0;

  gm.type = arcade::CommandType::GET_MAP;
  gm.width = 20;
  gm.height = 20;
  std::cout.write(reinterpret_cast<char *>(&gm), sizeof(arcade::GetMap));
  TileType *tiles = new TileType[400];
  for (uint16_t y = 0; y < 20; y++)
    {
      for (uint16_t x = 0; x < 20; x++)
        {
          if (this->_map->at(1, x, y).getType() != arcade::TileType::EMPTY)
            tiles[i] = this->_map->at(1, x, y).getType();
          else
            tiles[i] = this->_map->at(0, x, y).getType();
          i++;
        }
    }
  std::cout.write(reinterpret_cast<char *>(tiles), sizeof(TileType) * 400);
  delete []tiles;
}

void arcade::SnakeGame::getWhereAmI() const
{
  struct WhereAmI wai;

  wai.type = arcade::CommandType::WHERE_AM_I;
  wai.lenght = this->_snake.size();
  std::cout.write(reinterpret_cast<char *>(&wai), sizeof(arcade::WhereAmI));
  Position *positions = new Position[wai.lenght];
  for (std::list<std::unique_ptr<snake::SnakePart>>::const_iterator it = this->_snake.begin();
       it != this->_snake.end();
       it++)
    {
      positions[std::distance(this->_snake.begin(), it)].x = it->get()->getX();
      positions[std::distance(this->_snake.begin(), it)].y = it->get()->getY();
    }
  std::cout.write(reinterpret_cast<char *>(positions), sizeof(Position) * wai.lenght);
  delete []positions;
}

extern "C" arcade::IGame *getGame()
{
  return (new arcade::SnakeGame());
}

extern  "C" void  Play(void)
{
  std::unique_ptr<arcade::SnakeGame> snake = std::make_unique<arcade::SnakeGame>(0);
  arcade::CommandType command;

  while (std::cin.read(reinterpret_cast<char*>(&command), sizeof(arcade::CommandType)))
  {
    switch (command)
    {
      case arcade::CommandType::WHERE_AM_I :
        {
          snake->getWhereAmI();
          break;
        }
      case arcade::CommandType::GET_MAP :
        {
          snake->getMap();
          break;
        }
      case arcade::CommandType::GO_UP :
        {
          arcade::Event event;
          std::vector<arcade::Event> events;

          event.type = arcade::EventType::ET_KEYBOARD;
          event.action = arcade::ActionType::AT_PRESSED;
          event.kb_key = arcade::KeyboardKey::KB_ARROW_UP;
          events.push_back(event);
          snake->notifyEvent(std::move(events));
          break;
        }
      case arcade::CommandType::GO_DOWN :
        {
          arcade::Event event;
          std::vector<arcade::Event> events;

          event.type = arcade::EventType::ET_KEYBOARD;
          event.action = arcade::ActionType::AT_PRESSED;
          event.kb_key = arcade::KeyboardKey::KB_ARROW_DOWN;
          events.push_back(event);
          snake->notifyEvent(std::move(events));
          break;
        }
      case arcade::CommandType::GO_LEFT :
        {
          arcade::Event event;
          std::vector<arcade::Event> events;

          event.type = arcade::EventType::ET_KEYBOARD;
          event.action = arcade::ActionType::AT_PRESSED;
          event.kb_key = arcade::KeyboardKey::KB_ARROW_LEFT;
          events.push_back(event);
          snake->notifyEvent(std::move(events));
          break;
        }
      case arcade::CommandType::GO_RIGHT :
        {
          arcade::Event event;
          std::vector<arcade::Event> events;

          event.type = arcade::EventType::ET_KEYBOARD;
          event.action = arcade::ActionType::AT_PRESSED;
          event.kb_key = arcade::KeyboardKey::KB_ARROW_RIGHT;
          events.push_back(event);
          snake->notifyEvent(std::move(events));
          break;
        }
      case arcade::CommandType::GO_FORWARD :
        {
          break;
        }
      case arcade::CommandType::SHOOT :
        {
          break;
        }
      case arcade::CommandType::ILLEGAL :
        {
          break;
        }
      case arcade::CommandType::PLAY :
        {
          snake->process();
          break;
        }
        default:
          break;
    }
  }
}
