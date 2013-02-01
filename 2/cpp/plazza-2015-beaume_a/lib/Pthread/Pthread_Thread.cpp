#include		<pthread.h>
#include		<signal.h>
#include		<errno.h>
#include		<iostream>

#include		"Pthread_Thread.h"

namespace		pthread
{
  static void*	prepare_work(void*p)
  {
    Thread	*t = static_cast<Thread*>(p);
    t->_thread_launch();
    return t->getReturn();
  }

  Thread::Thread()
    : _work(true)
  {
    pthread_create(&this->_thread,
        NULL,
        prepare_work,
        this);
  }

  Thread::~Thread()
  {
    if (this->_work)
      this->join();
  }

  void	        	Thread::_thread_launch()
  {
    while (_work)
    {
      this->_status = WAITING;
      this->_cond.wait();
      this->_status = WORKING;
      this->_ret = this->_func(this->_param);
    }
    this->_status = DEAD;
  }

  bool			Thread::work(void *(*func)(void *), void *param)
  {
    if (this->_status != WAITING)
      return (false);
    this->_func = func;
    this->_param = param;
    this->_cond.signal();
    return (true);
  }

  void			Thread::join(void)
  {
    this->_work = false;
    this->_cond.signal();
    pthread_join(this->_thread, NULL);
  }
}
