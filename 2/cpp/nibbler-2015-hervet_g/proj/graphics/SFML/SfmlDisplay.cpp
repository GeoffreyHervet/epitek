#include <sstream>
#include <SFML/Graphics.hpp>

#include "SfmlDisplay.h"
#include "IGraphic.h"
#include "CoreProto.h"

SfmlDisplay::SfmlDisplay(int width, int height)
  : _win(sf::VideoMode(width * SIZE_CASE, height * SIZE_CASE, 32), "SFML Graphics")
{
  _width = width;
  _height = height;
  headMap[Nibbler::MV_RIGHT] = RSNAKE_SPT;
  headMap[Nibbler::MV_LEFT] = LSNAKE_SPT;
  headMap[Nibbler::MV_UP] = USNAKE_SPT;
  headMap[Nibbler::MV_DOWN] = DSNAKE_SPT;
  keyMap[sf::Key::Right] = Nibbler::MV_RIGHT;
  keyMap[sf::Key::Left] = Nibbler::MV_LEFT;
  keyMap[sf::Key::Up] = Nibbler::MV_UP;
  keyMap[sf::Key::Down] = Nibbler::MV_DOWN;
  keyMap[sf::Key::Space] = Nibbler::PAUSE;
}

SfmlDisplay::~SfmlDisplay()
{
  _win.Close();
}

Nibbler::eEvent SfmlDisplay::getEvent()
{
  if (this->_win.GetEvent(this->Event))
    {
      if (Event.Type == sf::Event::KeyPressed)
	{
	  if (Event.Key.Code == sf::Key::Escape)
	    {
	      this->_win.Close();
	      return (Nibbler::EXIT);
	    }
	  if (keyMap[Event.Key.Code])
	    return (keyMap[Event.Key.Code]);
	}
    }
  return (Nibbler::UNKNOWN);
}

bool	SfmlDisplay::erase_snake(std::deque<std::pair<unsigned char,unsigned char> > const& snake)
{
  unsigned int		i;
  sf::Sprite	Sprite;
  sf::Image	Image;

  i = 0;
  while (i < snake.size())
    {
      if (!Image.LoadFromFile(BG_SPT))
	return (false);
      Sprite.SetImage(Image);
      Sprite.SetPosition(snake[i].first * SIZE_CASE, snake[i].second * SIZE_CASE);
      this->_win.Draw(Sprite);
      i++;
    }
  return (true);
}
bool	SfmlDisplay::reset_queue(unsigned char x, unsigned char y)
{
  sf::Sprite	Sprite;
  sf::Image	Image;

  if (!Image.LoadFromFile(BG_SPT))
    return (false);
  Sprite.SetImage(Image);
  Sprite.SetPosition(x * SIZE_CASE, y * SIZE_CASE);
  this->_win.Draw(Sprite);
  return (true);
}

bool	SfmlDisplay::getSprite(int size, int position, Nibbler::eEvent direction, sf::Image *Image)
{
  if (size < 4)
    return (Image->LoadFromFile(FOOD_SPT));
  else if (position == 0)
    return (Image->LoadFromFile(headMap[direction]));
  else if (position == size - 2)
    return (Image->LoadFromFile(QUEUE_BEGIN));
  else if (position == size - 1)
    return (Image->LoadFromFile(QUEUE_END));
  return (Image->LoadFromFile(FOOD_SPT));
}

bool SfmlDisplay::displaySnake(std::deque<std::pair<unsigned char, unsigned char> > const& snake,
			       Nibbler::eEvent direction)
{
  unsigned int		i;
  sf::Sprite	Sprite;
  sf::Image	Image;

  i = 0;
  this->cleanScore();
  (void)direction;
  this->erase_snake(snake);
  while (i < snake.size())
    {
      if (!this->getSprite(snake.size(), i, direction, &Image))
	return (false);
      Sprite.SetImage(Image);
      Sprite.SetPosition(snake[i].first * SIZE_CASE, snake[i].second * SIZE_CASE);
      this->_win.Draw(Sprite);
      i++;
    }
  return (true);
}

bool SfmlDisplay::displayMap(const std::vector<std::vector<bool> > & map)
{
  sf::Sprite	Sprite;
  sf::Image	Image;
  int		y = 0;
  int		x;

  for (y = 0; y < _height; y++)
    {
      for (x = 0; x < _width; x++)
  	{
  	  if (map[y][x])
	    {
	      if (!Image.LoadFromFile(WALL_SPT))
		return (false);
	    }
	  else
	    {
	      if (!Image.LoadFromFile(BG_SPT))
		return (false);
	    }
	  Sprite.SetImage(Image);
	  Sprite.SetPosition(x * SIZE_CASE, y * SIZE_CASE);
  	  this->_win.Draw(Sprite);
  	}
    }
  return (true);
}

bool SfmlDisplay::displayFood(const std::vector<Nibbler::tFood>	&snake)
{
  sf::Sprite	Sprite;
  sf::Image	Image;

  if (!Image.LoadFromFile(FOOD_SPT))
    return (false);
  Sprite.SetImage(Image);
  Sprite.SetPosition(snake[0].x * SIZE_CASE, snake[0].y * SIZE_CASE);
  this->_win.Draw(Sprite);
  return (true);
}

bool	SfmlDisplay::cleanScore()
{
  sf::Sprite	Sprite;
  sf::Image	Image;

  if (!Image.LoadFromFile(BG_SPT))
    return (false);
  Sprite.SetImage(Image);
  Sprite.SetPosition(2 * SIZE_CASE, 2 * SIZE_CASE);
  this->_win.Draw(Sprite);
  Sprite.SetPosition(3 * SIZE_CASE, 2 * SIZE_CASE);
  this->_win.Draw(Sprite);
  Sprite.SetPosition(4 * SIZE_CASE, 2 * SIZE_CASE);
  this->_win.Draw(Sprite);
  return (true);
}

bool SfmlDisplay::displayScore(unsigned int score)
{
  sf::String Text;
  std::ostringstream	oss;

  oss << score;
  Text.SetText(oss.str());
  Text.SetFont(sf::Font::GetDefaultFont());
  Text.SetColor(sf::Color(0, 0, 0));
  Text.SetSize(28);
  Text.Move(2 * SIZE_CASE, 2 * SIZE_CASE - 5);
  _win.Draw(Text);
  _win.Display();
  return (true);
}

extern	"C"
{
  Nibbler::IGraphic	*ctor(int width, int height, int ac, char **av)
  {
    (void)ac;
    (void)av;
    SfmlDisplay		*tmp;

    tmp = new SfmlDisplay(width, height);
    return (tmp);
  }
}
