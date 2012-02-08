#ifndef SINGLETON_H_
# define SINGLETON_H_

# include <cstddef>

# include "Trace.h"

template<typename T> class Singleton
{
  static T* _instance;
  static bool _allocate;

  public:
    static T& getInstance()
    {
      PRINT_TRACE();
      if (Singleton<T>::_allocate == false)
      {
        Singleton<T>::_instance = new T;
        Singleton<T>::_allocate = true;
      }
      return (*(Singleton<T>::_instance));
    }

    virtual ~Singleton<T>()
    {
      PRINT_TRACE();
      Singleton<T>::_instance = NULL;
      Singleton<T>::_allocate = false;
    }
};
template<typename T> T* Singleton<T>::_instance = NULL;
template<typename T> bool Singleton<T>::_allocate = false;

#endif // !SINGLETON_H_
