#ifndef RAM_H_
# define RAM_H_

# include "Singleton.h"
# include "IMonitorModule.h"

namespace Mod
{
  class RAM : public Singleton<RAM>, public IMonitorModule
  {
    friend class Singleton<RAM>;

    private:
    RAM();
    RAM(RAM const&);
    void operator=(RAM const&);

    unsigned int _totalRam;
    unsigned int _freeRam;

    public:
    ~RAM();

    virtual void updateInfo();
    unsigned int getUsedRam() const;
    unsigned int getTotalRam() const;
    unsigned int getFreeRam() const;
    unsigned int getPercentRam() const;
  };
}

#endif // !RAM_H_
