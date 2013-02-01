#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <iostream>
# include <typeinfo>

class			Error
  : public		  std::exception
{
  public:
    enum		eLevel
    {
      NOTICE,
      WARN,
      CRITICAL
    };

    /*!
     * Ctor
     * \param what Expliciti error msg
     * \param lvl Level error
     */
    Error(const char *what, eLevel lvl) throw() : _what(what), _lvl(lvl) {};
    
    ~Error() throw() {};

    Error(const Error &e) throw();
    Error &operator=(const Error &e) throw();

    const char		*what(void) const throw()
    {
      return this->_what;
    };
    
    eLevel		level(void) const throw()
    {
      return this->_lvl;
    };

  private:
    const char *	_what;
    eLevel		_lvl;
};

std::ostream		&operator <<(std::ostream &, Error::eLevel);

#endif /* ERROR_HPP_ */
