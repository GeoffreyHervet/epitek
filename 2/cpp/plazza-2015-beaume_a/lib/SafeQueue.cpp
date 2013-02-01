#ifdef SAFEQUEUE_H_
# ifndef SAFEQUEUE_IPP_
#  define SAFEQUEUE_IPP_

template <typename T>
SafeQueue<T>::SafeQueue()
  : _finished(false)
{
}

template <typename T>
SafeQueue<T>::~SafeQueue()
{
}

template <typename T>
void			SafeQueue<T>::push(const int &val)
{
  ScopeLock		s(&this->_m);

  this->_queue.push(val);
}

template <typename T>
void			SafeQueue<T>::tryPop(int *ptr)
{
  if (this->_mutex.trylock())
  {
    *ptr = this->_queue.front();
    this->_queue.pop();
  }
  this->_mutex.unlock();
}

template <typename T>
bool		        SafeQueue<T>::isFinished(void)
{
  ScopeLock		s(&this->_m);

  return this->_finished;
}

template <typename T>
void		        SafeQueue<T>::setFinished(bool val)
{
  ScopeLock		s(&this->_m);

  this->_finished = val;
}

# endif /* SAFEQUEUE_IPP_ */
#endif /* SAFEQUEUE_H_ */
