#include <iostream>
#include <string>

#include "Trace.hh"

#include "ElfDePePeNoel.hh"
#include "PetitPoney.hh"
#include "TablePePeNoel.hh"
#include "TapisRoulantPePeNoel.hh"
#include "Carton.hh"
#include "PapierCadeau.hh"
#include "Nounours.hh"
#include "serialize.hh"
#include "TableAleat.hh"
#include "TapisRoulantAleat.hh"

int main(void)
{
  ElfDePePeNoel elf1;
  ElfDePePeNoel elf2(elf1);
  ElfDePePeNoel elf3;
  elf2 = elf1;
  TablePePeNoel table;
  TapisRoulantPePeNoel tapisRoulant;

  Nounours toto("IgiX");
  PapierCadeau pc;
  Carton c;
  PapierCadeau c2;
  Carton c3;

  Nounours n("nounours");
  PetitPoney pp("barbie's poney");

  // elf3 = elf1;

  // elf3.setTable(&table);
  // elf3.setTapisRoulant(&tapisRoulant);

  // elf3.emballerTousLesCadeaux();

  // std::cout << "==========================" << std::endl;

  TableAleat aleat(50);
  TapisRoulantAleat tapisaleat;

  elf3.setTable(&aleat);
  elf3.setTapisRoulant(&tapisaleat);
  elf3.emballerTousLesCadeaux();

  return 0;
}
