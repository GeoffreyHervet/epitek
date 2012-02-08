#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Trace.h"

#include "LoadAvg.h"

Mod::LoadAvg::LoadAvg()
: _loadAvg("")
{
  PRINT_TRACE();
  this->updateInfo();
}

Mod::LoadAvg::~LoadAvg()
{
  PRINT_TRACE();
#ifdef TRACE
  std::clog << "LoadAvg: " << this->_loadAvg << std::endl;
#endif
}

void Mod::LoadAvg::updateInfo()
{
  PRINT_TRACE();
  std::ifstream in("/proc/loadavg");
  std::string tmp;

  if (!in.good())
    return;

  in >> tmp;
  this->_loadAvg = (tmp += " ");
  in >> tmp;
  this->_loadAvg += (tmp += " ");
  in >> tmp;
  this->_loadAvg += tmp;
}

std::string Mod::LoadAvg::getLoadAvg() const
{
  PRINT_TRACE();
  return this->_loadAvg;
}
