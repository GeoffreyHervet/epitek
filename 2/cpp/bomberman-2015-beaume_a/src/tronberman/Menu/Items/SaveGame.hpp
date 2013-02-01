#ifndef SAVEGAME_HPP_
# define SAVEGAME_HPP_

namespace	Menu {
  class		SaveGame;
};

# include	"AMenuObject.hpp"

namespace	Menu
{
  class		SaveGame : public AMenuObject
  {
    private:
      SaveGame(const SaveGame &);
      SaveGame &operator=(const SaveGame &);

    public:
      SaveGame(const std::string &);
      ~SaveGame();

      bool	 	selected(IMenu &, MyGame &, gdl::Input &);
  };
}

#endif /* SAVEGAME_HPP_ */
