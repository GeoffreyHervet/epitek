//
// main.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d07m-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Tue Jan 10 11:24:18 2012 geoffrey hervet
// Last update Tue Jan 10 11:24:18 2012 geoffrey hervet
//

#include	"Federation.hh"
#include	"Warpsystem.hh"

int		main(void)
{
  Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
  Federation::Ship Independant(150, 230, "Greok");
  WarpSystem::QuantumReactor QR;
  WarpSystem::QuantumReactor QR2;
  WarpSystem::Core core(&QR);
  WarpSystem::Core core2(&QR2);

  UssKreog.setupCore(&core);
  UssKreog.checkCore();
  Independant.setupCore(&core2);
  Independant.checkCore();

  QR.setStability(false);
  QR2.setStability(false);
  UssKreog.checkCore();
  Independant.checkCore();

  return 0;
}
