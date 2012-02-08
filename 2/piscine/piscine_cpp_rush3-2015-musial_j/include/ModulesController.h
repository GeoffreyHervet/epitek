#ifndef MODULESCONTROLLER_H_
# define MODULESCONTROLLER_H_

# include <vector>

# include "IMonitorModule.h"
# include "RAM.h"
# include "Computer.h"
# include "Network.h"
# include "TimeInfo.h"
# include "OS.h"
# include "CPU.h"
# include "Swap.h"
# include "LoadAvg.h"
# include "Uptime.h"

# define IS_MOD_ENAB(i, j) ((i & j) != 0)

class ModulesController
{
  public:
    ModulesController();
    ~ModulesController();

  private:
    unsigned int _modulesEnabled;
    std::vector<IMonitorModule*> _modulesList;

  public:
    void setModules(unsigned int);
    void run();
    void launch(unsigned int flag);
    void launchAll();
    void kill(unsigned int flag);
    void killAll();
    void update(unsigned int flag);
    void updateAll();
    bool isEnabled(unsigned int flag) const;
    std::vector<IMonitorModule*> const& getList() const;
    unsigned int countActivated() const;
    IMonitorModule* getModule(unsigned int flag) const;
};

#endif // !MODULESCONTROLLER_H_
