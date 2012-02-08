//
// Picture.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d13-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 16 09:26:36 2012 geoffrey hervet
// Last update Mon Jan 16 09:26:36 2012 geoffrey hervet
//

#include	<iostream>
#include	<fstream>

#include	"Picture.h"

Picture::Picture(const std::string &fileName)
  : data("")
{
  std::ifstream	file;
  char		buf[255];

  buf[0] = 0;
  file.open(fileName.c_str(), std::ifstream::out);

  if (true == file.is_open())
  {
    while (!file.eof())
    {
      file.read(buf, 254);
      buf[file.gcount()] = 0;
      this->data += (std::string) buf;
    }
    file.close();
  }
}

Picture::~Picture()
{
}

Picture::Picture(const Picture&p)
{
  if (this != &p)
  {
    this->data = p.data;
  }
}

Picture			&Picture::operator=(const Picture &p)
{
  if (this != &p)
  {
    this->data = p.data;
  }
  return *this;
}
