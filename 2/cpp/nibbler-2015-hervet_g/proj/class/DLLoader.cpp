#include "DLLoader.h"

std::vector<void *>	DLLoader::HANDLERS;

void		*DLLoader::getInstance(const char *file, const char *entryPoint, const int flag)
{
  void	*handler;
  char	*error;
  void	*ctor;

  if (NULL == (handler = dlopen(file, flag)))
    throw Error(dlerror());

  dlerror();
  ctor = dlsym(handler, entryPoint);

  if (NULL != (error = dlerror()))
    throw Error(error);
  DLLoader::HANDLERS.push_back(handler);
  return ctor;
}

void			DLLoader::closeHandlers()
{
  for (std::vector<void *>::iterator it = DLLoader::HANDLERS.begin(); it != DLLoader::HANDLERS.end(); )
  {
    dlclose(*it);
    it = DLLoader::HANDLERS.erase(it);
  }
}
