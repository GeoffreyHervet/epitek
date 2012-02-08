/*
** AWeapon.h for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Fri Jan 13 11:03:54 2012 geoffrey hervet
** Last update Fri Jan 13 11:03:54 2012 geoffrey hervet
*/

#include		<string>

#ifndef   __AWEAPON_H__
# define  __AWEAPON_H__

class			AWeapon
{
  std::string		_name;
  int			_apcost;
  int			_damage;

  public:
    AWeapon(std::string const &name, int apcost, int damage);
    virtual ~AWeapon();

    std::string const	&getName() const;
    int			getAPcost() const;
    int			getDamage() const;

    virtual void	attack() const = 0;
};

#endif     /* !__AWEAPON_H__ */
