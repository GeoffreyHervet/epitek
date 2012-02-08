#ifndef		_OPERANDS_HH_
#define		_OPERANDS_HH_

#include	<string>
#include	<iostream>
#include	<sstream>

#include	"IOperand.hh"
#include	"Stack.hh"

namespace	avm
{

  template <typename T>
  class Operand : public IOperand
  {
  public:
    Operand(std::string val, eOperandType type)
    : type(type), str(val)
    {
      std::stringstream     a;

      a.str(val);
      a >> this->value;
    };

    ~Operand(){};

    Operand		*clone() const { return (new Operand<T>(this->toString(), this->type)); };
    std::string const&	toString() const {   return (this->str); };
    int			getPrecision() const {    return (static_cast<int>(this->type));};
    eOperandType	getType() const {    return (this->type); };
    T			getValue() const { return (this->value);};

    IOperand *operator+(const IOperand &rhs) const
    {
      Operand       *result;
      double        tmp;
      std::stringstream     s;

      s.str(rhs.toString());
      s >> tmp;
      result = (rhs.getPrecision() > this->getPrecision() ?
          static_cast<const Operand & > (rhs).clone() : this->clone());
      result->value = this->value + tmp;
      s.clear();
      s << result->value;
      result->str = s.str();
      return (result);
    };

    IOperand *operator-(const IOperand &rhs) const
    {
      Operand		*result;
      double		tmp;
      std::stringstream	s;

      s.str(rhs.toString());
      s >> tmp;
      result = (rhs.getPrecision() > this->getPrecision() ?
          static_cast<const Operand & > (rhs).clone() : this->clone());
      result->value = this->value - tmp;
      s.clear();
      s << result->value;
      result->str = s.str();
      return (result);
    };

    IOperand *operator*(const IOperand &rhs) const
    {
      Operand               *result;
      double                tmp;
      std::stringstream     s;

      s.str(rhs.toString());
      s >> tmp;
      result = (rhs.getPrecision() > this->getPrecision() ?
          static_cast<const Operand & > (rhs).clone() : this->clone());
      result->value = this->value * tmp;
      s.clear();
      s << result->value;
      result->str = s.str();
      return (result);
    };

    IOperand *operator/(const IOperand &rhs) const
    {
      Operand               *result;
      double                tmp;
      std::stringstream     s;

      s.str(rhs.toString());
      s >> tmp;
      if (tmp == 0.0)
	throw Stack::Error("Div by 0");
      result = (rhs.getPrecision() > this->getPrecision() ?
          static_cast<const Operand & > (rhs).clone() : this->clone());
      result->value = this->value / tmp;
      s.clear();
      s << result->value;
      result->str = s.str();
      return (result);
    };

    IOperand *operator%(const IOperand &rhs) const
    {
    Operand       *result;
    int           tmp;
    std::stringstream     s;

    s.str(rhs.toString());
    s >> tmp;
    if (tmp == 0)
      throw Stack::Error("Error: Modulo by 0");
    if (rhs.getType() == FLOAT || rhs.getType() == DOUBLE)
      throw Stack::Error("Modulo by decimal");
    result = (rhs.getPrecision() > this->getPrecision() ?
	   static_cast<const Operand &>(rhs).clone() : this->clone());
    result->value = this->value - (this->value / tmp) * tmp;
    s.clear();
    s << result->value;
    result->str = s.str();
    return (result);
    };

  private:
    eOperandType          type;
    std::string           str;
    T                     value;
  };

};

#endif		/* _OPERANDS_HH_ */