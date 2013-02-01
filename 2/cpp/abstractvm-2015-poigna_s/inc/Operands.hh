#ifndef		_OPERANDS_HH_
# define	_OPERANDS_HH_

# include	<string>
# include	<iostream>
# include	<sstream>
# include	<typeinfo>
# include	<stdexcept>
# include	<bitset>
# include	<iomanip>
# include	<cmath>
# include	<limits>

# include	"IOperand.hh"
# include	"Stack.hh"
# include	"utils.h"
# include	"tuple.hh"

# define	MOD(x, y) ((x) - (y) * int((x) / (y)))

namespace	avm
{
  template <typename T>
  class Operand : public IOperand
  {
    private:
      eOperandType	type;
      std::string	str;
      T			value;

    public:
      Operand(std::string val, eOperandType type);
      Operand(long double val, eOperandType type);
      ~Operand(){};
      Operand(const Operand<T> &);
      Operand<T>		operator=(const Operand<T> &);

      T				getValue() const {
        return (this->value);};

      std::string const&	toString() const { return (this->str); };
      int			getPrecision() const {    return (static_cast<int>(this->type));};
      eOperandType		getType() const {    return (this->type); };

      IOperand *operator+(const IOperand &rhs) const;
      IOperand *operator-(const IOperand &rhs) const;
      IOperand *operator*(const IOperand &rhs) const;
      IOperand *operator/(const IOperand &rhs) const;
      IOperand *operator%(const IOperand &rhs) const;

    protected:
      Tuple<long double,eOperandType> doCalcul(const IOperand &rhs, const eOperationType op) const;
  };

  /*
   * Template class's methods
   */
  template <typename T>
  Operand<T>::Operand(std::string val, eOperandType type) : type(type), str(val)
  {
    std::stringstream     a(val);
    int		          tmp;

    if (sizeof(T) <= sizeof(char))
    {
      a >> tmp;
      this->value = tmp;
    }
    else
      a >> this->value;

    if (a.fail() || (sizeof(T) == sizeof(char) && tmp != this->value))
      throw std::overflow_error("Overflow on assignement !");
  };

  template <typename T>
  Operand<T>::Operand(long double val, eOperandType type) : type(type)
  {
    this->value = static_cast<T>(val);

    std::stringstream     a;
    if (sizeof(T) <= sizeof(char))
      a << int(this->value);
    else
      a << this->value;

    if ((sizeof(T) > sizeof(char)) && (this->value != 0) &&
        (this->value == std::numeric_limits<T>::infinity() ||
         this->value == -std::numeric_limits<T>::infinity()
        ))
    {
      throw std::overflow_error("Overflow on operation !");
    }
    this->str = a.str();
  };

  template <typename T>
    IOperand *Operand<T>::operator+(const IOperand &rhs) const
    {
      Tuple<long double, eOperandType> tup = this->doCalcul(rhs, ADD);
      IOperand		*ret = utils::InstIOpByType(tup.getRight(), tup.getLeft());

      /* Check overflow */
      std::stringstream		ss;
      ss << rhs.toString() << " " << ret->toString();
      double r_val, ret_val;
      ss >> r_val >> ret_val;
      if ((this->getValue() > 0 && (ret_val < r_val)) ||
          (r_val > 0 && (ret_val < this->getValue())) ||
          (r_val < 0 && ret_val > this->getValue()))
      {
        std::stringstream	err;
        err << "Overflow on " << this->toString() << " + " << rhs.toString() << " !";
        throw std::overflow_error(err.str());
      }

      return ret;
    }

  template <typename T>
    IOperand *Operand<T>::operator-(const IOperand &rhs) const
    {
      Tuple<long double, eOperandType> tup = this->doCalcul(rhs, SUB);
      IOperand		*ret = utils::InstIOpByType(tup.getRight(), tup.getLeft());

      /* Check overflow */
      std::stringstream		ss;
      ss << rhs.toString() << " " << ret->toString();
      double r_val, ret_val;
      ss >> r_val >> ret_val;
      //-100 - 30
      if ((r_val < 0 && this->value > 0 && ret_val < 0) ||
          (this->value < 0 && r_val > 0 && ret_val > 0))
      {
        std::stringstream	err;
        err << "Overflow on " << this->toString() << " - " << rhs.toString() << " !";
        throw std::overflow_error(err.str());
      }
      return ret;
    }

  template <typename T>
    IOperand *Operand<T>::operator*(const IOperand &rhs) const
    {
      Tuple<long double, eOperandType> tup = this->doCalcul(rhs, MUL);

      IOperand		*ret = utils::InstIOpByType(tup.getRight(), tup.getLeft());

      /* Check overflow */
      std::stringstream		ss;
      ss << rhs.toString() << " " << ret->toString();
      double r_val, ret_val;
      ss >> r_val >> ret_val;

      if ((((this->getValue() > 0) ^ (r_val > 0)) == (ret_val > 0)) ||
          (ret->getType() != FLOAT && ret->getType() != DOUBLE && (ret_val / r_val != this->value)))
      {
        std::stringstream	err;
        err << "Overflow on " << this->toString() << " * " << rhs.toString() << " !";
        throw std::overflow_error(err.str());
      }
      return ret;
    }

  template <typename T>
    IOperand *Operand<T>::operator/(const IOperand &rhs) const
    {
      Tuple<long double, eOperandType> tup = this->doCalcul(rhs, DIV);

      return utils::InstIOpByType(tup.getRight(), tup.getLeft());
    }

  template <typename T>
    IOperand *Operand<T>::operator%(const IOperand &rhs) const
    {
      Tuple<long double, eOperandType> tup = this->doCalcul(rhs, MODULO);
      IOperand		*ret = utils::InstIOpByType(tup.getRight(), tup.getLeft());
      return ret;
    }


  template <typename T>
  Tuple<long double,eOperandType> Operand<T>::doCalcul(const IOperand &rhs, const eOperationType op) const
  {
    std::stringstream	values;
    double tmp_l;
    double tmp_r;

    values << this->toString() << " " << rhs.toString();
    values >> tmp_l;
    values >> tmp_r;

    double tmp;

    switch (op)
    {
      case ADD: tmp = tmp_l + tmp_r; break;
      case SUB: tmp = tmp_l - tmp_r; break;
      case MUL: tmp = tmp_l * tmp_r; break;
      case DIV: tmp = tmp_l / tmp_r; break;
      case MODULO: tmp = MOD(tmp_l, tmp_r); break;
    }

    eOperandType	final_type; /* On prend le plus grd type / ternaire */

    /* choose biggest type */
    if (rhs.getPrecision() > this->getPrecision())
      final_type = rhs.getType();
    else
      final_type = this->getType();

    Tuple<long double, eOperandType> ret(tmp, final_type);
    return ret;
  }

};


#endif		/* _OPERANDS_HH_ */
