//
// droidmemory.cpp for ex01 in /home/hervet_g/piscine/piscine_cpp_d08-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Wed Jan 11 15:46:22 2012 geoffrey hervet
// Last update Wed Jan 11 15:46:22 2012 geoffrey hervet
//

#include	<stdlib.h>

#include	"droidmemory.hh"

DroidMemory::DroidMemory()
{
  this->_exp = 0;
  this->_fingerPrint = (size_t) random();
}

/* ===============================================================
*/

size_t		DroidMemory::getExp(void) const
{
  return this->_exp;
}

size_t		DroidMemory::getFingerPrint(void) const
{
  return this->_fingerPrint;
}

/* =============================================================== */

void		DroidMemory::setExp(const size_t &exp)
{
  this->_exp = exp;
}

void		DroidMemory::setFingerPrint(const size_t &fp)
{
  this->_fingerPrint = fp;
}

/* =============================================================== */

DroidMemory	&DroidMemory::operator<<(DroidMemory &item)
{
  this->_exp += item.getExp();
  item.setFingerPrint(item.getFingerPrint() ^ this->_fingerPrint);
  return *this;
}

DroidMemory	&DroidMemory::operator>>(DroidMemory &item)
{
  item.setExp(item.getExp() + this->_exp);
  this->_fingerPrint ^= item.getFingerPrint();
  return *this;
}

DroidMemory	&DroidMemory::operator+=(size_t exp)
{
  this->_exp += exp;
  this->_fingerPrint ^= exp;
  return *this;
}

DroidMemory	&DroidMemory::operator+=(DroidMemory &item)
{
  this->_exp += item.getExp();
  item.setFingerPrint(item.getFingerPrint() ^ this->_fingerPrint);
  return *this;
}

DroidMemory	operator+(const DroidMemory &a, const DroidMemory &b)
{
  DroidMemory	ret;

  ret.setFingerPrint(a.getFingerPrint() ^ b.getFingerPrint());
  ret.setExp(a.getExp() ^ b.getExp());
  return ret;
}

DroidMemory 	operator+(const size_t &exp, const DroidMemory &a)
{
  DroidMemory	ret;

  ret.setFingerPrint(a.getFingerPrint() ^ exp);
  ret.setExp(a.getExp() ^ exp);
  return ret;
}

DroidMemory 	operator+(const DroidMemory &a, const size_t &exp)
{
  DroidMemory	ret;

  ret.setFingerPrint(a.getFingerPrint() ^ exp);
  ret.setExp(a.getExp() ^ exp);
  return ret;
}

/* ===============================================================
 */

std::ostream&		operator<<(std::ostream &os, const DroidMemory &item)
{
  os << "DroidMemory '" << item.getFingerPrint()
     << "', " << item.getExp();
  return os;
}
