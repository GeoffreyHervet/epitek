#include	<iostream>
#include	<sstream>
#include	"Number.hpp"

namespace	Menu
{
  Number::Number(const std::string &name, int min, int max) :
    AMenuObjectEditable(name),
    _max(max),
    _min(min),
    _value(min)
  {
    this->setSval();
  }

  Number::~Number()
  {
  }

  const std::string	&Number::next()
  {
    if (this->_min != this->_max)
    {
      if (this->_value == this->_max)
        this->_value = this->_min;
      else
        this->_value++;
    }
    return this->setSval();
  }

  const std::string	&Number::prev()
  {
    if (this->_min != this->_max)
    {
      if (this->_value == this->_min)
        this->_value = this->_max;
      else
        this->_value--;
    }
    return this->setSval();
  }

  const std::string	&Number::setSval(void)
  {
    std::stringstream	ss;

    ss << this->_value;
    this->_sVal = ss.str();

    return this->_sVal;
  }
}
