//
// Warrior.hh for ex01 in /home/hervet_g/piscine/piscine_cpp_d09-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 14:40:29 2012 geoffrey hervet
// Last update Thu Jan 12 14:40:29 2012 geoffrey hervet
//

#ifndef   __WARRIOR_HH__
# define  __WARRIOR_HH__

#include	<string>
#include	"Character.hh"

class			Warrior: virtual public Character
{
  public:
    const std::string	_weapon;

  public:
    Warrior(const std::string &, int lvl);

    int			CloseAttack();
    int			RangeAttack();
    //void		Heal();
    //void RestorePower();

    const std::string &	getWeapon() const;
};


#endif     /* !__WARRIOR_HH__ */
