//
// main.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d06-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 09 13:19:51 2012 geoffrey hervet
// Last update Mon Jan 09 13:19:51 2012 geoffrey hervet
//

#include	<iostream>
#include	<iomanip>

#include	"sickkoala.h"

int		main()
{
  SickKoala	koal("IgiX");

  koal.poke();
  std::cout << std::boolalpha << koal.takeDrug("mars") << std::endl;
  std::cout << std::boolalpha << koal.takeDrug("mArs") << std::endl;
  std::cout << std::boolalpha << koal.takeDrug("maRs") << std::endl;
  std::cout << std::boolalpha << koal.takeDrug("marS") << std::endl;
  std::cout << std::boolalpha << koal.takeDrug("MARS") << std::endl;
  std::cout << std::boolalpha << koal.takeDrug("TOTO") << std::endl;

  koal.overDrive(" Kreog ! Ca boume ?");
  koal.overDrive("Kreog ! Ca boume ?");
  koal.overDrive(" _K_reog ! Ca boume ?");
  koal.overDrive(" Kreog Kreog ! Ca boume ?");


  return 0;
}
