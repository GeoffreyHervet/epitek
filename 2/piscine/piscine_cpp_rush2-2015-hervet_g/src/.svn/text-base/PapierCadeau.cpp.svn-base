#include "Objet.hh"
#include "PapierCadeau.hh"

#include "Trace.hh"

PapierCadeau::PapierCadeau() : Emballage()
{
  TRACE_EXEC();
  this->type_ = PAPIER_CADEAU;
}

PapierCadeau::PapierCadeau(PapierCadeau const& src) : Emballage()
{
  TRACE_EXEC();
  (void)src;
  this->type_ = PAPIER_CADEAU;
}

PapierCadeau const& PapierCadeau::operator=(PapierCadeau const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
  }
  return (src);
}

PapierCadeau::~PapierCadeau()
{
  TRACE_EXEC();
}

