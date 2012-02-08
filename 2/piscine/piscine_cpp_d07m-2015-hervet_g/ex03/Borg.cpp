//
// Borg.cpp for ex01 in /home/hervet_g/piscine/piscine_cpp_d07m-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 11:41:09 2012 geoffrey hervet
// Last update Tue Jan 10 11:41:09 2012 geoffrey hervet
//

#include	<iostream>

#include	"Borg.hh"

Borg::Ship::Ship(int wF)
{
  this->_side = 3000;
  this->_maxWarp = 0;
  this->_home = UNICOMPLEX;
  this->_location = this->_home;
  this->_weaponFrequency = wF;
  this->_shield = 100;
  this->_repair = 3;

  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl <<
    "Your biological characteristics and technologies will be assimilated." << std::endl <<
    "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int wF, short rep)
{
  this->_side = 3000;
  this->_maxWarp = 0;
  this->_home = UNICOMPLEX;
  this->_location = this->_home;
  this->_weaponFrequency = wF;
  this->_shield = 100;
  this->_repair = rep;

  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl <<
    "Your biological characteristics and technologies will be assimilated." << std::endl <<
    "Resistance is futile." << std::endl;
}

void		Borg::Ship::setupCore(WarpSystem::Core* ptr)
{
  this->_core = ptr;
}

void		Borg::Ship::checkCore(void)
{
  if (this->_core->checkReactor()->isStable())
    std::cout << "Everything is in order." << std::endl;
  else
    std::cout << "Critical failure imminent." << std::endl;
}

bool		Borg::Ship::move(int warp, Destination d)
{
  if (warp > this->_maxWarp || d == this->_location || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = d;
  return true;
}

bool		Borg::Ship::move(int warp)
{
  if (warp > this->_maxWarp || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = this->_home;
  return true;
}

bool		Borg::Ship::move(Destination d)
{
  if (d == this->_location || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = d;
  return true;
}

bool		Borg::Ship::move()
{
  if (false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = this->_home;
  return true;
}

int		Borg::Ship::getShield()
{
  return	this->_shield;
}

void		Borg::Ship::setShield(int val)
{
  this->_shield = val;
}

int		Borg::Ship::getWeaponFrequency()
{
  return this->_weaponFrequency;
}

void		Borg::Ship::setWeaponFrequency(int val)
{
  this->_weaponFrequency = val;
}

short		Borg::Ship::getRepair()
{
  return this->_repair;
}

void		Borg::Ship::getRepair(short val)
{
  this->_repair = val;
}

void		Borg::Ship::fire(Federation::Starfleet::Ship *ship)
{
  std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
  ship->setShield(ship->getShield() - this->_weaponFrequency);
}

void		Borg::Ship::fire(Federation::Ship *ship)
{
  std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
  ship->getCore()->checkReactor()->setStability(false);
}

void		Borg::Ship::repair()
{
  if (this->_repair > 0)
  {
    std::cout << "Begin shield re-initialisation... Done. Awaiting further instruction." << std::endl;
    this->_repair--;
    this->_shield = 100;
  }
  else
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
}
