//
// Event.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 14:35:35 2012 geoffrey hervet
// Last update Thu Jan 19 14:35:35 2012 geoffrey hervet
//

#include	"Event.h"

Event::Event(const Event &e)
{
  if (this != &e)
  {
    this->_event = e.getEvent();
    this->_time  = e.getTime();
  }
}

Event::~Event()
{
}

Event		&Event::operator=(const Event &e)
{
  if (this != &e)
  {
    this->_event = e.getEvent();
    this->_time  = e.getTime();
  }
  return *this;
}

std::ostream	&operator<<(std::ostream &os, const Event &e)
{
  os << e.getTime() << ": " << e.getEvent();
  return os;
}

