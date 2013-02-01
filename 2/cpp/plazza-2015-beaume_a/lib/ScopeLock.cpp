#include		"ScopeLock.h"

ScopeLock::ScopeLock(IMutex *m)
  : _mutex(m)
{
  this->_mutex->lock();
}

ScopeLock::~ScopeLock()
{
  this->_mutex->unlock();
}
