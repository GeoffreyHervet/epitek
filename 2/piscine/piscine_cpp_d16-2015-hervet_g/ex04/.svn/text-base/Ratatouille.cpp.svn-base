//
// Ratatouille.cpp for ex04 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex04
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 21:47:30 2012 geoffrey hervet
// Last update Thu Jan 19 21:47:30 2012 geoffrey hervet
//

#include	"Ratatouille.h"

std::string	Ratatouille::kooc(void) const
{
  return this->s.str();
}

Ratatouille	&Ratatouille::operator=(const Ratatouille &ss)
{
  this->s << ss.kooc();
  return *this;
}

Ratatouille::Ratatouille(Ratatouille const &ss)
{
  this->s << ss.kooc();
}
