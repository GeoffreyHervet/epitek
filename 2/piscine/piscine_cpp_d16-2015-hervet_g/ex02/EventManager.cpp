//
// EventManager.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 14:35:55 2012 geoffrey hervet
// Last update Thu Jan 19 14:35:55 2012 geoffrey hervet
//

#include	<iostream>

#include	"EventManager.h"

static unsigned int glob_t = 0;
static bool predicate(const Event &a, const Event &b)
{
  return a.getTime() < b.getTime();
}

static bool deleteAtTime(const Event &e)
{
  return e.getTime() == glob_t;
}

static bool deleteTimeLess(const Event &e)
{
  return e.getTime() <= glob_t;
}

EventManager::EventManager() : _list(), _time(0) { }

EventManager::~EventManager() { }

EventManager::EventManager(EventManager const &) { }

EventManager		&EventManager::operator=(EventManager const &) { return *this; }

void			EventManager::addEvent(const Event &e)
{
  if (e.getTime() >= this->_time)
  {
    this->_list.push_back(e);
    this->_list.sort(predicate);
  }
}

void			EventManager::removeEventsAt(unsigned int t)
{
  glob_t = t;
  this->_list.remove_if(deleteAtTime);
}

void			EventManager::dumpEvents() const
{
  if (!this->_list.empty())
  {
    std::list<Event>::const_iterator	it = this->_list.begin();
    while (it != this->_list.end())
    {
      std::cout << *it << std::endl;
      ++it;
    }
  }
}

void			EventManager::dumpEventAt(unsigned int t) const
{
  if (!this->_list.empty())
  {
    std::list<Event>::const_iterator	it = this->_list.begin();
    while (it != this->_list.end())
    {
      if ((*it).getTime() > t)
        break;
      if ((*it).getTime() == t)
        std::cout << *it << std::endl;
      ++it;
    }
  }
}

void			EventManager::addTime(unsigned int t)
{
  if (!this->_list.empty())
  {
    std::list<Event>::iterator	it = this->_list.begin();
    while (it != this->_list.end())
    {
      if ((*it).getTime() > (this->_time + t))
        break;
      if ((*it).getTime() > this->_time) // >= ?
        std::cout << (*it).getEvent() << std::endl;
      ++it;
    }
  }

  this->_time += t;
  glob_t = this->_time;
  this->_list.remove_if(deleteTimeLess);
}

void			EventManager::addEventList(std::list<Event> &orig)
{
  std::list<Event>::iterator it = orig.begin();
  while (it != orig.end())
  {
    this->_list.push_front(*it);
    ++it;
  }
  this->_list.sort(predicate);
  glob_t = this->_time;
  this->_list.remove_if(deleteTimeLess);
}
