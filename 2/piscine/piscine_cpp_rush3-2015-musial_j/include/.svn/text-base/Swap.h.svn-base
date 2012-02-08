#ifndef SWAP_H_
# define SWAP_H_

# include <string>

# include "Singleton.h"
# include "IMonitorModule.h"
# include "Storage.h"

namespace Mod
{
  class Swap : public Singleton<Swap>, public IMonitorModule
  {
    friend class Singleton<Swap>;

    private:
    Swap();
    Swap(Swap const&);
    void operator=(Swap const&);

    Storage _swap;
    bool _enable;

    public:
    ~Swap();

    virtual void updateInfo();
    bool isEnable() const;
    Storage const& getData() const;
  };
}

#endif /* !SWAP_H_ */
