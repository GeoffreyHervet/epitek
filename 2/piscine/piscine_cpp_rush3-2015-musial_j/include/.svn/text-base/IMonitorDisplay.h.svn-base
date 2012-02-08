#ifndef IMONITORDISPLAY_H_
# define IMONITORDISPLAY_H_

# include "ModulesController.h"

enum DisplayType
{
  DISP_NONE,
  DISP_DEBUG,
  DISP_CONSOLE,
  DISP_GRAPHIC
};

class IMonitorDisplay
{
  public:
    virtual ~IMonitorDisplay();

    virtual void setModulesController(ModulesController*) = 0;
    virtual void run() = 0;
};

#endif // !IMONITORDISPLAY_H_
