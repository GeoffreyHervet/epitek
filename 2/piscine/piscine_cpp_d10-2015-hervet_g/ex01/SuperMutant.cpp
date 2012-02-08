//
// SuperMutant.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 11:53:18 2012 geoffrey hervet
// Last update Fri Jan 13 11:53:18 2012 geoffrey hervet
//

#include		<iostream>

#include		"SuperMutant.hh"

SuperMutant::SuperMutant()
  : AEnemy(170, "Super Mutant")
{
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
  std::cout << "Aaargh ..." << std::endl;
}

void			SuperMutant::takeDamage(int val)
{
  if (val > 3)
    AEnemy::takeDamage(val - 3);
}
