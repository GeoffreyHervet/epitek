//
// DomesticKoala.cpp for ex01 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 13:33:54 2012 geoffrey hervet
// Last update Thu Jan 19 13:33:54 2012 geoffrey hervet
//

#include	"DomesticKoala.h"

DomesticKoala::DomesticKoala(KoalaAction &k)
  : _vect(0xFF),
    _koal(k)
{
}

DomesticKoala::DomesticKoala(const DomesticKoala &d)
{
  if (this != &d)
  {
    this->_vect = d.getVect();
    this->_koal = d.getKoal();
  }
}

DomesticKoala	&DomesticKoala::operator=(const DomesticKoala &d)
{
  if (this != &d)
  {
    this->_vect = d.getVect();
    this->_koal = d.getKoal();
  }
  return *this;
}

void		DomesticKoala::learnAction(unsigned char c, DomesticKoala::methodPointer_t f)
{
  this->_vect[c] = f;
}

void		DomesticKoala::unlearnAction(unsigned char c)
{
  this->_vect[c] = NULL;
}

void		DomesticKoala::doAction(unsigned char c, const std::string &str)
{
  if (this->_vect[c] != NULL)
    ((this->_koal).*(this->_vect[c]))(str);
}

void		DomesticKoala::setKoalaAction(KoalaAction &k)
{
  std::vector<DomesticKoala::methodPointer_t> vect(0);

  this->_vect = vect;
  this->_koal = k;
}
