#ifndef IMUTEX_H_
# define IMUTEX_H_

/*!
 * \brief Thread Safe queue
 * \author Geoffrey HERVET
 * \version 0.1
 */

class	IMutex
{
  public:
    /*!
     * \brief Destructor
     */

    virtual ~IMutex(void){};

    /*!
     * \brief Lock the mutex
     */
    virtual void lock(void) = 0;

    /*!
     * \brief Unlock the mutex
     */

    /*!
     * \brief try to lock the mutex
     * \return true if mutex was locked else it's false
     */
    virtual void unlock(void) = 0;

    /*!
     * \brief try to lock the mutex
     * \return true if mutex was locked else it's false
     */
    virtual bool trylock(void) = 0;
};

#endif /* IMUTEX_H_ */
