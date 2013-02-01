#ifndef SAFEQUEUE_H_
# define SAFEQUEUE_H_

# include		<queue>

# include		"ISafeQueue.h"
# include		"Pthread_Thread.h"
# include		"Pthread_Mutex.h"
# include		"Pthread_Scopelock.h"

/*!
 * \brief Thread Safe queue
 * \author Geoffrey HERVET
 * \version 0.1
 */
template <typename T>
class			SafeQueue<T>
: public		ISafeQueue<T>
{
  public:

    /*!
     * \brief Constructeur
     */
    SafeQueue();

    /*!
     * \brief Destrusctor
     */

    ~SafeQueue();
    /*!
     * \brief Copy constructor
     */
    SafeQueue(const SafeQueue &);

    /*!
     * \brief Affectation constructeur
     */
    SafeQueue		&operator =(const SafeQueue &);

    /*!
     * \brief Push a value in queue
     * \param val value's reference to push
     */
    void		push(const T& val);

    /*!
     * \brief try to pop, if success, return true and set value into pointer
     * \param val Pointer for setting value poped 
     */
    void		tryPop(T *val);

    /*!
     * \brief isFinished
     */
    bool		isFinished(void);

    /*!
     * \brief setFinished
     * \param val new value of finished status
     */
    void		setFinished(bool val);

  protected:
    bool		_finished; /*!< Finished status */
    std::queue<T>	_queue; /*!< Queue */
    Mutex		_mutex; /*!< Mutex for thread safe */
};

# include		"SafeQueue.ipp"

#endif /* SAFEQUEUE_H_ */
