//
// Toy.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d13-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 16 09:26:54 2012 geoffrey hervet
// Last update Mon Jan 16 09:26:54 2012 geoffrey hervet
//

#include	<iostream>
#include	<fstream>

#include	"Toy.h"

Toy::Toy()
  : _type(BASIC_TOY),
  _name("toy"),
  _ascii("")
{
  this->setError();
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &fileName)
  : _type(type),
  _name(name),
  _ascii("")
{
  this->setAscii(fileName);
  this->setError();
}
Toy::~Toy()
{
}

bool		Toy::setError(const std::string &wath, const std::string &where, Toy::Error::ErrorType type)
{
  this->_error.type = type;
  this->_error.set(wath, where);

  return false;
}

Toy::Toy(const Toy&t)
{
  if (this != &t)
  {
    this->_type = t.getType();
    this->_name = t.getName();
    this->_ascii = t.getAscii();
  }
}

Toy			&Toy::operator=(const Toy &t)
{
  if (this != &t)
  {
    this->_type = t.getType();
    this->_name = t.getName();
    this->_ascii = t.getAscii();
  }
  return *this;
}

bool		Toy::setAscii(const std::string &fileName)
{
  std::ifstream	file;
  char		buf[255];

  this->_ascii = "";
  buf[0] = 0;
  file.open(fileName.c_str(), std::ifstream::out);

  if (false == file.is_open())
  {
    this->_ascii = "ERROR";
    return this->setError("bad new illustration", __FUNCTION__, Toy::Error::PICTURE);
  }
  while (!file.eof())
  {
    file.read(buf, 254);
    buf[file.gcount()] = 0;
    this->_ascii += (std::string) buf;
  }
  file.close();
  return true;
}

std::ostream		&operator<<(std::ostream &os, const Toy &t)
{
  os << t.getName() << std::endl
    << t.getAscii() << std::endl;
  return os;
}

Toy			&Toy::operator<<(std::string const &_ascii)
{
  this->_ascii = _ascii;
  return *this;
}
