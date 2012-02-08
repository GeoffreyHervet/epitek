//
// Hunter.cpp for ex04 in /home/hervet_g/piscine/piscine_cpp_d09-2015-hervet_g/ex04
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 19:16:24 2012 geoffrey hervet
// Last update Thu Jan 12 19:16:24 2012 geoffrey hervet
//

#include	<iostream>

#include	"Hunter.hh"

Hunter::Hunter(const std::string &name, int lvl)
  : Character(name, lvl),
    Warrior(name, lvl)
{
  
  this->_force = 8;
  this->_endur = 9;
  this->_intel = 5;
  this->_espr = 6;
  this->_agil = 24;

  std::cout << this->getName()
    << " is born form a tree"
    << std::endl;
}

int		Hunter::CloseAttack()
{
  if (this->getPower() < 30)
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }

  this->Range = Character::CLOSE;
  this->_power -= 30;
  std::cout << this->getName() << " strikes with " << this->getWeapon() << std::endl;
  return this->_force + 20;
}

int		Hunter::RangeAttack()
{
  if (this->getPower() < 25)
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }

  this->Range = Character::RANGE;
  this->_power -= 25;
  std::cout << this->getName() << " uses his bow" << std::endl;
  return this->_agil + 20;
}

void		Hunter::RestorePower()
{
  this->_power = 100;
  std::cout << this->getName() << " meditates" << std::endl;
}

const std::string Hunter::getWeapon()
{
  return "sword";
}
