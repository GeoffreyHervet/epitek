#ifndef MENU_HPP_
# define MENU_HPP_

# include <vector>
# include <string>
# include <map>

# include <Window.hpp>
# include <Input.hpp>

# include "AMenu.hpp"
# include "Text.hpp"
# include "MyGame.hpp"
# include "AMenuObject.hpp"
# include "ISoundManager.hpp"

namespace	Menu
{
  class		Main : public ::Menu::AMenu
  {
    private:
      Main(const Main &);
      Main &operator=(const Main &);

    public:
      Main(MyGame &, gdl::Input &);
      ~Main();

    public:
      Main			&operator<<(AMenuObject *);
      void			 update(gdl::Input &);
      void			 draw(gdl::Window &);
      void			 clear();

    private:
      std::vector<AMenuObject *>	_items;
  };
}

#endif /* MENU_HPP_ */
