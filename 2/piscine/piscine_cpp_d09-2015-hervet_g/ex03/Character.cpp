//
// Character.cpp for ok in /home/hervet_g/piscine/ok
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 11:33:38 2012 geoffrey hervet
// Last update Thu Jan 12 11:33:38 2012 geoffrey hervet
//

#include	<iostream>

#include	"Character.hh"


Character::Character(const std::string &name, int lvl)
  : Range(Character::CLOSE),
    _name(std::string(name)),
    _lvl(lvl),
    _pv(100),
    _power(100),
    _force(5),
    _endur(5),
    _intel(5),
    _espr(5),
    _agil(5)
{
  std::cout << name << " Created" << std::endl;
}

/* ====================================== */

const std::string &	Character::getName() const
{
  return this->_name;
}

int			Character::getLvl() const
{
  return this->_lvl;
}

int			Character::getPv() const
{
  return this->_pv;
}

int			Character::getPower() const
{
  return this->_power;
}

void			Character::addPv(const int val)
{
  if ((this->_pv + val) > 100)
    this->_pv = 100;
  else
    this->_pv += val;
}

/* ====================================== */

int			Character::CloseAttack()
{
  if (this->getPower() < 10)
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }

  this->Range = Character::CLOSE;
  this->_power -= 10;
  std::cout << this->getName() <<
    " strikes with a wood stick" << std::endl;
  return 10 + this->_force;
}

int			Character::RangeAttack()
{
  if (this->getPower() < 10)
  {
    this->_power = 0;
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
  }
  this->Range = Character::RANGE;
  this->_power -= 10;
  std::cout << this->getName() <<
    " launches a stone" << std::endl;
  return 5 + this->_force;
}

void			Character::Heal()
{
  this->addPv(50);
  std::cout << this->getName() <<
    " takes a potion" << std::endl;
}

void			Character::RestorePower()
{
  this->_power = 100;
  std::cout << this->getName() << " eats" << std::endl;
}

void			Character::TakeDamage(int _damage)
{
  if (this->_pv < _damage)
  {
    this->_pv = 0;
    std::cout << this->getName() << " out of combat" << std::endl;
  }
  else
  {
    this->_pv -= _damage;
    std::cout << this->getName() << " takes "
      << _damage << " damage" << std::endl;
  }
}

void			Character::addPower(const int nb)
{
  if ((this->_power + nb) > 100)
    this->_power = 100;
  else
    this->_power += nb;
}
