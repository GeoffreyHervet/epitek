#ifndef SCOPELOCK_H_
# define SCOPELOCK_H_

# include		"IMutex.h"

/*!
 * \brief Thread class implementation in C++ using pthread
 * \author Geoffrey HERVET
 * \version 0.1
 */
class			ScopeLock
{
  IMutex		*_mutex; /*!< mutex to lock */
  public:

    /*!
     * \brief ScopeLock Constructor
     * \param m Pointer to the  mutex to lock
     */
    ScopeLock(IMutex *m);

    /*!
     * \brief ScopeLock destructor
     */
    ~ScopeLock();

    /*!
     * \brief Copy constructor
     */
    ScopeLock(const ScopeLock &);

    /*!
     * \brief Assignation constructor
     */
    ScopeLock		&operator =(const ScopeLock &s);
};

#endif /* SCOPELOCK_H_ */
