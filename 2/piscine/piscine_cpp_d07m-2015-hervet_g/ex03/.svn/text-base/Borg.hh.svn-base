//
// Borg.hh for ex01 in /home/hervet_g/piscine/piscine_cpp_d07m-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 11:39:11 2012 geoffrey hervet
// Last update Tue Jan 10 11:39:11 2012 geoffrey hervet
//

#ifndef   __BORG_HH__
# define  __BORG_HH__

#include	<string>

namespace Borg { class Ship;}


#include	"Federation.hh"
#include	"Destination.hh"
#include	"Warpsystem.hh"

namespace		Borg
{
  class			Ship
  {
    int			_side;
    short		_maxWarp;
    Destination		_location;
    Destination		_home;
    WarpSystem::Core	*_core;
    int			_shield;
    int			_weaponFrequency;
    short		_repair;

    public:
      Ship(int wF);
      Ship(int wF, short);
      void		setupCore(WarpSystem::Core *);
      void		checkCore(void);
      bool		move(int warp, Destination d);
      bool		move(int warp);
      bool		move(Destination d);
      bool		move();
      int		getShield();
      void		setShield(int);
      int		getWeaponFrequency();
      void		setWeaponFrequency(int);
      short		getRepair();
      void		getRepair(short);
      void		fire(Federation::Starfleet::Ship *);
      void		fire(Federation::Ship *);
      void		repair();
  };
}

#endif     /* !__BORG_HH__ */
