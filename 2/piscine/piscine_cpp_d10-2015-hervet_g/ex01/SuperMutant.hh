//
// SuperMutant.hh for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 11:53:24 2012 geoffrey hervet
// Last update Fri Jan 13 11:53:24 2012 geoffrey hervet
//

#ifndef   __SUPERMUTANT_HH__
# define  __SUPERMUTANT_HH__

#include		"AEnemy.hh"

class			SuperMutant:
  public		  AEnemy
{
  public:
    SuperMutant();
    virtual ~SuperMutant();

    virtual void	takeDamage(int);
};

#endif     /* !__SUPERMUTANT_HH__ */
