#include		"FastGame.hpp"
#include		"Map.hpp"

namespace		Menu
{
  FastGame::FastGame(std::string const& s) :
    AMenuObject(s)
  {
  }

  FastGame::~FastGame()
  {
  }


  bool			FastGame::selected(IMenu&, MyGame& game, gdl::Input &)
  {
    unsigned		w = rand() % 20 + 10;
    Map*		map = new Map(w, w);

    map->randomize();
    map->wallAround();

    game.reset();
    game.setMap(map);
    game.setState(MyGame::GAME);

    game.getPlayers().RealsPlayers("Joueur 1", "Joueur 2", map);
    // game._players.putSomeBots(1, m.getMap(), game._bombs);
    game.getPlayers().putSomeBots(1, map, game.getBombs());

    game.newPart();
    game.initCam();
    return true;
  }
}
