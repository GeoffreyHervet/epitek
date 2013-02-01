#include <stdio.h>
#include <QtGui>
#include "QtDisplay.h"

extern "C"
{
  Nibbler::IGraphic	*ctor(int h, int w, int ac, char **av)
  {
    QApplication		*app = new QApplication(ac, av);
    QtDisplay			*ret = new QtDisplay(h, w);

    ret->setApp(app);
    ret->show();
    ret->grabKeyboard();
    ret->grabMouse();
    return ret;
  }
};
