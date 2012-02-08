#include		<algorithm>
#include		<iostream>

#include		"utils.h"

namespace		utils
{
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
