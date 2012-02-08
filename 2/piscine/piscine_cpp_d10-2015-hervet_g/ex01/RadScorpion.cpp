//
// RadScorpion.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 12:38:58 2012 geoffrey hervet
// Last update Fri Jan 13 12:38:58 2012 geoffrey hervet
//

#include		<iostream>

#include		"RadScorpion.hh"

RadScorpion::RadScorpion()
  : AEnemy(80, "RadScorpion")
{
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
  std::cout << "* SPROTCH *" << std::endl;
}
