#ifndef		SFML_DISPLAY_H__
# define	SFML_DISPLAY_H__

#include <iostream>
#include <vector>
#include <deque>
#include <SFML/Graphics.hpp>

#include "IGraphic.h"
#include "CoreProto.h"

# define	SIZE_CASE	25

# define	FOOD_SPT	"texture/food.png"
# define	BG_SPT		"texture/bg.png"
# define	WALL_SPT	"texture/stone.png"
# define	RSNAKE_SPT	"texture/head_right.png"
# define	LSNAKE_SPT	"texture/head_left.png"
# define	USNAKE_SPT	"texture/head_up.png"
# define	DSNAKE_SPT	"texture/head_down.png"
# define	QUEUE_BEGIN	"texture/q_b.png"
# define	QUEUE_END	"texture/q_e.png"

class			SfmlDisplay : public Nibbler::IGraphic
{
  std::map<Nibbler::eEvent, std::string>	headMap;
  std::map<sf::Key::Code, Nibbler::eEvent>	keyMap;
  sf::RenderWindow	_win;
  sf::Event		Event;
  int			_width;
  int			_height;

  bool	erase_snake(std::deque<std::pair<unsigned char, unsigned char> > const& snake);
  bool	getSprite(int size, int position, Nibbler::eEvent direction, sf::Image *Image);
  bool	cleanScore();

public:
  SfmlDisplay(int width, int height);
  virtual ~SfmlDisplay();

  virtual Nibbler::eEvent getEvent();
  virtual bool reset_queue(unsigned char, unsigned char);
  virtual bool displaySnake(std::deque<std::pair<unsigned char, unsigned char> > const&snake, Nibbler::eEvent direction);
  virtual bool displayMap(const std::vector<std::vector<bool> > &);
  virtual bool displayFood(const std::vector<Nibbler::tFood>	&snake);
  virtual bool displayScore(unsigned int score);
};

#endif
