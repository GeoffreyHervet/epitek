//
// main.cpp for ex01 in /home/hervet_g/piscine/piscine_cpp_d06-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 09 12:38:06 2012 geoffrey hervet
// Last update Mon Jan 09 12:38:06 2012 geoffrey hervet
//

#include	<iostream>
#include	<string>

int		main()
{
  float		temp;
  std::string	type;

  std::cin >> temp >> type;

  if (type == "Celsius")
  {
    type = "Fahrenheit";
    temp = temp / 5.0 * 9.0 + 32;
    std::cout.width(16);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(3);
    std::cout << temp;
    std::cout.width(16);
    std::cout << type << std::endl;
  }
  else if (type == "Fahrenheit")
  {
    type = "Celsius";
    temp = 5.0 / 9.0 * ( temp - 32 );
    std::cout.width(16);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(3);
    std::cout << temp;
    std::cout.width(16);
    std::cout << type << std::endl;
  }

  return 0;
}
