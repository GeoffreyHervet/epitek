//
// AEnemy.hh for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 11:19:40 2012 geoffrey hervet
// Last update Fri Jan 13 11:19:40 2012 geoffrey hervet
//

#include		<string>

#ifndef   __AENEMY_HH__
# define  __AENEMY_HH__

class			AEnemy
{
  int			_hp;
  std::string		_type;
  public:
    AEnemy(int hp, std::string const &type);
    virtual ~AEnemy();

    std::string const	&getType() const;
    int			getHP() const;

    virtual void	takeDamage(int);

    bool		canDoAction() const;
};

#endif     /* !__AENEMY_HH__ */
