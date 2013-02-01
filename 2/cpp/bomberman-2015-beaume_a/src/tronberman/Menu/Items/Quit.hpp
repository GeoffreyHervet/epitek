#ifndef QUIT_HPP_
# define QUIT_HPP_

# include		"AMenuObject.hpp"

namespace		Menu
{
  class			Quit : public AMenuObject
  {
    private:
      Quit(const Quit&);
      Quit& operator=(const Quit &);
    public:
      Quit(const std::string &);
      ~Quit();

      bool	 	selected(IMenu &, MyGame &, gdl::Input &);
  };
}


#endif /* QUIT_HPP_ */
