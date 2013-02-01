#include	"SaveGame.hpp"

namespace	Menu
{

  SaveGame::SaveGame(const std::string &name) :
    AMenuObject(name)
  {
  }

  SaveGame::~SaveGame()
  {
  }

  bool	SaveGame::selected(::Menu::IMenu &, MyGame &game, gdl::Input &)
  {
    game.saveGame();
    return true;
  }
}
