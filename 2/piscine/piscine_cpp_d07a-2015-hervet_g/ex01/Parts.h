/*
** Parts.h for ex01 in /home/hervet_g/piscine/piscine_cpp_d07a-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Jan 10 18:51:33 2012 geoffrey hervet
** Last update Tue Jan 10 18:51:33 2012 geoffrey hervet
*/

#include		<string>

#ifndef   __PARTS_H__
# define  __PARTS_H__

class			Arms
{
  bool			_functionnal;
  std::string		_serial;

  public:
    Arms(const std::string & serial = "A-01", bool functionnal = true);
    bool		isFunctionnal(void);
    std::string		serial(void);
    void		informations(void);
};

class			Legs
{
  bool			_functionnal;
  std::string		_serial;

  public:
    Legs(const std::string &serial = "L-01", bool functionnal = true);
    bool		isFunctionnal(void);
    std::string		serial(void);
    void		informations(void);
};

class			Head
{
  bool			_functionnal;
  std::string		_serial;

  public:
    Head(const std::string &serial = "H-01", bool functionnal = true);
    bool		isFunctionnal(void);
    std::string		serial(void);
    void		informations(void);
};

#endif     /* !__PARTS_H__ */
