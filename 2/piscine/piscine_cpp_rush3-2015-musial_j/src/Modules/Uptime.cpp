#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Trace.h"

#include "Uptime.h"

Mod::Uptime::Uptime()
: _uptime("")
{
  PRINT_TRACE();
  this->updateInfo();
}

Mod::Uptime::~Uptime()
{
  PRINT_TRACE();
#ifdef TRACE
  std::clog << "Uptime: " << this->_uptime << std::endl;
#endif
}

void Mod::Uptime::updateInfo()
{
  PRINT_TRACE();
  std::ifstream in("/proc/uptime");
  std::string tmp;
  std::stringstream out;
  int sec = 0;
  int min = 0;
  int h = 0;

  if (!in.good())
    return;

  in >> tmp;
  sec = atoi(tmp.c_str());

  h = sec / 60 / 60;
  sec -= h * 60 * 60;
  min = sec / 60;
  sec -= min * 60;

  out << h << ":" << min << ":" << sec;
  this->_uptime = out.str();
}

std::string Mod::Uptime::getUptime() const
{
  PRINT_TRACE();
  return this->_uptime;
}
