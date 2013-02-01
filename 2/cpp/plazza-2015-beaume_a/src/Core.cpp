#include	<string>
#include	<iostream>
#include	<vector>
#include	<iostream>
#include	<cstdlib>
#include	<cerrno>

#include	"Ingredients.hpp"
#include	"Menu.hpp"
#include	"Cook.hpp"
#include	"Kitchen.hpp"
#include	"MySDL.hpp"
#include	"Core.hpp"

Core::Core()
{
}

Core::~Core()
{
}

void	Core::Usage(char const *argv0)
{
  throw Error(std::string("Usage: " + std::string(argv0) + " mult_time cookers_nbr fill_ingredient time").c_str());
}

void	Core::Init(int argc, char **argv)
{
  if (argc != 4)
    Usage(argv[0]);
  this->_mult_time = atof(argv[1]);
  if (!(this->_mult_time > 0 && this->_mult_time < 1))
  {
    std::cerr << "Bad cookers number value (must be 0 < value < 1)." << std::endl;
    Usage(argv[0]);
  }
  errno = 0;
  this->_kitchen_cookers_nbr = strtol(argv[2], NULL, 10);
  if (errno != 0 || this->_kitchen_cookers_nbr == 0)
  {
    std::cerr << "Bad cookers number value (must be > 0)." << std::endl;
    Usage(argv[0]);
  }
  errno = 0;
  this->_fill_ingredient_ms_time = strtol(argv[3], NULL, 10);
  if (errno != 0 || this->_fill_ingredient_ms_time == 0)
  {
    std::cerr << "Bad fill ingredient number value (must be > 0)." << std::endl;
    Usage(argv[0]);
  }
}

void	Core::Exec()
{
  MySDL				sdl(840, 420, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
  Menu				menu;
  Kitchen			kitchen(10, 0);
  unsigned			i = 0;

  if (menu.newPizza("	Regina 2 pate toMAte GRuyere jAMboN chAMPIgnon"))
    std::cout << "some new ingr\n";
  if (menu.newPizza("   Margarita     1    PATE	tomATE	   grUYere   "))
    std::cout << "some new ingr\n";
  if (menu.newPizza("AmericaINE    2 pate TOMATE      grUYEre STEAK  "))
    std::cout << "some new ingr\n";
  if (menu.newPizza("  FantASIA   4 pate tomatE AUBERgines	CHEVRE		"))
    std::cout << "some new ingr\n";

  std::cout << "\n";

  menu.print();

  /*kitchen.commandPizza(menu.getPizza(1), Pizza::XXL);
  kitchen.commandPizza(menu.getPizza(0), Pizza::M);
  kitchen.commandPizza(menu.getPizza(999), Pizza::L);
  kitchen.commandPizza(menu.getPizza("s"), Pizza::XL);
  kitchen.commandPizza(menu.getPizza("fantasia"), Pizza::XL);
  kitchen.commandPizza(menu.getPizza("regina"), Pizza::XL);
  kitchen.commandPizza(menu.getPizza("regina"), Pizza::XL);
  kitchen.commandPizza(menu.getPizza("americaine"), Pizza::XL);
  */

  kitchen.enlargeNbIngrs(5);

  kitchen.print(menu);

  while (1)
    {
      if (++i % 200 == 0)
	kitchen.commandPizza(menu.getPizza("fantasia"), Pizza::XL);
      sdl.events();
      kitchen.moveCooks(sdl.getFrametime());
      sdl.render(kitchen);
    }
}
