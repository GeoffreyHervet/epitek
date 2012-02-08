#ifndef IMONITORMODULE_H_
# define IMONITORMODULE_H_

enum ModuleType
{
  MOD_EMPTY     = 0,
  MOD_CPU	= 1 << 0,
  MOD_RAM       = 1 << 1,
  MOD_COMPUTER  = 1 << 2,
  MOD_OS	= 1 << 3,
  MOD_TIMEINFO	= 1 << 4,
  MOD_NETWORK	= 1 << 5,
  MOD_SWAP	= 1 << 6,
  MOD_LOADAVG	= 1 << 7,
  MOD_UPTIME	= 1 << 8,
  MOD_ALL = (1 << 9) - 1
};

class IMonitorModule
{
  public:
    virtual ~IMonitorModule();

    virtual void updateInfo() = 0;
};

#endif // !IMONITORMODULE_H_
