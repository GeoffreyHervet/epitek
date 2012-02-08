//
// Warrior.cpp for ex01 in /home/hervet_g/piscine/piscine_cpp_d09-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 14:40:35 2012 geoffrey hervet
// Last update Thu Jan 12 14:40:35 2012 geoffrey hervet
//

#include	<iostream>

#include	"Warrior.hh"

Warrior::Warrior(const std::string &name, int lvl)
  : Character(name, lvl),
  _weapon("hammer")
{
  this->_force = 12;
  this->_endur = 12;
  this->_intel = 12;
  this->_espr = 5;
  this->_agil = 7;

  std::cout
    << "I'm "
    << this->getName()
    << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG"
    << std::endl;
}

int			Warrior::RangeAttack()
{
  if (this->getPower() < 10)
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }

  this->Range = Character::RANGE;
  this->_power -= 10;
  std::cout << this->getName() << " intercepts" << std::endl;
  return this->CloseAttack();
}

int		Warrior::CloseAttack()
{
  if (this->getPower() < 30)
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }

  this->Range = Character::CLOSE;
  this->_power -= 30;
  std::cout << this->getName() <<
    " strikes with his " << this->getWeapon() << std::endl;
  return 20 + this->_force;
}

const std::string &	Warrior::getWeapon() const
{
  return this->_weapon;
}
