/*
** Woody.h for ex02 in /home/hervet_g/piscine/piscine_cpp_d13-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Jan 16 10:49:50 2012 geoffrey hervet
** Last update Mon Jan 16 10:49:50 2012 geoffrey hervet
*/

#include		"Toy.h"

#ifndef   __WOODY_H__
# define  __WOODY_H__

class			Woody
  : public		  Toy

{
  public:
    Woody(std::string const &name, const std::string &fileName = "woody.txt");
    virtual ~Woody();

    virtual bool	speak(std::string const &sentence){ std::cout << "WOODY: "; Toy::speak(sentence); return true;};
};

#endif     /* !__WOODY_H__ */
