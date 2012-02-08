//
// AEnemy.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 11:19:28 2012 geoffrey hervet
// Last update Fri Jan 13 11:19:28 2012 geoffrey hervet
//

#include	<iostream>

#include	"AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const &type)
  : _hp(hp),
    _type(type)
{
}

AEnemy::~AEnemy()
{
}

std::string const	&AEnemy::getType() const
{
  return this->_type;
}

int			AEnemy::getHP() const
{
  return this->_hp;
}

void			AEnemy::takeDamage(int n)
{
  if (n > this->_hp)
    this->_hp = 0;
  else
    this->_hp -= n;
}

bool			AEnemy::canDoAction() const
{
  return this->_hp != 0;
}
