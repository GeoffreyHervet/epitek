//
// main.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 10:28:31 2012 geoffrey hervet
// Last update Fri Jan 13 10:28:31 2012 geoffrey hervet
//

#include	<iostream>

#include	"Sorcerer.hh"
#include	"Victim.hh"
#include	"Peon.hh"

int		main()
{
  Sorcerer robert("Robert", "the Magnificent");

  Victim jim("Jimmy");
  Peon joe("Joe");

  std::cout << robert << jim << joe;

  robert.polymorph(jim);
  robert.polymorph(joe);

  return 0;
}
