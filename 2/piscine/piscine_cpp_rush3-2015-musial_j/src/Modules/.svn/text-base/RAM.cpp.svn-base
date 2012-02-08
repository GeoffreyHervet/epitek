#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Trace.h"

#include "RAM.h"

static int byteStringToSecInt(std::string const& s)
{
  PRINT_TRACE();
  std::istringstream iss(s);
  long long int ret;

  iss >> ret;
  return ((int)(ret / 1024));
}

Mod::RAM::RAM()
: _totalRam(0), _freeRam(0)
{
  PRINT_TRACE();
  this->updateInfo();
}

Mod::RAM::~RAM()
{
  PRINT_TRACE();
#ifdef TRACE
  std::clog << "RAM: " << this->getUsedRam() << "/" << this->getTotalRam() << "MB (" << this->getPercentRam() << "%)" << std::endl;
#endif
}

void Mod::RAM::updateInfo()
{
  PRINT_TRACE();
  const std::string searchWords[] =
  {
    "MemTotal:",
    "MemFree:"
  };
  std::ifstream in("/proc/meminfo");
  std::string tmp;

  if (!in.good())
    return;

  while (!in.eof())
  {
    in >> tmp;
    if (tmp == searchWords[0])
    {
      in >> tmp;
      this->_totalRam = byteStringToSecInt(tmp);
    }
    else if (tmp == searchWords[1])
    {
      in >> tmp;
      this->_freeRam = byteStringToSecInt(tmp);
    }
  }
}

unsigned int Mod::RAM::getUsedRam() const
{
  PRINT_TRACE();
  if (this->_totalRam <= this->_freeRam)
    return (0);
  return (this->_totalRam - this->_freeRam);
}

unsigned int Mod::RAM::getFreeRam() const
{
  PRINT_TRACE();
  return (this->_freeRam);
}

unsigned int Mod::RAM::getTotalRam() const
{
  PRINT_TRACE();
  return (this->_totalRam);
}

unsigned int Mod::RAM::getPercentRam() const
{
  PRINT_TRACE();
  if (this->getTotalRam() == 0)
    return (0);
  return (((float)this->getUsedRam() / (float)this->getTotalRam()) * 100);
}
