//
// Federation.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d07m-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 09:58:57 2012 geoffrey hervet
// Last update Tue Jan 10 09:58:57 2012 geoffrey hervet
//

#include	<iostream>

#include	"Federation.hh"

/* ========================================= */

Federation::Starfleet::Ship::Ship(int length,
				int width,
                                std::string name,
                                short maxWarp)
{
  this->_length = length;
  this->_width	= width;
  this->_name	= name;
  this->_maxWarp= maxWarp;
  this->_captain= NULL;
  this->_home	= EARTH;
  this->_location=this->_home;

  std::cout <<
    "The ship USS " << this->_name <<
    " has been finished. It is " << this->_length <<
    " m in length and " << this->_width <<
    " m in width." << std::endl <<
    "It can go to Warp " << this->_maxWarp <<
    "!" << std::endl;
}

void		Federation::Starfleet::Ship::setupCore(WarpSystem::Core* ptr)
{
  this->_core = ptr;

  std::cout << "Uss " << this->_name << ": The core is set." << std::endl;
}

void		Federation::Starfleet::Ship::checkCore(void)
{
  std::cout << "Uss " << this->_name <<
    ": The core is " <<
    (this->_core->checkReactor()->isStable() ? "stable" : "unstable") <<
    " at the time." << std::endl;
}

void		Federation::Starfleet::Ship::promote(Starfleet::Captain *cap)
{
  this->_captain = cap;
  std::cout << this->_captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}


bool		Federation::Starfleet::Ship::move(int warp, Destination d)
{
  if (warp > this->_maxWarp || d == this->_location || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = d;
  return true;
}

bool		Federation::Starfleet::Ship::move(int warp)
{
  if (warp > this->_maxWarp || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = this->_home;
  return true;
}

bool		Federation::Starfleet::Ship::move(Destination d)
{
  if (d == this->_location || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = d;
  return true;
}

bool		Federation::Starfleet::Ship::move()
{
  if (false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = this->_home;
  return true;
}

/* ========================================= */

Federation::Ship::Ship(int length,
                      int width,
                      std::string name,
                      short maxWarp)
{
  this->_length = length;
  this->_width	= width;
  this->_name	= name;
  this->_maxWarp= (maxWarp > 1) ? 1 : maxWarp;
  this->_captain= NULL;
  this->_home	= VULCAN;
  this->_location=this->_home;

  std::cout <<
    "The independant ship " << this->_name <<
    " just finished its construction. It is " << this->_length <<
    " m is length and " << this->_width <<
    " m in width." << std::endl;
}

void		Federation::Ship::setupCore(WarpSystem::Core * ptr)
{
  this->_core = ptr;

  std::cout <<  this->_name << ": The core is set." << std::endl;
}

void		Federation::Ship::checkCore(void)
{
  std::cout << this->_name <<
    ": The core is " <<
    (this->_core->checkReactor()->isStable() ? "stable" : "unstable") <<
    " at the time." << std::endl;
}

void		Federation::Ship::promote(Starfleet::Captain *cap)
{
  this->_captain = cap;
  std::cout << this->_captain->getName() << ": I'm glad to be the captain of " << this->_name << "." << std::endl;
}

bool		Federation::Ship::move(int warp, Destination d)
{
  if (warp > this->_maxWarp || d == this->_location || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = d;
  return true;
}

bool		Federation::Ship::move(int warp)
{
  if (warp > this->_maxWarp || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = this->_home;
  return true;
}

bool		Federation::Ship::move(Destination d)
{
  if (d == this->_location || false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = d;
  return true;
}

bool		Federation::Ship::move()
{
  if (false == this->_core->checkReactor()->isStable())
    return false;
  this->_location = this->_home;
  return true;
}

/* ========================================= */

Federation::Starfleet::Ensign::Ensign(std::string name)
{
  this->_name = name;
  std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

/* ========================================= */

Federation::Starfleet::Captain::Captain(std::string name)
{
  this->_age = 0;
  this->_name = name;
}

std::string	Federation::Starfleet::Captain::getName()
{
  return this->_name;
}

int		Federation::Starfleet::Captain::getAge()
{
  return this->_age;
}

void		Federation::Starfleet::Captain::setAge(int age)
{
  this->_age = age;
}

