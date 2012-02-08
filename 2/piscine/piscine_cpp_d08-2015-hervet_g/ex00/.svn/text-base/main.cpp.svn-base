//
// header for norme in /
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.eu>
//
// Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
// Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
//

#include	"droid.hh"

int		main()
{
  Droid		d;
  Droid		d1("Avenger");
  size_t	Durasel = 200;

  std::cout << d  << std::endl;
  std::cout << d1 << std::endl;

  d = d1;

  d.setStatus(new std::string("Kill Kill Kill!"));
  d << Durasel;

  std::cout << d  << "--" << Durasel << std::endl;
  Droid d2 = d;
  d.setId("Rex");

  std::cout << (d2 != d) << std::endl;

  return 0;
}
