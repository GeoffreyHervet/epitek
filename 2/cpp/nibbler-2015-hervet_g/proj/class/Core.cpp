#include <iostream>
#include <vector>
#include <algorithm>

#include "Core.h"

namespace	Nibbler
{
  Core::Core(std::vector<std::vector <bool> > map, unsigned char width, unsigned char height, IGraphic *window)
    : _play(true),
      _pause(false),
      _height(height),
      _width(width),
      _window(window),
      _usleepTime(USLEEP_DEFAULT),
      _speedSlow(SPEED_SLOW)
  {
    tFood	tmp;

    srand(time(NULL));
    _food.push_back(tmp);
    this->_functions[MV_LEFT] =  &Core::moveLeft;
    this->_functions[MV_RIGHT] = &Core::moveRight;
    this->_functions[MV_UP] =    &Core::moveUp;
    this->_functions[MV_DOWN] =  &Core::moveDown;
    if (map.empty())
      this->initMap();
    else
      this->_map = map;
    if (false == this->initSnake())
      throw Error(ERR_MAP_SIZE);
    this->createFood();
  }

  Core::~Core()
  {
  }

  bool			Core::initSnake(void)
  {
    /* If the map is too small */
    if (this->_width <= SNAKE_LENGTH_DEFAULT || this->_height <= SNAKE_LENGTH_DEFAULT)
      return false;

    /* Initalize _snake with the default length */
    this->_snake = std::deque<std::pair<unsigned char, unsigned char> >(SNAKE_LENGTH_DEFAULT);

    unsigned char	idx = SNAKE_LENGTH_DEFAULT / 2;
    unsigned char	idx2;

    if (this->_width >= this->_height)
    {
      idx += this->_width / 2;
      idx2 = this->_height / 2;
      this->_direction = MV_RIGHT;
    }
    else
    {
      idx += this->_height / 2;
      idx2 = this->_width / 2;
      this->_direction = MV_DOWN;
    }

    for (std::deque<std::pair<unsigned char, unsigned char> >::iterator it = this->_snake.begin(); it != this->_snake.end(); ++it)
    {
      if (this->_width >= this->_height)
      {
        this->_map[idx2][idx] = false;
        (*it) = std::pair<unsigned char, unsigned char>(idx++, idx2);
      }
      else
      {
        this->_map[idx][idx2] = false;
        (*it) = std::pair<unsigned char, unsigned char>(idx2, idx++);
      }
    }
    std::reverse(this->_snake.begin(), this->_snake.end());
    return true;
  }

  void			Core::initMap(void)
  {
    this->_map = std::vector<std::vector <bool> >(this->_height);
    for (std::vector<std::vector<bool> >::iterator it = this->_map.begin();
        it != this->_map.end();
        ++it)
      (*it) = std::vector<bool>(this->_width, false);
    for (unsigned char y = 0; y < this->_height; y++)
      for (unsigned char x = 0; x < this->_width; x++)
      {
        this->_map[y][0] = true;
        this->_map[0][x] = true;
        this->_map[this->_height - 1][x] = true;
        this->_map[y][this->_width - 1] = true;
      }
  }

  void			Core::event(eEvent evt)
  {
    if (evt == EXIT)
      this->_play = false;
    else if (evt == PAUSE)
      this->_pause = !this->_pause;
    if (!this->_pause)
    {
      if (evt == UNKNOWN)
        evt = this->_direction;
      if (this->_functions[evt])
        (this->*_functions[evt])(evt);
    }
  }

  void			Core::run(void)
  {
    eEvent		tmp;
    unsigned char	x = 1;
    unsigned char	y = 1;

    this->_play = this->_window->displayMap(this->_map);
    if (!this->_window->displayFood(this->_food))
      return ;
    while (this->_play)
    {
      if (!this->_window->reset_queue(x, y))
        return ;
      if (!this->_window->displaySnake(this->_snake, this->_direction))
        return ;
      this->_play = this->_window->displayScore(_snake.size() - SNAKE_LENGTH_DEFAULT);
      x = _snake[_snake.size() - 1].first;
      y = _snake[_snake.size() - 1].second;
      tmp = this->_window->getEvent();
      if (tmp != _direction)
      {
        this->event(tmp);
        usleep(this->_usleepTime);
      }
    }
    if (this->_snake.size() == SNAKE_LENGTH_DEFAULT)
      std::cout << "Don't fear !" << std::endl;
    else
      std::cout << "Well played ! Your score is : " << (this->_snake.size() - SNAKE_LENGTH_DEFAULT) << std::endl;
  }

  void			Core::moveLeft(eEvent direction)
  {
    if (this->_direction == MV_RIGHT)
      this->moveRight(MV_RIGHT);
    else if (!this->_snake.empty())
    {
      valideStep((_snake[0].first - 1 + this->_map[0].size()) % this->_map[0].size(), _snake[0].second);
      this->_direction = direction;
      if (snakeEat(_snake[0].first - 1, _snake[0].second))
	{
	  this->createFood();
	  if (!this->_window->displayFood(this->_food))
	    return ;
	}
      else
        this->_snake.pop_back();
      std::pair<unsigned char, unsigned char>	lastHeadPos = this->_snake[0];
      this->_snake.push_front(std::pair<unsigned char, unsigned char>(
            (_snake[0].first - 1 + this->_map[0].size()) % this->_map[0].size(),
            lastHeadPos.second));
    }
  }

  void			Core::moveRight(eEvent direction)
  {
    if (this->_direction == MV_LEFT)
      this->moveLeft(MV_LEFT);
    else if (!this->_snake.empty())
    {
      valideStep((_snake[0].first + 1 + this->_map[0].size()) % this->_map[0].size(), _snake[0].second);
      this->_direction = direction;
      if (snakeEat(_snake[0].first + 1, _snake[0].second))
	{
	  this->createFood();
	  if (!this->_window->displayFood(this->_food))
	    return ;
	}
      else
        this->_snake.pop_back();
      std::pair<unsigned char, unsigned char>	lastHeadPos = this->_snake[0];
      this->_snake.push_front(std::pair<unsigned char, unsigned char>(
            (_snake[0].first + 1 + this->_map[0].size()) % this->_map[0].size(),
            lastHeadPos.second));
    }
  }

  void			Core::moveDown(eEvent direction)
  {
    if (this->_direction == MV_UP)
      this->moveUp(MV_UP);
    else if (!this->_snake.empty())
    {
      valideStep(_snake[0].first, (_snake[0].second + 1 + this->_map.size()) % this->_map.size());
      this->_direction = direction;
      if (snakeEat(_snake[0].first, _snake[0].second + 1))
	{
	  this->createFood();
	  if (!this->_window->displayFood(this->_food))
	    return ;
	}
      else
        this->_snake.pop_back();
      std::pair<unsigned char, unsigned char>	lastHeadPos = this->_snake[0];
      this->_snake.push_front(std::pair<unsigned char, unsigned char>(
            lastHeadPos.first,
            (lastHeadPos.second + 1 + this->_map.size()) % this->_map.size()));
    }
  }

  void			Core::moveUp(eEvent direction)
  {
    if (this->_direction == MV_DOWN)
      this->moveDown(MV_DOWN);
    else if (!this->_snake.empty())
    {
      valideStep(_snake[0].first, (_snake[0].second - 1 + this->_map.size()) % this->_map.size());
      this->_direction = direction;
      if (snakeEat(_snake[0].first, _snake[0].second - 1))
	{
	  this->createFood();
	  if (!this->_window->displayFood(this->_food))
	    return ;
	}
      else
        this->_snake.pop_back();
      std::pair<unsigned char, unsigned char>	lastHeadPos = this->_snake[0];
      this->_snake.push_front(std::pair<unsigned char, unsigned char>(
            lastHeadPos.first,
            (lastHeadPos.second - 1 + this->_map.size()) % this->_map.size()));
    }
  }

  bool			Core::isInWall(unsigned char x, unsigned char y) const
  {
    return this->_map[y][x];
  }

  bool			Core::isInSnake(unsigned char x, unsigned char y) const
  {
    unsigned int			i = 0;

    while (i < _snake.size())
    {
      if (_snake[i].first == x && _snake[i].second == y)
        return (true);
      i++;
    }
    return (false);
  }

  bool			Core::setSpeed()
  {
    int			subValue;

    this->_usleepTime -= _speedSlow;
    subValue = (_speedSlow * 5) / 100;
    _speedSlow -= subValue;
    return (true);
  }

  bool			Core::createFood()
  {
    char			rand_x;
    char			rand_y;

    this->setSpeed();
    rand_x = rand() % (_width - 2) + 1;
    rand_y = rand() % (_height - 2) + 1;
    while (isInWall(rand_x, rand_y) || isInSnake(rand_x, rand_y))
    {
      rand_x = rand() % (_width - 2) + 1;
      rand_y = rand() % (_height - 2) + 1;
    }
    if (_food.size() != 0)
    {
      _food[0].x = rand_x;
      _food[0].y = rand_y;
      _food[0].type = NORMAL;
      return (true);
    }
    return (false);
  }

  bool			Core::snakeEat(unsigned char x, unsigned char y) const
  {
    if (_food.size() != 0)
      if (_food[0].x == x && _food[0].y == y)
        return (true);
    return (false);
  }

  bool			Core::addElem()
  {
    int			x_elem;
    int			y_elem;

    if (_food.size() != 0)
    {
      x_elem = _food[0].x;
      y_elem = _food[0].y;
      _snake.push_front(std::pair<unsigned char,unsigned char>(x_elem, y_elem));
      return (true);
    }
    return (false);
  }

  bool			Core::valideStep(unsigned char x, unsigned char y)
  {
    if (_map[y][x] || this->isInSnake(x, y))
      this->_play = false;
    return (true);
  }
};
