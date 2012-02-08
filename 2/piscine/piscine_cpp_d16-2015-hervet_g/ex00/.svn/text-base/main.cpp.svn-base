//
// main.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 10:15:49 2012 geoffrey hervet
// Last update Thu Jan 19 10:15:49 2012 geoffrey hervet
//

#include	<iostream>

#include	"Parser.h"

int	main()
{
  Parser p;

  p.feed("((54 / 2) + 126) * ((1865 % 16) - 42)");
  std::cout << p.result() << std::endl;
  p.reset();
  p.feed("((12*2)+14)");
  std::cout << p.result() << std::endl;
  p.feed("((17 % 9) / 4)");
  std::cout << p.result() << std::endl;
  p.reset();
  p.feed("(17 - 4) * 13");
  std::cout << p.result() << std::endl;
  return 0;
}
