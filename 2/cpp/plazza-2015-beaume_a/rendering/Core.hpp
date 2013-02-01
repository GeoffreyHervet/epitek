#ifndef CORE_HPP_
# define CORE_HPP_

# include <stdexcept>

class Core
{
  public:
    Core(int argc = 0, char **argv = 0);
    ~Core();

  private:
    double		_mult_time;
    unsigned int	_kitchen_cookers_nbr;
    unsigned int	_fill_ingredient_ms_time;

  public:
    class Error : public std::exception
    {
      private:
        char const	*_what;
  
      public:
        Error(const char *what) throw()
        {
          this->_what = what;
        };
        const char *what() const throw()
        {
          return (this->_what);
        };
    };
};

#endif // !CORE_HPP_
