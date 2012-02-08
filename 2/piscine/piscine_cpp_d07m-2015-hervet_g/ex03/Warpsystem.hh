//
// Warpsystem.hh for ex00 in /home/hervet_g/piscine/piscine_cpp_d07m-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 11:21:44 2012 geoffrey hervet
// Last update Tue Jan 10 11:21:44 2012 geoffrey hervet
//

#ifndef   __WARPSYSTEM_HH__
# define  __WARPSYSTEM_HH__

#include	<string>

namespace	WarpSystem
{
  class		QuantumReactor
  {
    bool	_stability;

    public:
      QuantumReactor(bool = true);
      bool		isStable(void);
      void		setStability(bool);
  };

  class		Core
  {
    QuantumReactor *_coreReactor;
    public:
      Core(QuantumReactor *);
      QuantumReactor	*checkReactor(void);
  };
}

#endif     /* !__WARPSYSTEM_HH__ */
