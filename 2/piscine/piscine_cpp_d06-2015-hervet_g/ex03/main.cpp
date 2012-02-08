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
#include	"koalanurse.h"

int		main()
{
  SickKoala	koal("IgiX");
  KoalaNurse	nurse(42);

  koal.poke();
  std::cout << std::boolalpha << koal.takeDrug("mars") << std::endl;
  std::cout << std::boolalpha << koal.takeDrug("Buronzand") << std::endl;
  std::cout << std::boolalpha << koal.takeDrug("_Buronzand") << std::endl;

  nurse.timeCheck();
  koal.overDrive(" Kreog Kreog ! Ca boume ?");

  nurse.giveDrug("mars", &koal);
  nurse.timeCheck();
  nurse.timeCheck();
  return 0;
}
