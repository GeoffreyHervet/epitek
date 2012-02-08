//
// Character.hh for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 13:17:57 2012 geoffrey hervet
// Last update Fri Jan 13 13:17:57 2012 geoffrey hervet
//

#include		<string>

#ifndef   __CHARACTER_HH__
# define  __CHARACTER_HH__

#include		"AWeapon.hh"
#include		"AEnemy.hh"

class			Character
{
  std::string		_name;
  int			_ap;
  AWeapon		*_weapon;

  public:
    Character(std::string const &name);
    Character(const Character &);
    Character &operator=(const Character &);
    ~Character();

    void		recoverAp();
    void		equip(AWeapon *);
    void		attack(AEnemy *);

    const std::string	&getName() const;
    const std::string	getWeaponName() const;
    int		  	getAP() const;
};

std::ostream		&operator<<(std::ostream &, const Character &c);

#endif     /* !__CHARACTER_HH__ */
