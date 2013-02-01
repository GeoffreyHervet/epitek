#ifndef		CORE_HPP
# define	CORE_HPP

# include	<string>
# include	"Map.hpp"
# include	"MyGame.hpp"

class		Core
{

public:

  Core(void);
  virtual ~Core(void);

  void			run(void);

private:

  MyGame		_game;

};

#endif
