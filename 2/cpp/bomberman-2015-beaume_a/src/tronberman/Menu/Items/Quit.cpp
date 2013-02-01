#include	"Quit.hpp"

namespace		Menu
{
  Quit::Quit(const std::string &s)
    : AMenuObject(s)
  {
  }

  Quit::~Quit()
  {
  }

  bool			Quit::selected(IMenu &, MyGame &game, gdl::Input &)
  {
    game.setState(MyGame::STOP);
    return true;
  }
};
