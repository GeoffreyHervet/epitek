//
// main.cpp for ex02 in /home/hervet_g/piscine/piscine_cpp_d06-2015-hervet_g/ex02
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 09 13:19:51 2012 geoffrey hervet
// Last update Mon Jan 09 13:19:51 2012 geoffrey hervet
//

#include	<iostream>
#include	<iomanip>

#include	"sickkoala.h"
#include	"koalanurse.h"
#include	"koaladoctor.h"

int		main()
{
  SickKoala	koal("IgiX");
  KoalaDoctor	dr("Boubak");
  KoalaNurse	nurse(42);

  koal.poke();
  dr.diagnose(&koal);
  koal.takeDrug(nurse.readReport("IgiX.report"));


  return 0;
}
