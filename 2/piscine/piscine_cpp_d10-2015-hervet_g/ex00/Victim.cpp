//
// Victim.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 10:08:31 2012 geoffrey hervet
// Last update Fri Jan 13 10:08:31 2012 geoffrey hervet
//

#include	<iostream>

#include	"Victim.hh"

Victim::Victim(std::string const &name)
  : _name(name)
{
  std::cout << "Some random victim called " << this->getName()
    << " just popped !" << std::endl;
}

Victim::~Victim()
{
  std::cout << "Victim " << this->getName()
    << " just died for no apparent reason !" << std::endl;
}

const std::string	&Victim::getName(void) const
{
  return this->_name;
}

std::ostream		&operator<<(std::ostream &os, const Victim &c)
{
  os << "I'm " << c.getName() << " and i like otters !" << std::endl;
  return os;
}

void			Victim::getPolymorphed() const
{
  std::cout << this->getName()
    << " has been turned into a cute little sheep !" << std::endl;
}
