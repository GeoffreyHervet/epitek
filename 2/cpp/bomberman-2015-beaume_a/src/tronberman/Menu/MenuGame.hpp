#ifndef MENUGAME_HPP_
# define MENUGAME_HPP_

# include		<Text.hpp>

# include		"MyGame.hpp"
# include		"AMenu.hpp"
# include	        "ISoundManager.hpp"

namespace		Menu
{
  class			Game : public AMenu
  {
    private:
      Game(const Game &);
      Game &operator=(const Game &);
    public:
      Game(MyGame &, gdl::Input &);
      ~Game(void);

      void		update(gdl::Input &);
      void		draw(gdl::Window &);
      void		reset(void);

    private:
      std::vector<AMenuObject *> _items;
  };
}

#endif /* MENUGAME_HPP_ */
