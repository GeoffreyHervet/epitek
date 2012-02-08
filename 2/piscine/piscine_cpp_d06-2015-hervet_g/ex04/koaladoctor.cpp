//
// koaladoctor.cpp for ex04 in /home/hervet_g/piscine/piscine_cpp_d06-2015-hervet_g/ex04
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 09 18:20:03 2012 geoffrey hervet
// Last update Mon Jan 09 18:20:03 2012 geoffrey hervet
//

#include	<cstdlib>
#include	<string>
#include	<iostream>
#include	<fstream>

#include	"koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
  this->name = name;
  this->is_working = 0;
  std::cout << "Dr." << this->name << ": Je suis le Dr." << this->name << " ! Comment Kreoggez-vous ?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{

  if (this->is_working)
    this->timeCheck();
}

void		KoalaDoctor::diagnose(SickKoala *koala)
{
  std::ofstream	file;
  std::string	fileName;
  std::string	drugs [] =
  {
    "mars",
    "Buronzand",
    "Viagra",
    "Extasy",
    "Feuille d'eucalyptus"
  };

  if (!this->is_working)
    this->timeCheck();

  fileName = koala->getName() + ".report";
  file.open(fileName.c_str(), std::ios::out | std::ios::trunc);
  if (file)
  {
    std::cout << "Dr." << this->name << ": Alors, qu’est-ce qui vous goerk, Mr." << koala->getName() << " ?" << std::endl;
    koala->poke();

    file << drugs[random() % 5] << std::endl;
    file.close();
  }
}

void		KoalaDoctor::timeCheck(void)
{
  std::cout << "Dr." << this->name << ":" << ((this->is_working) ? " Je rentre dans ma foret d’eucalyptus !" : ": Je commence le travail !") << std::endl;
  this->is_working = !this->is_working;
}
