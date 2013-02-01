#include	"PrePlay.hpp"
#include	"Play.hpp"

namespace	Menu
{
  PrePlay::PrePlay(const std::string &s) :
    AMenuObject(s)
  {
  }

  PrePlay::~PrePlay()
  {
  }

  bool		PrePlay::selected(IMenu &, MyGame &game, gdl::Input &i)
  {
    game.setMenu(new Menu::Play(game, i));
    return true;
  }
}
