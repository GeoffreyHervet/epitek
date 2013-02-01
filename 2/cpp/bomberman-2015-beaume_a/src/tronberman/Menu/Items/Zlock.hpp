#ifndef ZLOCK_HPP_
# define ZLOCK_HPP_

# include		"AMenuObject.hpp"

namespace		Menu
{
  class			  Zlock: public AMenuObject
  {
    private:
      Zlock(const Zlock &);
      Zlock &operator=(const Zlock &);
    public:
      Zlock(const std::string &);
      ~Zlock();

      bool      	selected(IMenu &, MyGame &game, gdl::Input &);
  };
}

#endif /* ZLOCK_HPP_ */
