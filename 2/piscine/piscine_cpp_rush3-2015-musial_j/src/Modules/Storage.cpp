#include <string>

#include "Trace.h"

#include "Storage.h"

Storage::Storage() : _used(0), _total(0)
{
  PRINT_TRACE();
}

Storage::~Storage()
{
  PRINT_TRACE();
}

unsigned int Storage::getUsed() const
{
  PRINT_TRACE();
  return this->_used;
}

unsigned int Storage::getTotal() const
{
  PRINT_TRACE();
  return this->_total;
}

unsigned int Storage::getPercent() const
{
  PRINT_TRACE();
  if (this->getTotal() == 0)
    return (0);
  return (((float)this->getUsed() / (float)this->getTotal()) * 100);
}

std::string const& Storage::getName() const
{
  PRINT_TRACE();
  return this->_name;
}

void Storage::setUsed(int use)
{
  this->_used = use;
}

void Storage::setTotal(int tot)
{
  this->_total = tot;
}

void Storage::setName(std::string const& name)
{
  this->_name = name;
}
