//
// header for norme in /
// 
// Made by geoffrey hervet
// Login   <hervet_g@epitech.eu>
// 
// Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
// Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
//

#include	<iostream>

#include	"Banana.h"
#include	"Citron.h"

int main(void)
{
  Citron c;
  Banana b;
  std::cout << c.getVitamins() << std::endl;
  std::cout << b.getVitamins() << std::endl;
  std::cout << c.getName() << std::endl;
  std::cout << b.getName() << std::endl;
  Fruit& f = c;
  std::cout << f.getVitamins() << std::endl;
  std::cout << f.getName() << std::endl;
  return 1337;
}
