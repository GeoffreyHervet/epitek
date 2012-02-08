/*
** EventManager.h for ex02 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 19 14:35:49 2012 geoffrey hervet
** Last update Thu Jan 19 14:35:49 2012 geoffrey hervet
*/

#ifndef   __EVENTMANAGER_H__
# define  __EVENTMANAGER_H__

# include	<list>

# include	"Event.h"

class		EventManager
{
  std::list		<Event>_list;
  unsigned int		_time;

  public:
    EventManager();
    ~EventManager();
    EventManager(EventManager const &);
    EventManager	&operator=(EventManager const &);

    void		addEvent(const Event &);
    void		removeEventsAt(unsigned int);

    void		dumpEvents(void) const;
    void		dumpEventAt(unsigned int) const;

    void		addTime(unsigned int);
    void		addEventList(std::list<Event> &);
};

#endif     /* !__EVENTMANAGER_H__ */
