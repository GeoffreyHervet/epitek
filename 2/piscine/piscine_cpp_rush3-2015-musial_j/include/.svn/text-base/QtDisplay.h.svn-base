#ifndef QTDISPLAY_H_
# define QTDISPLAY_H_

# include "IMonitorDisplay.h"
# include "ModulesController.h"

class		QtDisplay :
  public	  IMonitorDisplay
{
  public:
    QtDisplay(int ac, char *av[]);
    ~QtDisplay();

    virtual void setModulesController(ModulesController*);
    virtual void run();

  private:
    int _ac;
    char **_av;
    ModulesController* _modulesController;
};

#endif // !QTDISPLAY_H_
