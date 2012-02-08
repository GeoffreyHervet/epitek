//
// Federation.hh for ex00 in /home/hervet_g/piscine/piscine_cpp_d07m-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 11:22:19 2012 geoffrey hervet
// Last update Tue Jan 10 11:22:19 2012 geoffrey hervet
//

#ifndef   __FEDERATION_HH__
# define  __FEDERATION_HH__

#include	<string>
#include	"Warpsystem.hh"

namespace	Federation
{
  namespace	Starfleet
  {
    class	Ship
    {
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_core;

      public:
        Ship(int, int, std::string, short);
        void		setupCore(WarpSystem::Core *);
        void		checkCore(void);
    };
  }
  class	Ship
  {
    int		_length;
    int		_width;
    std::string	_name;
    short	_maxWarp;
    WarpSystem::Core *_core;

    public:
    Ship(int, int, std::string, short = 1);
    void		setupCore(WarpSystem::Core *);
    void		checkCore(void);
  };
}


#endif     /* !__FEDERATION_HH__ */
