/*
** koaladoctor.h for ex04 in /home/hervet_g/piscine/piscine_cpp_d06-2015-hervet_g/ex04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Jan 09 18:20:10 2012 geoffrey hervet
** Last update Mon Jan 09 18:20:10 2012 geoffrey hervet
*/

#ifndef   __KOALADOCTOR_H__
# define  __KOALADOCTOR_H__

#include	<string>

#include	"sickkoala.h"

class		KoalaDoctor
{
  std::string	name;
  bool		is_working;

  public:
    KoalaDoctor(std::string);
    ~KoalaDoctor();
    void	diagnose(SickKoala *);
    void	timeCheck(void);
};

#endif     /* !__KOALADOCTOR_H__ */
