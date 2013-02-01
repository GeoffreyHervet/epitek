#ifndef NUMBER_HPP_
# define NUMBER_HPP_

# include		"AMenuObjectEditable.hpp"

namespace		Menu
{
  class			Number : public AMenuObjectEditable
  { 
    public:
      Number(const std::string &name, int max, int min);
      ~Number();

      const std::string & next();
      const std::string & prev();

      const std::string & value() const { return this->_sVal; };

    private:
      const std::string & setSval(void);

    private:
      int		_max;
      int		_min;
      int		_value;
      std::string	_sVal;
  };
}

#endif /* NUMBER_HPP_ */
