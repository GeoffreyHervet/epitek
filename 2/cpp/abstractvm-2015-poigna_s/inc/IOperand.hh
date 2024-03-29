#ifndef		_IOPERAND_HH_
#define		_IOPERAND_HH_

#include	<iostream>

namespace			avm
{
  enum				eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
  };

  enum				eOperationType
  {
    ADD,
    SUB,
    MUL,
    DIV,
    MODULO
  };

  class				IOperand
  {
  public:
    virtual ~IOperand() {};

    virtual std::string const&	toString()		const = 0;

    virtual int			getPrecision()		const = 0;
    virtual eOperandType	getType()		const = 0;

    virtual IOperand *operator+(const IOperand &rhs)	const = 0;
    virtual IOperand *operator-(const IOperand &rhs)	const = 0;
    virtual IOperand *operator*(const IOperand &rhs)	const = 0;
    virtual IOperand *operator/(const IOperand &rhs)	const = 0;
    virtual IOperand *operator%(const IOperand &rhs)	const = 0;
  };
};

std::ostream		&operator<<(std::ostream &os, const avm::IOperand &op);

#endif		/* _IOPERAND_HH_ */
