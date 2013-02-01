#include		<algorithm>
#include		<iostream>
#include		<sys/types.h>

#include		"utils.h"
#include		"Operands.hh"

namespace		utils
{
  avm::IOperand		*InstIOpByType(avm::eOperandType type, const long double &val)
  {
    switch (type)
    {
      case avm::INT8:   return new avm::Operand<int8_t> (val, type); break;
      case avm::INT16:  return new avm::Operand<int16_t>(val, type); break;
      case avm::INT32:  return new avm::Operand<int32_t>(val, type); break;
      case avm::FLOAT:  return new avm::Operand<float>  (val, type); break;
      case avm::DOUBLE: return new avm::Operand<double> (val, type); break;
    };
    return NULL;
  }

  std::string		strToLower(const std::string &src)
  {
    std::string		ret(src);

    for (unsigned int idx = 0; ret[idx]; idx++)
      if (ret[idx] >= 'A' && ret[idx] <= 'Z')
        ret[idx] += 'a' - 'A';
    return ret;
  }

  void			replace_chars::operator()(char &c) const
  {
    if (c == this->_a)
      c = this->_b;
  }
};
