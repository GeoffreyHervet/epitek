//
// droidmemory.hh for ex01 in /home/hervet_g/piscine/piscine_cpp_d08-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Wed Jan 11 15:42:16 2012 geoffrey hervet
// Last update Wed Jan 11 15:42:16 2012 geoffrey hervet
//

#include	<string>

#ifndef   __DROIDMEMORY_HH__
# define  __DROIDMEMORY_HH__

class		DroidMemory;

#include	"droid.hh"

class		DroidMemory
{
  size_t		_fingerPrint;
  size_t		_exp;

  public:
    DroidMemory();

    size_t		getExp(void) const;
    size_t		getFingerPrint(void) const;

    void		setExp(const size_t &);
    void		setFingerPrint(const size_t &);

    DroidMemory &	operator<<(DroidMemory &);
    DroidMemory &	operator>>(DroidMemory &);
    DroidMemory &	operator+=(DroidMemory &);
    DroidMemory &	operator+=(size_t exp);
};

std::ostream&		operator<<(std::ostream &, const DroidMemory &);
DroidMemory 		operator+(const DroidMemory &, const DroidMemory &);
DroidMemory	 	operator+(const size_t &exp, const DroidMemory &);
DroidMemory 		operator+(const DroidMemory &, const size_t &exp);

#endif     /* !__DROIDMEMORY_HH__ */
