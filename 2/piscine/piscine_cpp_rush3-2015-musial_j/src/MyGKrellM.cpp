#include <iostream>
#include <string>

#include "Trace.h"

#include "MyGKrellM.h"
#include "ModulesController.h"
#include "IMonitorDisplay.h"
#include "NCursesDisplay.h"
#include "QtDisplay.h"

  MyGKrellM::MyGKrellM (int argc, char * argv[])
: _modulesToEnable(MOD_EMPTY), _display(NULL), _displayType(DISP_NONE)
{
  PRINT_TRACE();

  if (this->parseOptions(argc, argv))
    return;
  if (this->_modulesToEnable == MOD_EMPTY)
  {
    std::cerr << "Error: please enable at least one module." << std::endl;
    std::cerr << "Try `" << argv[0] << " --help` for more informations." << std::endl;
    return;
  }
  switch (this->_displayType)
  {
    case DISP_DEBUG:
      break;
    case DISP_CONSOLE:
      this->_display = new NCursesDisplay(); break;
    case DISP_GRAPHIC:
      this->_display = new QtDisplay(argc, argv); break;
    case DISP_NONE:
    default:
      std::cerr << "Error: please chose a display manager." << std::endl;
      std::cerr << "Try `" << argv[0] << " --help` for more informations." << std::endl;
      return;
  }
  this->_modulesController.setModules(this->_modulesToEnable);
  this->_modulesController.run();
  if (this->_display != NULL)
  {
    this->_display->setModulesController(&this->_modulesController);
    this->_display->run();
  }
}

MyGKrellM::~MyGKrellM()
{
  PRINT_TRACE();
}

int MyGKrellM::parseOptions(int argc, char* argv[]) // not const for QT
{
  PRINT_TRACE();
  //if no options
  if (argc == 1)
  {
    MyGKrellM::usage(std::string(argv[0]));
    return (1);
  }

  //looking for help first
  for (int i = 1; i < argc; ++i)
    if (std::string(argv[i]) == "-help" || std::string(argv[i]) == "--help")
    {
      MyGKrellM::usage(std::string(argv[0]));
      return (1);
    }

  //parsing options
  for (int i = 1; i < argc; ++i)
    //display
    if (std::string(argv[i]) == "--debug")
    {
      if (this->_displayType != DISP_NONE)
        std::cerr << "Warning: display manager already defined, ignore '--debug'." << std::endl;
      else
        this->_displayType = DISP_DEBUG;
    }
    else if (std::string(argv[i]) == "--console")
    {
      if (this->_displayType != DISP_NONE)
        std::cerr << "Warning: display manager already defined, ignore '--console'." << std::endl;
      else
        this->_displayType = DISP_CONSOLE;
    }
    else if (std::string(argv[i]) == "--gui")
    {
      if (this->_displayType != DISP_NONE)
        std::cerr << "Warning: display manager already defined, ignore '--gui'." << std::endl;
      else
        this->_displayType = DISP_GRAPHIC;
    }
    //modules
    else if (std::string(argv[i]) == "--cpu")
      this->_modulesToEnable |= MOD_CPU;
    else if (std::string(argv[i]) == "--ram")
      this->_modulesToEnable |= MOD_RAM;
    else if (std::string(argv[i]) == "--computer")
      this->_modulesToEnable |= MOD_COMPUTER;
    else if (std::string(argv[i]) == "--os")
      this->_modulesToEnable |= MOD_OS;
    else if (std::string(argv[i]) == "--timeinfo")
      this->_modulesToEnable |= MOD_TIMEINFO;
    else if (std::string(argv[i]) == "--network")
      this->_modulesToEnable |= MOD_NETWORK;
    else if (std::string(argv[i]) == "--swap")
      this->_modulesToEnable |= MOD_SWAP;
    else if (std::string(argv[i]) == "--load")
      this->_modulesToEnable |= MOD_LOADAVG;
    else if (std::string(argv[i]) == "--uptime")
      this->_modulesToEnable |= MOD_UPTIME;
    else if (std::string(argv[i]) == "--all")
      this->_modulesToEnable |= MOD_ALL;
    else
    {
      std::cerr << "Error: unrecognized option '" << argv[i] << "'" << std::endl;
      std::cerr << "Try `" << argv[0] << " --help` for more informations." << std::endl;
      return (1);
    }

  return (0);
}

void MyGKrellM::usage(std::string const& progName)
{
  PRINT_TRACE();
  std::cout << "Usage: " << progName << " [OPTION]" << std::endl;
  std::cout << "Show basics informations about your system (in the console by default)." << std::endl;

  std::cout << std::endl << "  Display Managers:" << std::endl;
  std::cout << "  --console, terminal display" << std::endl;
  std::cout << "  --gui, graphic display" << std::endl;

  std::cout << std::endl << "  Modules:" << std::endl;
  std::cout << "  --cpu, display informations on your CPU" << std::endl;
  std::cout << "  --ram, display informations on your RAM" << std::endl;
  std::cout << "  --computer, display informations on your Computer" << std::endl;
  std::cout << "  --os, display informations on your OS" << std::endl;
  std::cout << "  --timeinfo, display time data (uptime, data)" << std::endl;
  std::cout << "  --network, display network informations" << std::endl;
  std::cout << "  --swap, display SWAP informations" << std::endl;
  std::cout << "  --load, display load average informations" << std::endl;
  std::cout << "  --uptime, display uptime" << std::endl;
  std::cout << "    --all, enable all the module" << std::endl;
}
