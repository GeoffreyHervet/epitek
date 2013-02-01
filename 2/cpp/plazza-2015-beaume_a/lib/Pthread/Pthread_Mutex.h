#ifndef PTHREAD_MUTEX_H_
# define PTHREAD_MUTEX_H_

# include		<typeinfo>
# include		<pthread.h>
# include       	<errno.h>

# include		"IMutex.h"

namespace		pthread
{
  /*!
  * \brief Thread class implementation in C++ using pthread
  * \author Geoffrey HERVET
  * \version 0.1
  */
  class			Mutex
    : public		IMutex
  {
    pthread_mutex_t	_mutex; /*!< pthread mutex */
    public:
      /*!
       * \class Error
       * \brief Exception class of Mutex
       */
      class Error : public std::exception
      {
        const char  *_what; /*!< Content of exception */
        public:
          /*!
           * \brief Constructor of Error
           * \param what Error message
           */
          Error(const char *what) throw() : _what(what){};
   
          /*!
           * \brief Getter of message error
           * \return Message error
           */
          const char *what() const throw() { return this->_what; };
      };

    public:
      /*!
       * \brief Mutex constructor
       */
      Mutex();

      /*!
       * \brief Mutex destructor
       */
      ~Mutex();

      /*!
       * \brief Mutex afectation
       */
      Mutex		&operator =(const Mutex &m);

      /*!
       * \brief Mutext copy constructor
       */
      Mutex(const Mutex &m);

      /*!
       * \brief Lock the mutex
       */
      void		lock();

      /*!
       * \brief Unlock the mutex
       */
      void		unlock();

      /*!
       * \brief try to lock the mutex
       * \return true if mutex was locked else it's false
       */
      bool		trylock();

      /*!
       * \brief getter
       * \return _mutex
       */
      pthread_mutex_t	getMutex()
      {
        return this->_mutex;
      };
        
  };
}

#endif /* PTHREAD_MUTEX_H_ */
