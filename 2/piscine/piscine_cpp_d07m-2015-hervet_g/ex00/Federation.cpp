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
