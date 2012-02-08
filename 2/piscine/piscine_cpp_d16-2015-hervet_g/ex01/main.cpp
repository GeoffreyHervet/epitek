//
// main.cpp for ex01 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex01
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 13:57:22 2012 geoffrey hervet
// Last update Thu Jan 19 13:57:22 2012 geoffrey hervet
//

#include <iostream>
#include <cstdlib>

#include "DomesticKoala.h"
#include "KoalaAction.h"

int main(int argc, char **argv)
{
  KoalaAction action;
  DomesticKoala *dk = new DomesticKoala(action);
  dk->learnAction('<',&KoalaAction::eat);
  dk->learnAction('>',&KoalaAction::goTo);
  dk->learnAction('#',&KoalaAction::sleep);
  dk->learnAction('X', &KoalaAction::reproduce);
  dk->doAction('>',"{EPITECH.}");
  dk->doAction('<',"un DoubleCheese");
  dk->doAction('X',"une Mouette");
  dk->doAction('#',"La fin de la piscine C++, et d'un Astek brulant sur un bucher");
  return 0;
}
