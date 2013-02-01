#include <stdlib.h>

#include "Restart.hpp"


namespace		Menu
{
  Restart::Restart(const std::string &s)
    : AMenuObject(s)
  {
  }

  Restart::~Restart()
  {
  }

  bool      	Restart::selected(IMenu &, MyGame &g, gdl::Input &)
  {
    g.restart();
    return true;
  }
};
