/*
** Buzz.h for ex02 in /home/hervet_g/piscine/piscine_cpp_d13-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Jan 16 10:31:39 2012 geoffrey hervet
** Last update Mon Jan 16 10:31:39 2012 geoffrey hervet
*/

#include		"Toy.h"

#ifndef   __BUZZ_H__
# define  __BUZZ_H__

class			Buzz
  : public		  Toy
{

  public:
    Buzz(std::string const &name, const std::string &fileName = "buzz.txt");
    virtual ~Buzz();

    virtual bool	speak(std::string const &sentence){ std::cout << "BUZZ: "; Toy::speak(sentence); return true;};
    virtual bool	speak_es(std::string const &sentence){ std::cout << "BUZZ: senorita \"" << sentence << "\" senorita" << std::endl; return true; };
};

#endif     /* !__BUZZ_H__ */
