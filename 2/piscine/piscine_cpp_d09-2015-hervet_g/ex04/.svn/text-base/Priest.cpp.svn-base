//
// Priest.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d09-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 15:35:40 2012 geoffrey hervet
// Last update Thu Jan 12 15:35:40 2012 geoffrey hervet
//

#include	<iostream>

#include	"Priest.hh"

  Priest::Priest(const std::string &name, int lvl)
: Character(name, lvl),
  Mage(name, lvl)
{
  this->_force = 4;
  this->_endur = 4;
  this->_intel = 42;
  this->_espr = 21;
  this->_agil = 2;

  std::cout << this->getName() << " enters in the order" << std::endl;
}

int		Priest::CloseAttack()
{
  if (this->getPower() < 10)
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }

  this->Range = Character::CLOSE;
  this->_power -= 10;
  std::cout << this->getName() << " uses a spirit explosion" << std::endl;
  return 10 + this->_espr;
}

int		Priest::RangeAttack()
{
  if (this->getPower() < 25)
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }

  this->Range = Character::RANGE;
  this->_power -= 25;
  std::cout << this->getName() << " launches a fire ball" << std::endl;
  return this->_espr + 20;
}

void		Priest::Heal()
{
  if (this->getPower() >= 10)
  {
    this->_power -= 10;
    this->addPv(70);
    std::cout << this->getName() << " casts a little head spell" << std::endl;
  }
  else
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
  }
}




