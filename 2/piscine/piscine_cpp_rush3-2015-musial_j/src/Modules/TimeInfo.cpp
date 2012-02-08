#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Trace.h"

#include "TimeInfo.h"

static int SecStringToSecInt(std::string const& s)
{
  PRINT_TRACE();
  std::istringstream iss(s);
  long long int ret;

  iss >> ret;
  return ((int)(ret));
}

Mod::TimeInfo::TimeInfo()
: _uptime(0)
{
  PRINT_TRACE();
  this->updateInfo();
}

Mod::TimeInfo::~TimeInfo()
{
  PRINT_TRACE();
#ifdef TRACE
  std::clog << "TIMEINFO: " << this->getHour() << "(hour) | " << this->getDate() << "(date) | " << this->getUptime() << "(uptime)" << std::endl;
#endif
}

void Mod::TimeInfo::updateInfo()
{
  PRINT_TRACE();
  this->setTime();
  this->setUptime();
}

std::string const& Mod::TimeInfo::getHour() const
{
  PRINT_TRACE();
  return (this->_hour);
}

std::string const& Mod::TimeInfo::getDate() const
{
  PRINT_TRACE();
  return (this->_date);
}

time_t Mod::TimeInfo::getUptime() const
{
  PRINT_TRACE();
  return (this->_uptime);
}

void Mod::TimeInfo::setTime()
{
  PRINT_TRACE();
  std::ifstream in("/proc/driver/rtc");
  std::string tmp;

  if (!in.good())
    return;

  in >> tmp;
  in >> tmp;
  in >> tmp;
  this->_hour = tmp;
  in >> tmp;
  in >> tmp;
  in >> tmp;
  this->_date = tmp;
}

void Mod::TimeInfo::setUptime()
{
  PRINT_TRACE();
  std::ifstream in("/proc/uptime");
  std::string tmp;

  if (!in.good())
    return;

  in >> tmp;
  this->_uptime = SecStringToSecInt(tmp);
}
