//
// Sorcerer.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 09:59:00 2012 geoffrey hervet
// Last update Fri Jan 13 09:59:00 2012 geoffrey hervet
//

#include	<iostream>

#include	"Sorcerer.hh"

Sorcerer::Sorcerer(std::string const &name, std::string const &title)
  : _name(name),
    _title(title)
{
  std::cout << this->getName() << ", "
    << this->getTitle() << ", is born !"
    << std::endl;
}

Sorcerer::~Sorcerer()
{
  std::cout << this->getName() << ", "
    << this->getTitle() << ", is dead. Consequences will never be the same !"
    << std::endl;
}

const std::string	&Sorcerer::getTitle(void) const
{
  return this->_title;
}

const std::string	&Sorcerer::getName(void) const
{
  return this->_name;
}

std::ostream		&operator<<(std::ostream &os, const Sorcerer &c)
{
  os << "I am " << c.getName() << ", " << c.getTitle() << ", and I like ponies !" << std::endl;
  return os;
}

void			Sorcerer::polymorph(Victim const &v) const
{
  v.getPolymorphed();
}
