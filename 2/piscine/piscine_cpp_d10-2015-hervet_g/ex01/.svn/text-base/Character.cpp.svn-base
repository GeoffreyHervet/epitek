//
// Character.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 13:17:53 2012 geoffrey hervet
// Last update Fri Jan 13 13:17:53 2012 geoffrey hervet
//

#include	<iostream>
#include	<iomanip>

#include	"Character.hh"

Character::Character(std::string const &name)
  : _name(name),
    _ap(40),
    _weapon(NULL)
{
}

Character::Character(const Character &other)
  : _name(other.getName()),
    _ap(other.getAP()),
    _weapon(NULL)
{
}

Character		&Character::operator=(const Character &other)
{
  if (&other != this)
  {
    if (this->_weapon != NULL)
    {
    }
    this->_name = other.getName();
  }
  return *this;
}

Character::~Character()
{
}

void			Character::recoverAp()
{
  if ((this->_ap + 10) > 40)
    this->_ap = 40;
  else
    this->_ap += 10;
}

void			Character::equip(AWeapon *weap)
{
  this->_weapon = weap;
}

void			Character::attack(AEnemy *en)
{
  if (this->_weapon != NULL && en != NULL && this->_ap >this->_weapon->getAPcost())
  {
    this->_ap -= this->_weapon->getAPcost();
    std::cout << this->getName() << " attacks "
      << en->getType() << " with a "
      << this->_weapon->getName() << std::endl;
    this->_weapon->attack();
    en->takeDamage(this->_weapon->getDamage());
    if (en->getHP() == 0)
      delete en;
  }
}

const std::string	&Character::getName() const
{
  return this->_name;
}

const std::string	Character::getWeaponName() const
{
  if (this->_weapon == NULL)
    return "";
  return this->_weapon->getName();
}

int		  	Character::getAP() const
{
  return this->_ap;
}

std::ostream		&operator<<(std::ostream &os, const Character &c)
{
  os << c.getName() << " has " << c.getAP() << " AP and";
  if (c.getWeaponName().empty())
    os << " is unarmed" << std::endl;
  else
    os << " wields a " << c.getWeaponName() << std::endl;
  return os;
}
