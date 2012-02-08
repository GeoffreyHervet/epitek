//
// main.cpp for ex06 in /home/hervet_g/piscine/piscine_cpp_d15-2015-hervet_g/ex06
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Wed Jan 18 14:40:08 2012 geoffrey hervet
// Last update Wed Jan 18 14:40:08 2012 geoffrey hervet
//

#include	<iostream>
#include	<string>

#include	"ex06.hpp"

int	main()
{
  Tuple<int, std::string> a;
  a.a = 12;
  a.b = "12";
  std::cout << a.toString() << std::endl;

  Tuple<float> b;
  b.a = 12;
  b.b = 1.1f;
  std::cout << b.toString() << std::endl;

  Tuple<char> c;
  c.a = 12;
  c.b = 42;
  std::cout << c.toString() << std::endl;
  return 0;
}
