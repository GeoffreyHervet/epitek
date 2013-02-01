#include	"Main.hpp"
#include	"BackToMain.hpp"

namespace	Menu
{

  BackToMain::BackToMain(const std::string &name) :
    AMenuObject(name)
  {
  }

  BackToMain::~BackToMain()
  {
  }

  bool	BackToMain::selected(::Menu::IMenu &, MyGame &game, gdl::Input&)
  {
    game.setState(MyGame::MENU);
    game.setMainMenu();
    return true;
  }
}
