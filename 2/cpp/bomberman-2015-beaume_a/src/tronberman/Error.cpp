# include			"Error.hpp"

std::ostream		&operator <<(std::ostream &os, Error::eLevel lvl)
{
  switch (lvl)
  {
    case ::Error::NOTICE: std::cerr << "NOTICE"; break;
    case ::Error::WARN: std::cerr << "WARN"; break;
    case ::Error::CRITICAL: std::cerr << "CRITICAL"; break;
  }
  return os;
}
