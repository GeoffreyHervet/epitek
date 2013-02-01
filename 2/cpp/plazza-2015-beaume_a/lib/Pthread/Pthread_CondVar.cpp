#include		<sys/time.h>
#include		"Pthread_CondVar.h"

namespace		pthread
{
  CondVar::CondVar()
  {
    pthread_cond_init(&this->_cond, NULL);
  }

  CondVar::~CondVar()
  {
    pthread_cond_destroy(&this->_cond);
  }

  void			CondVar::brodcast(void)
  {
    pthread_cond_broadcast(&this->_cond);
  }

  void			CondVar::signal(void)
  {
    pthread_cond_signal(&this->_cond);
  }

  bool			CondVar::wait(int sec, int nsec)
  {
    struct timeval	tv;
    struct timespec	ts;
    pthread_mutex_t	mu = this->_m.getMutex();

    gettimeofday(&tv, NULL);
    ts.tv_sec = tv.tv_sec + sec;
    ts.tv_nsec = nsec;
    return !pthread_cond_timedwait(&this->_cond, &mu, &ts);
  }

  bool			CondVar::wait(void)
  {
    pthread_mutex_t	mu = this->_m.getMutex();

    return !pthread_cond_wait(&this->_cond, &mu);
  }

}
