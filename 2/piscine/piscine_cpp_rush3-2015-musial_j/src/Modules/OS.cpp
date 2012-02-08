#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Trace.h"

#include "OS.h"

Mod::OS::OS()
  : _bits(0)
{
  PRINT_TRACE();
  this->updateInfo();
}

Mod::OS::~OS()
{
  PRINT_TRACE();
#ifdef TRACE
  std::clog << "OS: " << this->getOSType() << "(osType) | " << this->getOSRelease() << "(osRelease) | " << this->getKernelVersion() << "(kernel) | " << this->is32b() << "(32b) | " << this->is64b() << "(64b)" << std::endl;
#endif
}

void Mod::OS::setBits()
{
  PRINT_TRACE();
  std::ifstream in("/proc/cpuinfo");
  std::string tmp;

  if (!in.good())
    return;

  this->_bits = 32;
  while (!in.eof())
  {
    in >> tmp;
    if (tmp == "lm")
    {
      this->_bits = 64;
      return;
    }
  }
}

void Mod::OS::setOSType()
{
  PRINT_TRACE();
  std::ifstream in("/proc/sys/kernel/ostype");
  std::string tmp;

  if (!in.good())
    return;

  in >> tmp;
  this->_osType = tmp;
}

void Mod::OS::setOSRelease()
{
  PRINT_TRACE();
  std::ifstream in("/proc/sys/kernel/osrelease");
  std::string tmp;

  if (!in.good())
    return;

  in >> tmp;
  this->_osRelease = tmp;
}

void Mod::OS::setKernelVersion()
{
  PRINT_TRACE();
  std::ifstream in("/proc/sys/kernel/version");

  if (!in.good())
    return;

  std::getline(in, this->_kernelVersion);
}

void Mod::OS::updateInfo()
{
  PRINT_TRACE();
  this->setBits();
  this->setOSType();
  this->setOSRelease();
  this->setKernelVersion();
}

std::string const& Mod::OS::getOSType() const
{
  PRINT_TRACE();
  return (this->_osType);
}

std::string const& Mod::OS::getOSRelease() const
{
  PRINT_TRACE();
  return (this->_osRelease);
}

std::string const& Mod::OS::getKernelVersion() const
{
  PRINT_TRACE();
  return (this->_kernelVersion);
}

bool Mod::OS::is32b() const
{
  PRINT_TRACE();
  return (this->_bits == 32);
}

bool Mod::OS::is64b() const
{
  PRINT_TRACE();
  return (this->_bits == 64);
}
