#include	"Credits.hpp"
#include	"CreditsView.hpp"

namespace		Menu
{
  Credits::Credits(const std::string &s)
    : AMenuObject(s)
  {
  }

  Credits::~Credits()
  {
  }

  bool			Credits::selected(IMenu &, MyGame &game, gdl::Input&i)
  {
    game.setMenu(new Menu::CreditsView(game, i));
    return true;
  }
};
