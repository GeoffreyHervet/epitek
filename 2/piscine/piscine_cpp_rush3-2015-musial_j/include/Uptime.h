#ifndef UPTIME_H_
# define UPTIME_H_

# include <string>

# include "Singleton.h"
# include "IMonitorModule.h"

namespace Mod
{
  class Uptime : public Singleton<Uptime>, public IMonitorModule
  {
    friend class Singleton<Uptime>;

    private:
    Uptime();
    Uptime(Uptime const&);
    void operator=(Uptime const&);

    std::string _uptime;

    public:
    ~Uptime();

    void updateInfo();
    std::string getUptime() const;
  };
}


#endif /* !UPTIME_H_ */
