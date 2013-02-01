#ifndef PTHREAD_CONDVAR_H_
# define PTHREAD_CONDVAR_H_

# include		<pthread.h>
# include		"Pthread_Mutex.h"

namespace		pthread
{
  /*!
  * \brief Thread class implementation in C++ using pthread
  * \author Geoffrey HERVET
  * \version 0.1
  */
  class			CondVar
  {
    pthread_cond_t	_cond; /*!< pthread conditionnal var */
    Mutex		_m; /*!< Mutex of condvar */

    public:
      /*!
       * \class Error
       * \brief Exception class of CondVar
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

      /*!
       * \brief Constructor
       */
      CondVar();

      /*!
       * \brief Destructor
       */
      ~CondVar();

      /*!
       * \brief Copy constructor
       */
      CondVar(const CondVar &);

      /*!
       * \brief Affectation constructor
       */
      CondVar		&operator =(const CondVar &);

      /*!
       * \brief Unblock all thread waiting for this condition variable
       */
      void		brodcast(void);


      /*!
       * \brief Unblock a thread waiting for a condition variable
       */
      void		signal(void);

      /*!
       * \brief wait on a condition variable for a specific amount of time
       * \param sec Number of sec
       * \param nsec Number of nanosec
       * \return true if success
       */
      bool		wait(int sec, int nsec = 0);

      /*!
       * \brief wait on a condition variable for a specific amount of time
       * \return true if success
       */
      bool		wait();
  };
}

#endif /* PTHREAD_CONDVAR_H_ */
