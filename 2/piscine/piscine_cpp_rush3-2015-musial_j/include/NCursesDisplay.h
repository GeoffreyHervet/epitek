#ifndef NCURSESDISPLAY_H_
# define NCURSESDISPLAY_H_

# include <ncurses.h>
# include <string>

# include "IMonitorDisplay.h"
# include "ModulesController.h"

class NCursesDisplay : public IMonitorDisplay
{
  public:
    NCursesDisplay();
    ~NCursesDisplay();
    void refresh_stats();
    virtual void setModulesController(ModulesController*);
    ModulesController* getController();
    virtual void run();
    int getColor(unsigned int);
    int getColorCPU(unsigned int);
    void showCPU(std::basic_string<char>, float);
    int line;
  private:
    WINDOW* window;
    ModulesController* _modulesController;
};

#endif // !NCURSESDISPLAY_H_
