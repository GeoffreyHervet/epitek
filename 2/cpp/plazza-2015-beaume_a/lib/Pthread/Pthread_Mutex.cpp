#include	<pthread.h>
#include	<iostream>

#include	"Pthread_Mutex.h"

namespace	pthread
{
  Mutex::Mutex()
  {
    pthread_mutex_init(&this->_mutex, NULL);
  }

  pthread::Mutex::~Mutex()
  {
    pthread_mutex_destroy(&this->_mutex);
  }

  void				Mutex::lock()
  {
    pthread_mutex_lock(&this->_mutex);
  }

  void				Mutex::unlock()
  {
    if (EDEADLK == pthread_mutex_unlock(&this->_mutex))
      throw Error("Deadlock detected");
  }

  bool				Mutex::trylock()
  {
    return !pthread_mutex_trylock(&this->_mutex);
  }
}
