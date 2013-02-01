#include <iostream>

#include "Core.hpp"

Core::Core()
{
}

Core::~Core()
{
}

void		Core::run(void)
{
  try
  {
  this->_game.run();
  }
  catch (...)
  {
    std::cerr << "Une erreur est survenue ..." << std::endl;
  }
}
