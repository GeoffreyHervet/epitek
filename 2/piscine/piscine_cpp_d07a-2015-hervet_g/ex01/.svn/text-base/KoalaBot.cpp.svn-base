//
// KoalaBot.cpp for ex01 in /home/hervet_g/piscine/piscine_cpp_d07a-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 19:07:09 2012 geoffrey hervet
// Last update Tue Jan 10 19:07:09 2012 geoffrey hervet
//

#include	<iostream>

#include	"Parts.h"
#include	"KoalaBot.h"

KoalaBot::KoalaBot(const std::string serial)
  : _serial(serial)
{
}

void	KoalaBot::setParts(const Arms &obj)
{
  this->_arms = obj;
}

void	KoalaBot::setParts(const Legs &obj)
{
  this->_legs = obj;
}

void	KoalaBot::setParts(const Head &obj)
{
  this->_head = obj;
}


void	KoalaBot::swapParts(Arms &obj)
{
  Arms	&tmp = this->_arms;
  this->_arms = obj;
  obj = tmp;
}

void	KoalaBot::swapParts(Legs &obj)
{
  Legs	&tmp = this->_legs;
  this->_legs = obj;
  obj = tmp;
}

void	KoalaBot::swapParts(Head &obj)
{
  Head	&tmp = this->_head;
  this->_head = obj;
  obj = tmp;
}

void	KoalaBot::informations(void)
{
  std::cout << "[KoalaBot] " << this->_serial << std::endl;

  this->_arms.informations();
  this->_legs.informations();
  this->_head.informations();
}

bool	KoalaBot::status(void)
{
  return this->_arms.isFunctionnal()
    && this->_legs.isFunctionnal()
    && this->_head.isFunctionnal();
}
