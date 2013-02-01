#ifndef BackToMain_HPP_
# define BackToMain_HPP_

namespace	Menu {
  class		BackToMain;
};

# include	"AMenuObject.hpp"

namespace	Menu
{
  class		BackToMain : public AMenuObject
  {
    private:
      BackToMain(const BackToMain &);
      BackToMain &operator=(const BackToMain &);

    public:
      BackToMain(const std::string &);
      ~BackToMain();

      bool	 	selected(IMenu&, MyGame&, gdl::Input &);
  };
}

#endif /* BackToMain_HPP_ */
