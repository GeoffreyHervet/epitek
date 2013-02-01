#ifndef CREDITS_HPP_
# define CREDITS_HPP_

# include		"AMenuObject.hpp"

namespace		Menu
{
  class			Credits : public AMenuObject
  {
    private:
      Credits(const Credits&);
      Credits& operator=(const Credits &);
    public:
      Credits(const std::string &);
      ~Credits();

      bool	 	selected(IMenu&, MyGame&, gdl::Input &);
  };
}


#endif /* CREDITS_HPP_ */
