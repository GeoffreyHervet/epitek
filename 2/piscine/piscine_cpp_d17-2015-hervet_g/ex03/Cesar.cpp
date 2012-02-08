//
// Cesar.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d17-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 20 10:49:53 2012 geoffrey hervet
// Last update Fri Jan 20 10:49:53 2012 geoffrey hervet
//

#include	<iostream>

#include	"Cesar.h"

void		Cesar::encryptChar(char c)
{
  if (c >= 'a' && c <= 'z')
    std::cout << (char)('a' + (c - 'a' + this->_decCr) % 26);
  else if (c >= 'A' && c <= 'Z')
    std::cout << (char)('A' + (c - 'A' + this->_decCr) % 26);
  else
    std::cout << c;
  this->_decCr++;
}

static int tmp(int i)
{
  if (i >= 0)
    return i;
  return 26 + i;
}

void		Cesar::decryptChar(char c)
{
  if (c >= 'a' && c <= 'z')
    std::cout << (char)('a' + tmp(c - 'a' - this->_decDe));
  else if (c >= 'A' && c <= 'Z')
    std::cout << (char)('A' + tmp(c - 'A' - this->_decDe));
  else
    std::cout << c;
  this->_decDe++;
}
