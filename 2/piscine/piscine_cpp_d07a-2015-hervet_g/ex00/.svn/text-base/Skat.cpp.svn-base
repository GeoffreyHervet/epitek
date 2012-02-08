//
// Skat.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d07a-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 17:40:35 2012 geoffrey hervet
// Last update Tue Jan 10 17:40:35 2012 geoffrey hervet
//

#include	<iostream>

#include	"Skat.h"

Skat::Skat(std::string const &name, int stimPaks)
  	: _name(name), _stimPaks(stimPaks)
{
}

Skat::~Skat()
{
}

int&		Skat::stimPaks()
{
  return this->_stimPaks;
}

const std::string& Skat::name(void) const
{
  return this->_name;
}

void		Skat::shareStimPaks(int number, int &stock)
{
  if (this->_stimPaks < number)
    std::cout << "Don't be greedy" << std::endl;
  else
  {
    stock += number;
    this->_stimPaks -= number;
    std::cout << "Keep the change." << std::endl;
  }
}

void		Skat::addStimPaks(unsigned int number)
{
  this->_stimPaks += number;
  if (!number)
    std::cout << "Hey boya, did you forget something ?" << std::endl;
}

void		Skat::useStimPaks(void)
{
  if (!(this->_stimPaks))
    std::cout << "Mediiiiiic" << std::endl;
  else
  {
    this->_stimPaks--;
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
  }
}

void		Skat::status(void)
{
  std::cout << "Soldier " << this->_name <<
    " reporting " << this->_stimPaks <<
    " stimpaks remaining sir !" << std::endl;
}

