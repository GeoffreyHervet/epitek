//
// Encryption.cpp for ex03 in /home/hervet_g/piscine/piscine_cpp_d17-2015-hervet_g/ex03
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 20 15:06:58 2012 geoffrey hervet
// Last update Fri Jan 20 15:06:58 2012 geoffrey hervet
//

#include <iostream>
#include <algorithm>
#include <vector>

#include	"Encryption.h"

void		Encryption::operator()(char c)
{
  return (this->_method->*(this->_handler))(c);
}

// Encryption(IEncryptionMethod &iem, Encryption::IEHandler_t e)
Encryption::Encryption(IEncryptionMethod &iem, void (IEncryptionMethod::*h)(char))
  : _handler(h),
    _method(&iem)
{
};

void		Encryption::encryptString(IEncryptionMethod& encryptionMethod, std::string const& toEncrypt)
{
  Encryption e(encryptionMethod, &IEncryptionMethod::encryptChar);

  encryptionMethod.reset();
  std::for_each(toEncrypt.begin(), toEncrypt.end(), e);
  std::cout << std::endl;
}

void		Encryption::decryptString(IEncryptionMethod& encryptionMethod, std::string const& toDecrypt)
{
  Encryption e(encryptionMethod, &IEncryptionMethod::decryptChar);

  encryptionMethod.reset();
  std::for_each(toDecrypt.begin(), toDecrypt.end(), e);
  std::cout << std::endl;
}
