#include	<exception>
#include	<cstdlib>
#include	<iostream>

#include	"Core.hpp"

int 		main(int argc, char **argv)
{
  Core		app;

  try
  {
    app.Init(argc, argv);
    app.Exec();
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
