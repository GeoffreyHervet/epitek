#include <fstream>
#include <map>
#include <string>
#include <sstream>

#include "Trace.h"

#include "Network.h"

static int StringToInt(std::string const& s)
{
  PRINT_TRACE();
  std::istringstream iss(s);
  long long int ret;

  iss >> ret;
  return ((int)(ret));
}

Mod::Network::Network()
{
  PRINT_TRACE();
  this->updateInfo();
}

Mod::Network::~Network()
{
  PRINT_TRACE();

#ifdef TRACE
  for(std::map<std::string, netPackets>::iterator it = this->_packets.begin(); it != this->_packets.end(); ++it ) {
    std::clog << "name: " << it->first
	      << ", receive: " << it->second.receive
	      << ", transmit: " << it->second.transmit << std::endl;
  }
#endif
}

void Mod::Network::updateInfo()
{
  PRINT_TRACE();

  std::ifstream in("/proc/net/dev");
  char buff[256];
  std::string tmp;
  std::string name;
  netPackets packets = {0, 0};

  if (!in.good())
    return;

  while (!in.eof())
    {
      in.getline(buff, 256);
      tmp = buff;
      if (tmp.find(":") < tmp.size())
	{
  	  this->subFrontSpace(tmp);
	  name = tmp.substr(0, tmp.find(":"));
	  tmp = tmp.substr(tmp.find(":") + 1);
	  this->subFrontSpace(tmp);

	  this->strJump(tmp);

	  packets.receive = StringToInt(tmp.substr(0, tmp.find(" ")));
	  this->subFrontSpace(tmp);

	  for (int i = 0; i < 8; ++i)
	    this->strJump(tmp);

	  packets.transmit = StringToInt(tmp.substr(0, tmp.find(" ")));
	  this->_packets[name] = packets;
	}
    }
}

void Mod::Network::subFrontSpace(std::string & str)
{
  PRINT_TRACE();
  while (str.size() > 0 && str[0] == ' ')
    str = str.substr(1);
}

void Mod::Network::strJump(std::string & str)
{
  PRINT_TRACE();
  str = str.substr(str.find(" "));
  this->subFrontSpace(str);
}

std::map<std::string, netPackets> const& Mod::Network::getPackets() const
{
  return this->_packets;
}
