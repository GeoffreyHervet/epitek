#ifndef ISAFEQUEUE_H_
# define ISAFEQUEUE_H_

/*!
 * \brief Interface for Thread Safe queue
 * \author Geoffrey HERVET
 * \version 0.1
 */
template <typename T>
class ISafeQueue<T>
{
  public:
    /*!
     * \brief Destrusctor
     */
    virtual ~ISafeQueue(void){};

    /*!
     * \brief push
     */
    virtual void push(T value) = 0;

    /*!
     * \brief try to pop, if success, return true and set value into pointer
     * \param value Pointer for setting value poped 
     */
    virtual bool tryPop(T* value) = 0;

    /*!
     * \brief isFinished
     */
    virtual bool isFinished(void) = 0;

    /*!
     * \brief setFinished
     * \param val new value of finished status
     */
    virtual void setFinished(bool val) = 0;
};

#endif /* ISAFEQUEUE_H_ */
