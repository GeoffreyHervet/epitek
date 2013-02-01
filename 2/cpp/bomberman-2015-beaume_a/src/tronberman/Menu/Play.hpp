#ifndef PLAY_HPP_
# define PLAY_HPP_

# include	<vector>
# include	<Text.hpp>

# include	"AMenu.hpp"
# include	"AMenuObjectEditable.hpp"
# include	"MyGame.hpp"

namespace	Menu
{
  class		Play : public AMenu
  {
    private:
      Play(const Play &);
      Play &operator=(const Play &);
    public:
      Play(MyGame &, gdl::Input &);
      ~Play();

      void	update(gdl::Input &);
      void	draw(gdl::Window &);

    private:
      bool				_error_map;
      std::vector<AMenuObjectEditable *> _items;
  };
}

#endif /* PLAY_HPP_ */
