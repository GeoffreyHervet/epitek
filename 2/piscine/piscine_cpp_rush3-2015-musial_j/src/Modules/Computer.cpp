#include <string>
#include <cstring>
#include <sys/types.h>
#include <pwd.h>
#include <fstream>

#include "Trace.h"

#include "Computer.h"

Mod::Computer::Computer()
  : _computerName(""), _userName("")
{
  PRINT_TRACE();
  this->updateInfo();
}

Mod::Computer::~Computer()
{
  PRINT_TRACE();
#ifdef TRACE
  std::clog << "ComputerName: " << this->getComputerName() << std::endl
	    << "UserName: " << this->getUserName() << std::endl;
#endif
}

void Mod::Computer::updateInfo()
{
  PRINT_TRACE();

  this->setComputerName();
  this->setUserName();
}

void Mod::Computer::setComputerName()
{
  PRINT_TRACE();

  std::ifstream in("/proc/sys/kernel/hostname");
  std::string tmp;

  if (!in.good())
    return;

  in >> tmp;
  this->_computerName = tmp;
}

void Mod::Computer::setUserName()
{
  PRINT_TRACE();
  struct passwd *passwd;
  passwd = getpwuid(getuid());

  this->_userName = passwd->pw_name;
}

std::string const& Mod::Computer::getComputerName() const
{
  PRINT_TRACE();

  return this->_computerName;
}

std::string const& Mod::Computer::getUserName() const
{
  PRINT_TRACE();

  return this->_userName;
}
