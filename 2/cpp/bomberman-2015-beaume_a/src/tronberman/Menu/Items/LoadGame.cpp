#include	"LoadGame.hpp"
#include	"Loader.hpp"

namespace Menu
{
  LoadGame::LoadGame(const std::string &s) :
    AMenuObject(s)
  {
  }

  LoadGame::~LoadGame()
  {
  }

 bool		LoadGame::selected(IMenu &, MyGame &game, gdl::Input &i)
  {
    game.setMenu(new Menu::Loader(game, i));
    return true;
  }
}
