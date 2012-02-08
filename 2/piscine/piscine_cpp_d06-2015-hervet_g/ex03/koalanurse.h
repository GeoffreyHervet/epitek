/*
** koalanurse.h for ex03 in /home/hervet_g/piscine/piscine_cpp_d06-2015-hervet_g/ex03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Jan 09 16:06:09 2012 geoffrey hervet
** Last update Mon Jan 09 16:06:09 2012 geoffrey hervet
*/

#ifndef   __KOALANURSE_H__
# define  __KOALANURSE_H__

#include	<string>

#include	"sickkoala.h"

class		KoalaNurse
{
  unsigned int	id;
  bool		is_working;

  public:
    KoalaNurse(unsigned int id);
    ~KoalaNurse();
    void		giveDrug(std::string, SickKoala *);
    std::string		readReport(std::string);
    void		timeCheck(void);
};

#endif     /* !__KOALANURSE_H__ */
