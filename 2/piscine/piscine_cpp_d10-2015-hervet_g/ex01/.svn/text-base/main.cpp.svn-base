//
// main.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d10-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 13 14:16:59 2012 geoffrey hervet
// Last update Fri Jan 13 14:16:59 2012 geoffrey hervet
//

#include	<iostream>
#include	<string>

#include	"PowerFist.hh"
#include	"Character.hh"
#include	"RadScorpion.hh"
#include	"PlasmaRifle.hh"

int	main()
{
  Character* zaz = new Character("zaz");

  std::cout << *zaz;

  AEnemy* b = new RadScorpion();
  AWeapon* pr = new PlasmaRifle();
  AWeapon* pf = new PowerFist();

  zaz->equip(pr);
  std::cout << *zaz;
  zaz->equip(pf);

  zaz->attack(b);
  std::cout << *zaz;
  zaz->equip(pr);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;

  return 0;
}
