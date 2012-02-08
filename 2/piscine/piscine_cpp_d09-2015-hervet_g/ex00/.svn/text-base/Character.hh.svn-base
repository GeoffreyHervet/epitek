//
// Character.hh for ok in /home/hervet_g/piscine/ok
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 12 11:33:30 2012 geoffrey hervet
// Last update Thu Jan 12 11:33:30 2012 geoffrey hervet
//

#include		<string>

#ifndef   __CHARACTER_HH__
# define  __CHARACTER_HH__

class			Character
{
  public:
    enum		AttackRange
    {
      CLOSE,
      RANGE
    };
    AttackRange		Range;

  protected:
    std::string		_name;
    int			_lvl;
    int			_pv;
    int			_power;

    int			_force;
    int			_endur;
    int			_intel;
    int			_espr;
    int			_agil;

    void		addPv(const int);
    void		addPower(const int);

  public:
    Character(const std::string &, int lvl);

    const std::string &	getName() const;
    int			getLvl() const;
    int			getPv() const;
    int			getPower() const;

    int			RangeAttack();
    int			CloseAttack();
    void		Heal();
    void		RestorePower();

    void		TakeDamage(int _damage);
};

#endif     /* !__CHARACTER_HH__ */
