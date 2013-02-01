#include		<iostream>
#include		<utility>
#include		<cstdlib>
#include		"Core.hpp"
#include		"MyGame.hpp"

int			main(void)
{
  MyGame		game;
  Core			core;

  core.run();
  return EXIT_SUCCESS;
}
