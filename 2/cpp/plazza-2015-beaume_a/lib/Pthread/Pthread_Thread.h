#ifndef PTHREAD_TREAD_H_
# define PTHREAD_TREAD_H_

# include		<typeinfo>
# include		<pthread.h>

# include		"Pthread_CondVar.h"

namespace		pthread
{
  /*!
  * \brief Thread class implementation in C++ using pthread
  * \author Geoffrey HERVET
  * \version 0.1
  * pthread_once not implemented
  * pthread_self not implemented
  * pthread_once not implemented
  */
  class			Thread
  {
    public:
      /*!
       * \brief  used to know thred status
       */
      enum		eStatus
      {
        DEAD,
        WORKING,
        WAITING
      };

      /*!
       * \class Error
       * \brief Exception class of Thread
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
       * \brief Constructor of thread
       */
      Thread();

      /*!
       * \brief Copy Constructor
       */
      Thread(const Thread &t);

      /*!
       * \brief Copy operator
       */
      Thread		&operator=(const Thread &);

      /*!
       * \brief Destructor
       */
      ~Thread();

      /*!
       * \brief exec a function in the tread
       * \param fun function to exec
       * \param param Parameter to fun
       * \return true if can execute the func
       */
      bool      	work(void *(*fun)(void *), void *param);

      /*!
       * \brief alias on Thread::work()
       * \param fun function to exec
       * \param param Parameter to fun
       * \return true if can execute the func
       */
      bool		operator ()(void *(*fun)(void *), void *param)
      {
        return this->work(fun, param);
      };

      /*!
       * \brief wait thread ending work
       */
      void		join(void);

      /*!
       * \brief launch thread
       */
      void	        _thread_launch();

      /*!
       * \brief get returned val of thread
       */
      void*		getReturn(void) const
      {
        return this->_ret;
      }

    protected:
      bool		_work; /*!< is working (executing functions) */
      pthread_t		_thread; /*!< phtread struct */
      eStatus		_status; /*!< phtread status */
      CondVar		_cond; /*!< conditionall variable for sync */
      void		*(*_func)(void*); /*!< func to call */
      void		*_param; /*!< param of _func */
      void		*_ret; /*!< Return of work function */


  };
}

#endif /* PTHREAD_TREAD_H_ */
