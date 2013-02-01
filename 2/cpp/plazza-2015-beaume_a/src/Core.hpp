#ifndef CORE_HPP_
# define CORE_HPP_

# include <stdexcept>

/*!
 * \class 	Core
 * \brief 	Program Core
 *              Argument parsing
 *              User input
 *              Execution
 * \author      Aymeric Beaumet
 */
class Core
{
  public:
    Core();
    ~Core();

    /*!
     * \brief   Parse argument (argv)
     */
    void	Init(int argc = 0, char **argv = 0);
    /*!
     * \brief   Launch execution
     */
    void	Exec();

  private:
    double		_mult_time;
    unsigned int	_kitchen_cookers_nbr;
    unsigned int	_fill_ingredient_ms_time;

    void	Usage(char const *argv0);

  public:
    /*!
     * \class Error
     * \brief Exception class of Core
     */
    class Error : public std::exception
    {
      const char  *_what; /*!< Content of exception */
      public:
      /*!
       * \brief Constructor of Error
       * \param what Error message
       */
      Error(const char *what) throw() : _what(what){};

      /*!
       * \brief Getter of message error
       * \return Message error
       */
      const char *what() const throw() { return this->_what; };
    };
};

#endif // !CORE_HPP_
