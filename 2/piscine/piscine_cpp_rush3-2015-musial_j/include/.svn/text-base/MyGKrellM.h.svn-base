#ifndef MYGKRELLM_H_
# define MYGKRELLM_H_

# include <string>

# include "IMonitorDisplay.h"
# include "IMonitorModule.h"

class MyGKrellM
{
  public:
    MyGKrellM (int argc, char * argv[]);
    ~MyGKrellM ();

  public:
    int parseOptions(int argc, char* argv[]);
    static void usage(std::string const& progName);

  private:
    unsigned int	_modulesToEnable;
    ModulesController	_modulesController;
    IMonitorDisplay*	_display;
    DisplayType		_displayType;
};

#endif // !MYGKRELLM_H_
