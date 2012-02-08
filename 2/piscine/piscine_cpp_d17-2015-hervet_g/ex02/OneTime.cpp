//
// OneTime.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d17-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 20 10:50:09 2012 geoffrey hervet
// Last update Fri Jan 20 10:50:09 2012 geoffrey hervet
//

#include	<iostream>

#include	"OneTime.h"

void		OneTime::encryptChar(char c)
{
  if (c >= 'A' && c <= 'Z')
    c = (c - 'A' - 'a' + this->_key[this->_idxCr]) % 26 + 'A';
  else if (c >= 'a' && c <= 'z')
    c = (c - 2 * 'a' + this->_key[this->_idxCr]) % 26 + 'a';
  std::cout << c;
  this->_idxCr = (this->_idxCr + 1) % this->_key.size();
}

static int tmp(int i)
{
  i %= 26;
  if (i >= 0)
    return i;
  return 26 + i;
}

void		OneTime::decryptChar(char c)
{
  if (c >= 'A' && c <= 'Z')
    c = tmp(c - 'A' - this->_key[this->_idxDe] + 'a') + 'A';
  else if (c >= 'a' && c <= 'z')
    c = tmp(c - 'a' - this->_key[this->_idxDe] + 'a') + 'a';
  std::cout << c;
  this->_idxDe = (this->_idxDe + 1) % this->_key.size();
}
