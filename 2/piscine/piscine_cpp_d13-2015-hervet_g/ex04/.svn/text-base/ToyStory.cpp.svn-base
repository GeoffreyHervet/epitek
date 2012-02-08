// ToyStory.cpp for ex06 in /home/hervet_g/piscine/piscine_cpp_d13-2015-hervet_g/ex06
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 16 14:14:52 2012 geoffrey hervet
// Last update Mon Jan 16 14:14:52 2012 geoffrey hervet
//

#include	<cstring>

#include	<string>
#include	<iostream>
#include	<fstream>
#include	<iomanip>

#include		"ToyStory.h"

bool			ToyStory::tellMeAStory(std::string const &fileName,
    Toy &toy1, bool (Toy::*speak1)(std::string const &),
    Toy &toy2, bool (Toy::*speak2)(std::string const &))
{
  std::ifstream	file;
  std::string	line;
  char		buf[4096];
  Toy		play[] = {toy1, toy2};
  bool		(Toy::*f[])(std::string const&) = {speak1, speak2};
  bool		pos = false;

  std::cout << toy1.getAscii() << std::endl << toy2.getAscii() << std::endl;

  file.open(fileName.c_str(), std::ifstream::out);
  if (false == file.is_open())
    return false;

  while (!file.eof())
  {
    file.getline(buf, 4095);
    line = buf;
    if (std::string::npos != line.find("picture:"))
    {
      if (play[pos].setAscii(line.substr(8)) == false)
        return ToyStory::error(play[pos].getLastError());
      std::cout << play[pos].getAscii() << std::endl;
      continue;
    }
    (play[pos].*f[pos])(line);
    pos = !pos;
  }
  return true;
}
