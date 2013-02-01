#ifndef RESTART_HPP_
# define RESTART_HPP_

# include		"AMenuObject.hpp"

namespace		Menu
{
  class			  Restart: public AMenuObject
  {
    private:
      Restart(const Restart &);
      Restart &operator=(const Restart &);
    public:
      Restart(const std::string &);
      ~Restart();

      bool	 	selected(IMenu &, MyGame &, gdl::Input &);
  };
}

#endif /* RESTART_HPP_ */
