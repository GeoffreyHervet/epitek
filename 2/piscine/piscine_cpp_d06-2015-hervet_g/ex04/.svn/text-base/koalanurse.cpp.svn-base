//
// koalanurse.cpp for ex03 in /home/hervet_g/piscine/piscine_cpp_d06-2015-hervet_g/ex03
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 09 16:09:50 2012 geoffrey hervet
// Last update Mon Jan 09 16:09:50 2012 geoffrey hervet
//

#include	<fstream>
#include	<iomanip>
#include	<iostream>
#include	<string>

#include	"koalanurse.h"

KoalaNurse::KoalaNurse(unsigned int id)
{
  this->id = id;
  this->is_working = 0;
}

KoalaNurse::~KoalaNurse()
{
  if (this->is_working)
    this->timeCheck();
  std::cout << "Nurse " << this->id << ": Enfin un peu de repos !" << std::endl;
}

void		KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
  if (!this->is_working)
    this->timeCheck();

  koala->takeDrug(drug);
}

std::string	KoalaNurse::readReport(std::string fileName)
{
  std::ifstream	file;
  std::string	line = "";
  char		buf[1024];

  if (!this->is_working)
    this->timeCheck();

  if (std::string::npos == fileName.find(".report"))
    return line;

  buf[0] = 0;
  file.open(fileName.c_str(), std::ifstream::out);
  if (false == file.is_open() || file.eof())
    return line;

  file.getline(buf, 1024);
  line += buf;
  file.close();

  if (std::string::npos != line.find("\n"))
    line.replace(line.find("\n"), 1, (std::string)"\0");

  std::cout << "Nurse " << this->id << ": Kreog ! Il faut donner un " << line << " a Mr." << fileName.substr(0, fileName.size() - 7) << " !" << std::endl;
  return line;
}

void		KoalaNurse::timeCheck(void)
{
  std::cout << "Nurse " << this->id << ((this->is_working) ? " Je rentre dans ma foret d’eucalyptus !" : ": Je commence le travail !") << std::endl;
  this->is_working = !this->is_working;
}
