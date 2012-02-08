//
// Warpsystem.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d07m-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 11:23:08 2012 geoffrey hervet
// Last update Tue Jan 10 11:23:08 2012 geoffrey hervet
//

#include	"Warpsystem.hh"

/* ========================================= */

WarpSystem::QuantumReactor::QuantumReactor(bool stability)
{
  this->_stability = stability;
}

bool		WarpSystem::QuantumReactor::isStable(void)
{
  return this->_stability;
}

void		WarpSystem::QuantumReactor::setStability(bool stability)
{
  this->_stability = stability;
}

/* ========================================= */

WarpSystem::Core::Core(WarpSystem::QuantumReactor *ptr)
{
  this->_coreReactor = ptr;
}

WarpSystem::QuantumReactor	*WarpSystem::Core::checkReactor(void)
{
  return this->_coreReactor;
}
