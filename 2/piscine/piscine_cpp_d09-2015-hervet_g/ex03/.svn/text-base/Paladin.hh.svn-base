//
// Paladin.hh for ex03 in /home/hervet_g/piscine/piscine_cpp_d09-2015-hervet_g/ex03
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 16:11:33 2012 geoffrey hervet
// Last update Thu Jan 12 16:11:33 2012 geoffrey hervet
//

#ifndef   __PALADIN_HH__
# define  __PALADIN_HH__

#include	"Warrior.hh"
#include	"Priest.hh"

class		Paladin: public Warrior, public Priest
{
  public:
    Paladin(const std::string &, int lvl);

    using Warrior::CloseAttack;
    using Priest::RangeAttack;
    using Priest::Heal;
    using Warrior::Character::RestorePower;
    int		Intercept();
};

#endif     /* !__PALADIN_HH__ */
