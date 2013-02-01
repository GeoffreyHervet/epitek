#ifndef IMENU_HPP_
# define IMENU_HPP_

# include	<Input.hpp>
# include	<Window.hpp>

namespace Menu {
  class IMenu;
}

# include	"AMenuObject.hpp"

namespace Menu
{
  class		IMenu
  {
    public:
      virtual ~IMenu(){};

      virtual void			 update(gdl::Input &) = 0;
      virtual void			 draw(gdl::Window &) = 0;
      virtual void			 init(const gdl::Window &) = 0;
  };
};

#endif /* IMENU_HPP_ */
