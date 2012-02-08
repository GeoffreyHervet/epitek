/*
** ex05.h for ex05 in /home/hervet_g/piscine/piscine_cpp_d15-2015-hervet_g/ex05
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Wed Jan 18 12:27:57 2012 geoffrey hervet
** Last update Wed Jan 18 12:27:57 2012 geoffrey hervet
*/

#include	<iostream>
#include	<iomanip>

#ifndef   __EX05_H__
# define  __EX05_H__

template <typename T>
class		array
{
  size_t	_size;
  T*		_content;

  public:
    ~array(){ if (this->_content != NULL) delete[] this->_content; };
    array(): _size(0), _content(NULL){};
    array(unsigned int size): _size(size), _content(new T [size - 1]) { if (this->_content == NULL) throw std::exception(); };
    array(const array &a){
      if (this != &a)
      {
        this->_size = a.size();
        T*	cont = a.getContent();
        size_t	idx = -1;
        this->_content = new T [this->_size];
        if (this->_content == NULL)
          throw std::exception();
        while (++idx < this->_size)
          this->_content[idx] = cont[idx];
      }
    };

    array	&operator=(const array &a)
    {
      if (this != &a)
      {
        this->_size = a.size();
        T*	cont = a.getContent();
        size_t	idx = -1;
        this->_content = new T [this->_size];
        if (this->_content == NULL)
          throw std::exception();
        while (++idx < this->_size)
          this->_content[idx] = cont[idx];
      }
      return *this;
    }

    T			&operator[](const size_t idx)
    {
      if (idx >= this->_size)
      {
        T*		tmp = new T [idx + 1];
        size_t		i = 0;

        if (tmp == NULL)
          throw std::exception();
        for (i = 0; i < this->_size; i++)
          tmp[i] = this->_content[i];
        delete[] this->_content;
        this->_content = tmp;
        this->_size = idx + 1;
      }
      return this->_content[idx];
    };

    const T		&operator[](const size_t idx) const
    {
      if (idx >= this->_size)
        throw  std::exception();
      return this->_content[idx];
    }

    void		dump() const {
      size_t		idx = 0;

      std::cout << "[";
      while (idx < this->_size)
      {
        if (idx != 0)
          std::cout << ", " ;
        std::cout << this->_content[idx++];
      }
      std::cout << "]" << std::endl;
    };

    size_t		size() const { return this->_size; };
    T*			getContent() const { return this->_content; };

    void		setContent(T *tab){
      if (this->_content != NULL)
        delete[] this->_content;
      this->_content = tab;
    };

    template <typename U>
    array <U>		convertTo(U (*f)(T const &))
    {
      array<U>		ret(this->_size);
      U			*tab = ret.getContent();
      size_t		idx = this->_size;
      while (idx--)
        tab[idx] = f(this->_content[idx]);
      ret.setContent(tab);
      return ret;
    };
};

template <>
void		array<bool>::dump() const
{
  size_t		idx = 0;

  std::cout << "[" << std::boolalpha;
  while (idx < this->_size)
  {
    if (idx != 0)
      std::cout << ", " ;
    std::cout << this->_content[idx++];
  }
  std::cout << "]" << std::endl;
}


#endif     /* !__EX05_H__ */
