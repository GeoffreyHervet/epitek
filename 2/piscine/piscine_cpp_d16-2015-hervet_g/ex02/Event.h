/*
** Event.h for ex02 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 19 14:48:49 2012 geoffrey hervet
** Last update Thu Jan 19 14:48:49 2012 geoffrey hervet
*/

#ifndef   __EVENT_H__
# define  __EVENT_H__

# include	<iostream>
# include	<string>

class		Event
{
  unsigned int	_time;
  std::string	_event;

  public:
    Event(void) : _time(0), _event("") {};
    Event(unsigned int t, const std::string &e): _time(t), _event(e) {};
    ~Event(void);
    Event(const Event &);
    Event		&operator=(const Event &);

    unsigned int	getTime(void) const { return this->_time; };
    const std::string	&getEvent(void) const { return this->_event; };

    void		setTime(unsigned int t) { this->_time = t; };
    void		setEvent(const std::string &str) { this->_event = str; };
};

std::ostream	&operator<<(std::ostream &os, const Event &e);

#endif     /* !__EVENT_H__ */
