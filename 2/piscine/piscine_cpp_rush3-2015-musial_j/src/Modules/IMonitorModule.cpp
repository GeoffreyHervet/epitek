#include "Trace.h"

#include "IMonitorModule.h"

IMonitorModule::~IMonitorModule()
{
  PRINT_TRACE();
}
