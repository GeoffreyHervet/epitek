#ifndef LOAD_GAME_HPP
# define LOAD_GAME_HPP

# include	"AMenuObject.hpp"

namespace		Menu
{
  class			LoadGame : public AMenuObject
  {
    private:
      LoadGame(const LoadGame &);
      LoadGame &operator=(const LoadGame &);
    public:
      LoadGame(const std::string &);
      ~LoadGame();

      bool	 	selected(IMenu&, MyGame&, gdl::Input &);
  };
}

#endif /* !LOAD_GAME_HPP */
