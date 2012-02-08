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

namespace Federation { class Ship; namespace Starfleet { class Ship; } }

#include	"Destination.hh"
#include	"Warpsystem.hh"
#include	"Borg.hh"

namespace	Federation
{
  namespace	Starfleet
  {
    class	Captain;

    class	Ship
    {
      short		_maxWarp;
      int		_length;
      int		_width;
      int		_shield;
      int		_photonTorpedo;
      Destination	_location;
      Destination	_home;
      std::string	_name;
      WarpSystem::Core	*_core;
      Captain		*_captain;

      public:
        Ship(int, int, std::string, short, int);
        Ship();
        void		setupCore(WarpSystem::Core *);
        void		checkCore(void);
        void		promote(Captain *);
        bool		move(int warp, Destination d);
        bool		move(int warp);
        bool		move(Destination d);
        bool		move();
        void		fire(Borg::Ship*);
        void		fire(int, Borg::Ship*);
        int		getShield();
        void		setShield(int);
        std::string	getName(void);
    };

    class	Captain
    {
      std::string	_name;
      int		_age;
      public:
        Captain(std::string);
        std::string	getName();
        int		getAge();
        void		setAge(int);
    };

    class	Ensign
    {
      std::string	_name;
      public:
        explicit Ensign(std::string);
    };
  }


  class	Ship
  {
    int		_length;
    int		_width;
    Destination	_location;
    Destination	_home;
    std::string	_name;
    short	_maxWarp;
    WarpSystem::Core *_core;
    Starfleet::Captain *_captain;

    public:
    Ship(int, int, std::string, short = 1);
    void		setupCore(WarpSystem::Core *);
    void		checkCore(void);
    void		promote(Starfleet::Captain *);
    bool		move(int warp, Destination d);
    bool		move(int warp);
    bool		move(Destination d);
    bool		move();
    WarpSystem::Core	*getCore();
  };
}


#endif     /* !__FEDERATION_HH__ */
