#ifndef TIMEINFO_H_
# define TIMEINFO_H_

# include <ctime>

# include "Singleton.h"
# include "IMonitorModule.h"

namespace Mod
{
  class TimeInfo : public Singleton<TimeInfo>, public IMonitorModule
  {
    friend class Singleton<TimeInfo>;

    private:
    TimeInfo();
    TimeInfo(TimeInfo const&);
    void operator=(TimeInfo const&);

    std::string _hour;
    std::string _date;
    time_t _uptime;

    void setTime();
    void setUptime();

    public:
    ~TimeInfo();

    virtual void updateInfo();
    std::string const& getHour() const;
    std::string const& getDate() const;
    time_t getUptime() const;
  };
}

#endif // !TIMEINFO_H_
