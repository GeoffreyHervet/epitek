#ifndef NETWORK_H_
# define NETWORK_H_

# include <map>
# include <string>

# include "Singleton.h"
# include "IMonitorModule.h"

struct	netPackets
{
  int	receive;
  int	transmit;
};

namespace Mod
{
  class Network : public Singleton<Network>, public IMonitorModule
  {
    friend class Singleton<Network>;

    private:
    Network();
    Network(Network const&);
    void operator=(Network const&);

    void subFrontSpace(std::string &);
    void strJump(std::string &);

    std::map<std::string, netPackets> _packets;

    public:
    ~Network();
    std::map<std::string, netPackets> const& getPackets() const;
    virtual void updateInfo();
  };
}

#endif /* !NETWORK_H_ */
