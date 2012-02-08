//
// header for norme in /
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.eu>
//
// Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
// Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
//

#include	<string>
#include	<iostream>

#ifndef __DROID_HH_
# define __DROID_HH_

class		Droid
{
  std::string	_id;
  std::string	*_status;
  size_t const	_attack;
  size_t const	_toughness;
  size_t	_energy;

  public:
    Droid(const std::string & = "");
    Droid(const Droid &);
    ~Droid();

    Droid &	operator=(const Droid &);
    bool	operator==(const Droid &) const;
    bool	operator!=(const Droid &) const;
    Droid &	operator<<(size_t &);

    std::string	getId(void) const;
    std::string	*getStatus() const;
    size_t	getEnergy(void) const;
    size_t	getAttack(void) const;
    size_t	getToughness(void) const;

    void	setStatus(const std::string *);
    void	setId(const std::string &);
    void	setEnergy(const size_t);
};

std::ostream&	operator<<(std::ostream &, const Droid &); //, const Droid &);

#endif /* !__DROID_HH_ */
