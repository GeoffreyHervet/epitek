#ifndef LOADAVG_H_
# define LOADAVG_H_

# include <string>

# include "Singleton.h"
# include "IMonitorModule.h"

namespace Mod
{
  class LoadAvg : public Singleton<LoadAvg>, public IMonitorModule
  {
    friend class Singleton<LoadAvg>;

    private:
    LoadAvg();
    LoadAvg(LoadAvg const&);
    void operator=(LoadAvg const&);

    std::string _loadAvg;

    public:
    ~LoadAvg();

    void updateInfo();
    std::string getLoadAvg() const;
  };
}


#endif /* !LOADAVG_H_ */
