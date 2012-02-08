//
// Sorcerer.hh for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 09:46:36 2012 geoffrey hervet
// Last update Fri Jan 13 09:46:36 2012 geoffrey hervet
//

#ifndef   __SORCERER_HH__
# define  __SORCERER_HH__

#include	<string>

#include	"Victim.hh"

class			Sorcerer
{
  std::string		_name;
  std::string		_title;
  public:
    Sorcerer(std::string const &, std::string const &);
    ~Sorcerer();

    const std::string	&getName(void) const;
    const std::string	&getTitle(void) const;

    void		polymorph(Victim const &) const;
};

std::ostream		&operator<<(std::ostream &, const Sorcerer &);

#endif     /* !__SORCERER_HH__ */
