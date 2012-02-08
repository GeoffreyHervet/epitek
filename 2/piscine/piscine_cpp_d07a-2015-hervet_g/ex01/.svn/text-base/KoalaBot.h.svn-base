/*
** KoalaBot.h for ex01 in /home/hervet_g/piscine/piscine_cpp_d07a-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Jan 10 19:07:03 2012 geoffrey hervet
** Last update Tue Jan 10 19:07:03 2012 geoffrey hervet
*/

#include	<string>

#include	"Parts.h"

#ifndef   __KOALABOT_H__
# define  __KOALABOT_H__

class		KoalaBot
{
  Arms			_arms;
  Legs			_legs;
  Head			_head;
  std::string		_serial;

  public:
    KoalaBot(const std::string serial = "Bob-01");
    void		swapParts(Arms &);
    void		swapParts(Legs &);
    void		swapParts(Head &);
    void		setParts(const Arms &);
    void		setParts(const Legs &);
    void	  	setParts(const Head &);
    void		informations(void);
    bool		status(void);
};

#endif     /* !__KOALABOT_H__ */
