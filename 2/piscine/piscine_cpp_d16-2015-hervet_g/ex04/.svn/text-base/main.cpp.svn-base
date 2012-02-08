//
// main.cpp for ex04 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex04
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 21:50:54 2012 geoffrey hervet
// Last update Thu Jan 19 21:50:54 2012 geoffrey hervet
//

#include	"Ratatouille.h"

using namespace std;

int main()
{
  Ratatouille rata;

  rata.addSauce("Tomate").addCondiment(42).addSpice(123.321);
  rata.addVegetable('x');

  std::cout << "On goute: " << rata.kooc() << std::endl;

  rata.addSauce("Bolognaise");
  rata.addSpice(3.14);

  std::cout << "Vas-y goute moi ca: " << rata.kooc() << std::endl;

  // Attend vas-y donne ta marmite j'en prend un peu et j'essaie un autre truc
  Ratatouille glurp(rata);

  glurp.addVegetable('p');
  glurp.addVegetable('o');
  glurp.addSauce("Tartare");

  std::cout << "Et maintenant: " << glurp.kooc() << std::endl;

  // OK je prend c'est bon...
  rata = glurp;
  std::cout << "Je regoute c'est trop booon: " << rata.kooc() << std::endl;
  return 0;
}
