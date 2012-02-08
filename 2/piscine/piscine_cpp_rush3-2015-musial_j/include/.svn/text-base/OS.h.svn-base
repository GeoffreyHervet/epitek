#ifndef OS_H_
# define OS_H_

# include <string>

# include "Singleton.h"
# include "IMonitorModule.h"

namespace Mod
{
  class OS : public Singleton<OS>, public IMonitorModule
  {
    friend class Singleton<OS>;

    private:
    OS();
    OS(OS const&);
    void operator=(OS const&);

    std::string _osType;
    std::string _osRelease;
    std::string _kernelVersion;
    unsigned int _bits;

    void setBits();
    void setOSType();
    void setOSRelease();
    void setKernelVersion();

    public:
    ~OS();

    virtual void updateInfo();
    std::string const& getOSType() const;
    std::string const& getOSRelease() const;
    std::string const& getKernelVersion() const;
    bool is32b() const;
    bool is64b() const;
  };
}

#endif // !OS_H_
