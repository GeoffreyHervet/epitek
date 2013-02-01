#ifndef LOADER_HPP_
# define LOADER_HPP_

# include	<vector>
# include	<Text.hpp>

# include	"AMenu.hpp"
# include	"AMenuObjectEditable.hpp"
# include	"MyGame.hpp"
# include	"ItemSave.hpp"

namespace Menu
{
  class		Loader : public AMenu
  {
    private:
      Loader(const Loader &);
      Loader &operator=(const Loader &);
    public:
      Loader(MyGame &, gdl::Input &);
      ~Loader();

      void	update(gdl::Input &);
      void	draw(gdl::Window &);

    private:
      ItemSave					*_item;
  };
}

#endif /* !LOADER_HPP_ */
