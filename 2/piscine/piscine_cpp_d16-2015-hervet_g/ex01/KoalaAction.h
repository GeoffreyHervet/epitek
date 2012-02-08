/*
** KoalaAction.h for ex01 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 19 13:37:12 2012 geoffrey hervet
** Last update Thu Jan 19 13:37:12 2012 geoffrey hervet
*/

#ifndef   __KOALAACTION_H__
# define  __KOALAACTION_H__

# include	<string>
# include	<iostream>

class		KoalaAction
{
  public:
    KoalaAction(){};

    void	eat(const std::string &s){ std::cout << "Je mange: " << s << std::endl; };
    void	sleep(const std::string &s) { std::cout << "Je dors et je reve de: " <<  s << std::endl; };
    void	goTo(const std::string &s) { std::cout << "Je vais a: " << s << std::endl; };
    void	reproduce(const std::string &s) { std::cout << "Je tente de me reproduire avec:" << s << std::endl; };
};

#endif     /* !__KOALAACTION_H__ */
