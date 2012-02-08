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
#include		"Buzz.h"
#include		"Woody.h"

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
  {
    std::cout << "Bas Story" << std::endl;
    return false;
  }

  while (!file.eof())
  {
    file.getline(buf, 4095);
    line = buf;
    if (line.empty()) return true;
    if (std::string::npos != line.find("picture:"))
    {
      if (play[pos].setAscii(line.substr(8)) == false)
        return ToyStory::error(play[pos].getLastError());
      std::cout << play[pos].getAscii() << std::endl;
      continue;
    }

    if (false == (play[pos].*f[pos])(line))
      return ToyStory::error(play[pos].getLastError());

    // std::cout << "type : " << ((play[pos].getType() == 2) ? "buzz" : "woodi") << std::endl;
    pos = !pos;
  }
  return true;
}
