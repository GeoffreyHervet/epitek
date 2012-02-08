//
// Paladin.cpp for ex03 in /home/hervet_g/piscine/piscine_cpp_d09-2015-hervet_g/ex03
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 16:11:38 2012 geoffrey hervet
// Last update Thu Jan 12 16:11:38 2012 geoffrey hervet
//

#include	<iostream>

#include	"Paladin.hh"

Paladin::Paladin(const std::string &name, int lvl)
  : Character(name, lvl),
    Warrior(name, lvl),
    Priest(name, lvl)

{
  Warrior::_force = 9;
  Warrior::_endur = 10;
  Warrior::_intel = 10;
  Warrior::_espr = 10;
  Warrior::_agil = 2;

  std::cout << "the light falls on " <<  this->getName() << std::endl;
}


int		Paladin::Intercept()
{
  return Warrior::RangeAttack();
}
