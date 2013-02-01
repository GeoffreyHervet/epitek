#include	"Resume.hpp"

namespace	Menu
{

  Resume::Resume(const std::string &name) :
    AMenuObject(name)
  {
  }

  Resume::~Resume()
  {
  }

  bool	Resume::selected(::Menu::IMenu &, MyGame &game, gdl::Input &)
  {
    game.setState(MyGame::GAME);
    return true;
  }
}
