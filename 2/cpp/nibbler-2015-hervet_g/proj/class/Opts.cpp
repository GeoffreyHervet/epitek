#include "Opts.h"

Opts::Opts(int ac, char **av, const char *def)
{
  std::string		defValue(def);

  for (int idx = 1; idx < ac; ++idx)
  {
    if (av[idx][0] == '-' && av[idx][1] == '-' && !av[idx][2])
      break;
    if (av[idx][0] == '-' && av[idx][1])
    {
      //big option --name=value
      if (av[idx][1] == '-')
      {
        size_t idx2 = 1;
        while (av[idx][idx2] && av[idx][idx2] != '=')
          ++idx2;
        if (!av[idx][idx2])
          this->_opts[std::string(&av[idx][2])] = defValue;
        else
        {
          av[idx][idx2] = 0;
          this->_opts[std::string(&av[idx][2])] = std::string(&av[idx][idx2 + 1]);
        }
      }
      else if (!av[idx][2])
      {
        if ((idx + 1) < ac && av[idx + 1][0] != '-')
        {
          this->_opts[std::string(&av[idx][1])] = std::string(av[idx + 1]);
          ++idx;
        }
        else
          this->_opts[std::string(&av[idx][1])] = defValue;
      }
      else
      {
        size_t idx2 = 0;
        while (av[idx][++idx2])
          this->_opts[std::string(&av[idx][idx2])] = defValue;
        if ((idx + 1) < ac && av[idx + 1][0] != '-')
        {
          this->_opts[std::string(&av[idx][idx2 - 1])] = std::string(av[idx + 1]);
          ++idx;
        }
      }
    }
  }
}

Opts::~Opts()
{
}

const std::string	&Opts::operator [](const std::string &key)
{
  return this->getValue(key);
}

const std::string	&Opts::getValue(const std::string &key) 
{
  return this->_opts[key];
}

void			Opts::setValue(const std::string &key, const std::string &val)
{
  // duplicate key & val
  (this->_opts)[std::string(key)] = std::string(val);
}

bool			Opts::haveOption(const std::string &key)
{
  return !this->_opts[key].empty();
}

std::map<std::string, std::string>::const_iterator Opts::begin(void) const
{
  return this->_opts.begin();
}

std::map<std::string, std::string>::const_iterator Opts::end(void) const
{
  return this->_opts.end();
}
