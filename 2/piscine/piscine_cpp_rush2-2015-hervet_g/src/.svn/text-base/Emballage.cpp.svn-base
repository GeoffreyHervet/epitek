#include <iostream>

#include "Trace.hh"

#include "Objet.hh"
#include "Emballage.hh"

Emballage::Emballage() : objet_(NULL)
{
  TRACE_EXEC();
  this->type_ = EMBALLAGE;
}

Emballage::Emballage(Emballage const& src) : Objet(), objet_(src.objet_)
{
  TRACE_EXEC();
  this->type_ = EMBALLAGE;
}

Emballage const& Emballage::operator=(Emballage const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    if (this->objet_)
      delete this->objet_;
    this->objet_ = src.objet_;
  }
  return (src);
}

Emballage::~Emballage()
{
  TRACE_EXEC();
}

void Emballage::setObjet(Objet* src)
{
  TRACE_EXEC();
  this->objet_ = src;
}

bool Emballage::emballeMoiCa(Objet* objet, bool verbose)
{
  TRACE_EXEC();
  if (objet == NULL)
  {
    std::cerr << "Erreur : pointeur sur objet NULL" << std::endl;
    return (false);
  }
  if (this->objet_ != NULL)
  {
    std::cerr << "Erreur : objet deja present" << std::endl;
    return (false);
  }
  this->objet_ = objet;
  if (verbose)
    std::cout << "tuuuut tuuut tuut" << std::endl;
  return (true);
}

Objet* Emballage::ouvreMoi()
{
  TRACE_EXEC();
  return (this->objet_);
}

Objet* Emballage::getObjet() const
{
  TRACE_EXEC();
  return (this->objet_);
}
