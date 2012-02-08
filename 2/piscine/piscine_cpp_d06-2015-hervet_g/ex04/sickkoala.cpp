//
// sickkoala.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d06-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 09 13:07:06 2012 geoffrey hervet
// Last update Mon Jan 09 13:07:06 2012 geoffrey hervet
//

#include	<string>
#include	<cstring>
#include	<iostream>

#include	"sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala::~SickKoala()
{
  std::cout << "Mr." << this->name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}

void		SickKoala::poke()
{
  std::cout << "Mr." << this->name << ": Gooeeeeerrk !! :'(" << std::endl;
}

bool		SickKoala::takeDrug(std::string drug)
{
  if (!strcasecmp(drug.c_str(), ((std::string)("mars")).c_str()) || drug == "Buronzand")
  {
    std::cout << "Mr." << this->name << ": "
              << ((drug == "Buronzand") ? "Et la fatigue a fait son temps !" : " Mars, et ca Kreog !")
              << std::endl;
    return true;
  }
  std::cout << "Mr." << this->name << ":  Goerk !" << std::endl;
  return false;
}

void		SickKoala::overDrive(std::string str)
{
  while (std::string::npos != str.find("Kreog"))
    str.replace(str.find("Kreog"), 5, (std::string)"1337");
  std::cout << "Mr." << this->name << ": " << str << std::endl;
}

std::string	SickKoala::getName(void)
{
  return this->name;
}
