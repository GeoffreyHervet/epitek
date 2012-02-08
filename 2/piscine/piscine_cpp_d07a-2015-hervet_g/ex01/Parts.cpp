//
// Parts.cpp for ex01 in /home/hervet_g/piscine/piscine_cpp_d07a-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 18:51:38 2012 geoffrey hervet
// Last update Tue Jan 10 18:51:38 2012 geoffrey hervet
//

#include	<iostream>
#include	<iomanip>

#include	"Parts.h"

Arms::Arms(std::string const &serial, bool functionnal)
	: _serial(serial)
{
  this->_functionnal = functionnal;
}

bool		Arms::isFunctionnal(void)
{
  return this->_functionnal;
}

std::string	Arms::serial(void)
{
  return this->_serial;
}

void		Arms::informations(void)
{
  std::cout << "[Parts] Arms " <<
    this->_serial << " status  : " <<
    ((this->_functionnal == true) ? "OK" : "KO")
    << std::endl;
}

Legs::Legs(std::string const &serial, bool functionnal)
	: _serial(serial)
{
  this->_functionnal = functionnal;
}

bool		Legs::isFunctionnal(void)
{
  return this->_functionnal;
}

std::string	Legs::serial(void)
{
  return this->_serial;
}

void		Legs::informations(void)
{
  std::cout << "[Parts] Legs " <<
    this->_serial << " status  : " <<
    ((this->_functionnal == true) ? "OK" : "KO")
    << std::endl;
}


Head::Head(std::string const &serial, bool functionnal)
	: _serial(serial)
{
  this->_functionnal = functionnal;
  this->_serial = serial;
}

bool		Head::isFunctionnal(void)
{
  return this->_functionnal;
}

std::string	Head::serial(void)
{
  return this->_serial;
}

void		Head::informations(void)
{
  std::cout << "[Parts] Head " <<
    this->_serial << " status  : " <<
    ((this->_functionnal == true) ? "OK" : "KO")
    << std::endl;
}


