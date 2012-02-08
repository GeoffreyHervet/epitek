#include <fstream>
#include <string>
#include <sstream>

#include "Trace.h"

#include "Swap.h"

static int BytsInStringToInt(std::string const& s)
{
  PRINT_TRACE();
  std::istringstream iss(s);
  long long int ret;

  iss >> ret;
  return ((int)(ret / 1024));
}

Mod::Swap::Swap()
{
  PRINT_TRACE();
  this->_enable = false;
  this->updateInfo();
}

Mod::Swap::~Swap()
{
  PRINT_TRACE()
#ifdef TRACE
    std::clog << "Swap: " << this->_swap.getName() << " Total : " << this->_swap.getTotal() << "Mo, Used : " << this->_swap.getUsed() << "Mo" << std::endl;
#endif
}
#include <iostream>

void Mod::Swap::updateInfo()
{
  PRINT_TRACE();
  std::ifstream in("/proc/swaps");
  std::string tmp;

  if (!in.good())
    return;

  for (int i = 0; i < 6; i++)
    in >> tmp;

  this->_swap.setName(tmp);
  in >> tmp; in >> tmp;
  this->_swap.setTotal(BytsInStringToInt(tmp));
  in >> tmp;
  this->_swap.setUsed(BytsInStringToInt(tmp));
  this->_enable = true;
}

bool Mod::Swap::isEnable() const
{
  PRINT_TRACE();
  return this->_enable;
}

Storage const & Mod::Swap::getData() const
{
  PRINT_TRACE();
  return this->_swap;
}
