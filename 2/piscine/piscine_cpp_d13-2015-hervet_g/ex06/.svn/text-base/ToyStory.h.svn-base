/*
** ToyStory.h for ex06 in /home/hervet_g/piscine/piscine_cpp_d13-2015-hervet_g/ex06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Jan 16 14:15:05 2012 geoffrey hervet
** Last update Mon Jan 16 14:15:05 2012 geoffrey hervet
*/

#include		<iostream>
#include		<string>

#include		"Toy.h"

#ifndef   __TOYSTORY_H__
# define  __TOYSTORY_H__

class		ToyStory
{
  public:
    static bool	tellMeAStory(std::string const &fileName,
    Toy &toy1, bool (Toy::*speak1)(std::string const &),
    Toy &toy2, bool (Toy::*speak2)(std::string const &));
  protected:
    static bool error(const Toy::Error &e){
      std::cout << e.where() << ": " << e.what() << std::endl;
      return false;
    };
};

#endif     /* !__TOYSTORY_H__ */
