#ifndef COMPUTER_H_
# define COMPUTER_H_

# include <string>

# include "Singleton.h"
# include "IMonitorModule.h"

namespace Mod
{
  class Computer : public Singleton<Computer>, public IMonitorModule
  {
    friend class Singleton<Computer>;

    private:
    Computer();
    Computer(Computer const&);
    void operator=(Computer const&);

    void setComputerName();
    void setUserName();

    std::string _computerName;
    std::string _userName;

    public:
    ~Computer();

    virtual void updateInfo();

    std::string const& getComputerName() const;
    std::string const& getUserName() const;
  };
}

#endif /* !COMPUTER_H_ */
