//
// PowerFist.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 11:16:01 2012 geoffrey hervet
// Last update Fri Jan 13 11:16:01 2012 geoffrey hervet
//

#include		<iostream>

#include		"PowerFist.hh"

PowerFist::PowerFist()
  : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void			PowerFist::attack() const
{
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
