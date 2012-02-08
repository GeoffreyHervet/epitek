//
// QtDisplay.cpp for Qt in /home/hervet_g/rush/rush3/mygkrellm/src/Display/Qt
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Sat Jan 21 17:44:51 2012 geoffrey hervet
// Last update Sat Jan 21 17:44:51 2012 geoffrey hervet
//

#include	<iostream>
#include	<unistd.h>

#include	<stdlib.h>

#include "Trace.h"

#include "QtDisplay.h"
#include "Window.h"

QtDisplay::QtDisplay(int ac, char **av)
  : _ac(ac),
    _av(av),
    _modulesController(NULL)
{
  PRINT_TRACE();
}

QtDisplay::~QtDisplay()
{
  PRINT_TRACE();
}

void QtDisplay::setModulesController(ModulesController* var)
{
  PRINT_TRACE();


  this->_modulesController = var;
}

void QtDisplay::run()
{
  PRINT_TRACE();

  QApplication app(this->_ac, (this->_av));
  Window	win(this->_modulesController);
  win.show();

  app.exec();
}
