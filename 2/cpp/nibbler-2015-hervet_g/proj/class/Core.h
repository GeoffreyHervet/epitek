#ifndef CORE_H_
# define CORE_H_

# include <map>
# include <deque>
# include <vector>
# include <utility>
# include <unistd.h>
# include <typeinfo>

# include "CoreProto.h"
# include "IGraphic.h"

# define  USLEEP_DEFAULT	(150000)
# define  SPEED_SLOW		(7500)
# define  SNAKE_LENGTH_DEFAULT	(4)
# define  MAX_SIZE_MAP		(150)
# define  MIN_SIZE_MAP		(15)

# define  ERR_MAP_SIZE		("Invalide map size [15 * 15 | 150 * 150]")
# define  ERR_EVENT		("Unrecognized event")

namespace	Nibbler
{
  class	IGraphic;
  class	Core
  {
    class			Error :
      public			  std::exception
    {
      const			char *_what;

      public:
      Error(const char *e) throw() : std::exception(), _what(e) {};
      ~Error() throw() {};
      Error(const Error &e) throw() : std::exception(), _what(e.what()) {};
      Error			&operator=(const Error &) throw();

      const char		*what(void) const throw() { return this->_what; };
    };

    protected:
      bool			_play;
      bool			_pause;
      const unsigned char	_height;
      const unsigned char	_width;
      IGraphic			*_window;
      useconds_t		_usleepTime;
      int			_speedSlow;
      eEvent			_direction;

      std::map<eEvent, void (Core::*)(eEvent)>			_functions;

      std::vector<std::vector <bool> >				_map;
      std::deque<std::pair<unsigned char, unsigned char> >	_snake;
      std::vector<tFood>					_food;

    public:
      Core(std::vector<std::vector <bool> > map, unsigned char width, unsigned char height, IGraphic *);
      ~Core();
    protected:
      Core(const Core &);
      Core		&operator=(const Core &);

    public:
      void		event(eEvent);
      void		run(void);

    protected:
      void		initMap(void);
      bool		initSnake(void);

      void		moveLeft(eEvent);
      void		moveRight(eEvent);
      void		moveDown(eEvent);
      void		moveUp(eEvent);

      /* check valide */

      bool		valideStep(unsigned char, unsigned char);

      /* add elem */

      bool		addElem();
      bool		setSpeed();

      /* food gestion */

      bool		createFood();
      bool		isInSnake(unsigned char, unsigned char) const;
      bool		isInWall(unsigned char, unsigned char) const;
      bool		snakeEat(unsigned char, unsigned char) const;
  };
};
#endif /* CORE_H_ */
