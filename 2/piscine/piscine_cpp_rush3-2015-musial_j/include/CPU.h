#ifndef CPU_H_
# define CPU_H_

# include <string>
# include <list>
# include <map>
# include <ctime>
# include <sys/time.h>
# include "Singleton.h"
# include "IMonitorModule.h"

struct	activityStats
{
  std::string name;
  int work;
  int total;
};

namespace Mod
{
  class CPU : public Singleton<CPU>, public IMonitorModule
  {
    friend class Singleton<CPU>;

  private:
    CPU();
    CPU const& operator=(CPU const&);

    void setModel(std::string);
    void setCoreNbr(std::string);
    void setFrequency(std::string);
    void setTemperature(std::string);
    void setActivity();

    std::string _model;
    unsigned int _coreNbr;
    float _frequency;
    std::string _temperature;
    std::list<activityStats> _activityStats;
    std::map<std::string, float> _activity;
    timeval _timestamp;

  public:
    ~CPU();

    virtual void updateInfo();
    std::string const& getModel() const;
    unsigned int getCoreNbr() const;
    float getFrequency() const;
    std::string const& getTemperature() const;
    std::map<std::string, float> const& getActivity() const;
  };
}

#endif /* !CPU_H_ */
