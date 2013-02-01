#include <stdlib.h>

#include "Zlock.hpp"


namespace		Menu
{
  Zlock::Zlock(const std::string &s)
    : AMenuObject(s)
  {
  }

  Zlock::~Zlock()
  {
  }

  bool      	Zlock::selected(IMenu &, MyGame &, gdl::Input &)
  {
    system("zlock -immed &");
    return true;
  }
};
