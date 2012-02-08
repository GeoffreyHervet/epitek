#include <iostream>

#include "Trace.hh"

#include "Objet.hh"
#include "Carton.hh"

Carton::Carton() : Emballage(), isOpen_(true)
{
  TRACE_EXEC();
  this->type_ = CARTON;
}

Carton::Carton(Carton const& src) : Emballage(), isOpen_(src.isOpen_)
{
  TRACE_EXEC();
  this->type_ = CARTON;
}

Carton const& Carton::operator=(Carton const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    this->isOpen_ = src.isOpen_;
  }
  return (src);
}

Carton::~Carton()
{
  TRACE_EXEC();
}

bool Carton::emballeMoiCa(Objet* objet)
{
  TRACE_EXEC();
  if (!this->isOpen_)
  {
    std::cerr << "Erreur : impossible d'emballer dans un carton ferme" << std::endl;
    return (false);
  }
  return (this->Emballage::emballeMoiCa(objet));
}

Objet* Carton::ouvreMoi()
{
  TRACE_EXEC();
  if (!this->isOpen_)
    std::cerr << "Attention : impossible d'ouvrir le carton deja ouvert" << std::endl;
  this->isOpen_ = true;
  return (this->Emballage::ouvreMoi());
}

bool Carton::fermeMoi()
{
  TRACE_EXEC();
  if (this->isOpen_ == false)
  {
    std::cerr << "Erreur : impossible de fermer le carton (deja ferme)" << std::endl;
    return (false);
  }
  this->isOpen_ = false;
  return (true);
}
