/*
** Hunter.h for ex04 in /home/hervet_g/piscine/piscine_cpp_d09-2015-hervet_g/ex04
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Thu Jan 12 19:16:30 2012 geoffrey hervet
** Last update Thu Jan 12 19:16:30 2012 geoffrey hervet
*/

#ifndef   __HUNTER_H__
# define  __HUNTER_H__

#include      "Character.hh"
#include      "Warrior.hh"

class		Hunter: public Warrior
{
  const std::string	_weapon_;
  public:
    Hunter(const std::string &, int lvl);

    int		CloseAttack(); // c a c
    int		RangeAttack(); // dist
    void	RestorePower();
    using	Warrior::Character::Heal;

    const std::string	getWeapon();
};

#endif     /* !__HUNTER_H__ */
