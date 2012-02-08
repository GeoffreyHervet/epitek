/*
** Ratatouille.h for ex04 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 19 21:47:27 2012 geoffrey hervet
** Last update Thu Jan 19 21:47:27 2012 geoffrey hervet
*/

#ifndef   __RATATOUILLE_H__
# define  __RATATOUILLE_H__

# include	<string>
# include	<iostream>
# include	<sstream>

class		Ratatouille
{
    std::ostringstream	s;

  public:
    Ratatouille() {};
    Ratatouille(Ratatouille const &r);
    ~Ratatouille() {};
    Ratatouille		&operator=(const Ratatouille &);

    Ratatouille		&addVegetable(unsigned char c) { this->s << c; return *this;};
    Ratatouille		&addCondiment(unsigned int i) { this->s << i; return *this;};
    Ratatouille		&addSpice(double d) { this->s << d; return *this;};
    Ratatouille		&addSauce(const std::string &s) { this->s << s; return *this;};

    std::string		kooc(void) const;
};

#endif     /* !__RATATOUILLE_H__ */
