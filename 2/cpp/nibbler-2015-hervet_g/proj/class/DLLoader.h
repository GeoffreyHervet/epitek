#ifndef DLLOADER_H_
# define DLLOADER_H_

# include <iostream>
# include <dlfcn.h>
# include <vector>

class		DLLoader
{
  static std::vector<void *>	HANDLERS;

  public:
  class	Error
    : public std::exception
  {
    const char	*_what;
    public:
      Error(const char *what) throw()
      {
        this->_what = what;
      };
      const char *what() const throw()
      {
        return this->_what;
      };
  };

  static void		*getInstance(const char *file, const char *entryPoint="ctor", const int flag=RTLD_NOW);
  static void		 closeHandlers();
};

#endif /* DLLOADER_HPP_ */
