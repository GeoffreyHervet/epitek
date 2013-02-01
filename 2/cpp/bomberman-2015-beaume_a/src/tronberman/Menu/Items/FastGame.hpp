#ifndef		FASTGAME_HPP
# define	FASTGAME_HPP

# include	"AMenuObject.hpp"

namespace	Menu
{

  class		FastGame : public AMenuObject
  {

    private:

      FastGame(FastGame const&);
      FastGame&		operator=(FastGame const&);

    public:

      FastGame(std::string const&);
      ~FastGame();

      bool	 	selected(IMenu&, MyGame&, gdl::Input &);
  };
}

#endif		/* FASTGAME_HPP_ */
