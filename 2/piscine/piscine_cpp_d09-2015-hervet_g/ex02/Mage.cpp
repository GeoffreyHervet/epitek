//
// Mage.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d09-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 15:20:58 2012 geoffrey hervet
// Last update Thu Jan 12 15:20:58 2012 geoffrey hervet
//

#include	<iostream>

#include	"Mage.hh"

Mage::Mage(const std::string &name, int lvl)
  :Character(name, lvl)
{
  this->_force = 6;
  this->_endur = 6;
  this->_intel = 12;
  this->_espr = 11;
  this->_agil = 7;

  std::cout << this->getName() << " teleported" << std::endl;
}

int			Mage::CloseAttack()
{
  if (this->getPower() < 10)

  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }

  this->Range = Character::CLOSE;
  this->_power -= 10;
  std::cout << this->getName() << " blinks" << std::endl;
  return this->RangeAttack();
}

int			Mage::RangeAttack()
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
  return 20 + this->_espr;
}

void			Mage::RestorePower()
{
  this->addPower(50 + this->_intel);
  std::cout << this->getName() << " takes a mana potion" << std::endl;
}


