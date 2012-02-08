#include <cstddef>

#include "Trace.h"

#include "ModulesController.h"

  ModulesController::ModulesController()
: _modulesEnabled(0)
{
  PRINT_TRACE();
}

ModulesController::~ModulesController()
{
  PRINT_TRACE();
  this->killAll();
}

void ModulesController::setModules(unsigned int var)
{
  PRINT_TRACE();

  this->_modulesEnabled = var;
}

void ModulesController::run()
{
  PRINT_TRACE();
  static bool first = true;

  if (!first)
    return;
  first = false;
  this->launch(this->_modulesEnabled);
}

void ModulesController::launch(unsigned int flag)
{
  PRINT_TRACE();
  if (IS_MOD_ENAB(flag, MOD_CPU) && !this->isEnabled(MOD_CPU))
    this->_modulesList.push_back(&Mod::CPU::getInstance());
  if (IS_MOD_ENAB(flag, MOD_RAM) && !this->isEnabled(MOD_RAM))
    this->_modulesList.push_back(&Mod::RAM::getInstance());
  if (IS_MOD_ENAB(flag, MOD_COMPUTER) && !this->isEnabled(MOD_COMPUTER))
    this->_modulesList.push_back(&Mod::Computer::getInstance());
  if (IS_MOD_ENAB(flag, MOD_OS) && !this->isEnabled(MOD_OS))
    this->_modulesList.push_back(&Mod::OS::getInstance());
  if (IS_MOD_ENAB(flag, MOD_TIMEINFO) && !this->isEnabled(MOD_TIMEINFO))
    this->_modulesList.push_back(&Mod::TimeInfo::getInstance());
  if (IS_MOD_ENAB(flag, MOD_NETWORK) && !this->isEnabled(MOD_NETWORK))
    this->_modulesList.push_back(&Mod::Network::getInstance());
  if (IS_MOD_ENAB(flag, MOD_SWAP) && !this->isEnabled(MOD_SWAP))
    this->_modulesList.push_back(&Mod::Swap::getInstance());
  if (IS_MOD_ENAB(flag, MOD_LOADAVG) && !this->isEnabled(MOD_LOADAVG))
    this->_modulesList.push_back(&Mod::LoadAvg::getInstance());
  if (IS_MOD_ENAB(flag, MOD_UPTIME) && !this->isEnabled(MOD_UPTIME))
    this->_modulesList.push_back(&Mod::Uptime::getInstance());
}

void ModulesController::launchAll()
{
  PRINT_TRACE();
  this->launch(MOD_ALL);
}

void ModulesController::kill(unsigned int flag)
{
  PRINT_TRACE();
  IMonitorModule* mod;

  if ((mod = this->getModule(flag)) == NULL)
    return;
  delete mod;
}

void ModulesController::killAll()
{
  PRINT_TRACE();
  for (std::vector<IMonitorModule*>::const_iterator i = this->_modulesList.begin();
      i != this->_modulesList.end(); ++i)
    delete (*i);
  this->_modulesList.clear();
}

void ModulesController::update(unsigned int flag)
{
  PRINT_TRACE();
  IMonitorModule* mod;

  if ((mod = this->getModule(flag)) == NULL)
    return;
  mod->updateInfo();
}

void ModulesController::updateAll()
{
  PRINT_TRACE();
  for (std::vector<IMonitorModule*>::const_iterator i = this->_modulesList.begin();
      i != this->_modulesList.end(); ++i)
    (*i)->updateInfo();
}

bool ModulesController::isEnabled(unsigned int flag) const
{
  PRINT_TRACE();
  return (this->getModule(flag) != NULL);
}

std::vector<IMonitorModule*> const& ModulesController::getList() const
{
  PRINT_TRACE();
  return (this->_modulesList);
}

unsigned int ModulesController::countActivated() const
{
  PRINT_TRACE();
  return (this->_modulesList.size());
}

IMonitorModule* ModulesController::getModule(unsigned int flag) const
{
  PRINT_TRACE();
  IMonitorModule* ret = NULL;

  if (!this->_modulesList.empty())
    for (std::vector<IMonitorModule*>::const_iterator i = this->_modulesList.begin();
        i != this->_modulesList.end(); ++i)
    {
      if (IS_MOD_ENAB(flag, MOD_CPU) && (ret = dynamic_cast<Mod::CPU*>(*i)) != NULL)
        break;
      if (IS_MOD_ENAB(flag, MOD_RAM) && (ret = dynamic_cast<Mod::RAM*>(*i)) != NULL)
        break;
      if (IS_MOD_ENAB(flag, MOD_COMPUTER) && (ret = dynamic_cast<Mod::Computer*>(*i)) != NULL)
        break;
      if (IS_MOD_ENAB(flag, MOD_OS) && (ret = dynamic_cast<Mod::OS*>(*i)) != NULL)
        break;
      if (IS_MOD_ENAB(flag, MOD_TIMEINFO) && (ret = dynamic_cast<Mod::TimeInfo*>(*i)) != NULL)
        break;
      if (IS_MOD_ENAB(flag, MOD_NETWORK) && (ret = dynamic_cast<Mod::Network*>(*i)) != NULL)
        break;
      //if (IS_MOD_ENAB(flag, MOD_HARDDRIVE) && (ret = dynamic_cast<Mod::HardDrive*>(*i)) != NULL)
      //  break;
      if (IS_MOD_ENAB(flag, MOD_SWAP) && (ret = dynamic_cast<Mod::Swap*>(*i)) != NULL)
        break;
      if (IS_MOD_ENAB(flag, MOD_LOADAVG) && (ret = dynamic_cast<Mod::LoadAvg*>(*i)) != NULL)
        break;
      if (IS_MOD_ENAB(flag, MOD_UPTIME) && (ret = dynamic_cast<Mod::Uptime*>(*i)) != NULL)
        break;
    }
  return (ret);
}
