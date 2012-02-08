//
// AWeapon.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 11:04:19 2012 geoffrey hervet
// Last update Fri Jan 13 11:04:19 2012 geoffrey hervet
//

#include	<iostream>

#include	"AWeapon.hh"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
  : _name(name),
    _apcost(apcost),
    _damage(damage)
{

}

AWeapon::~AWeapon()
{
}

std::string const	&AWeapon::getName() const
{
  return this->_name;
}

int			AWeapon::getAPcost() const
{
  return this->_apcost;
}

int			AWeapon::getDamage() const
{
  return this->_damage;
}
