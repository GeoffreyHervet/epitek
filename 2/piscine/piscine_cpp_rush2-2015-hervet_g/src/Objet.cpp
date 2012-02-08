#include <cstddef>
#include <iostream>

#include "Trace.hh"

#include "Objet.hh"
#include "PetitPoney.hh"
#include "Nounours.hh"
#include "PapierCadeau.hh"
#include "Nounours.hh"
#include "Carton.hh"

Objet::Objet() : type_(OBJET)
{
  TRACE_EXEC();
}

Objet::Objet(Objet const& src) : type_(OBJET)
{
  TRACE_EXEC();
  (void)src;
}

Objet const& Objet::operator=(Objet const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
  }
  return (src);
}

Objet::~Objet()
{
  TRACE_EXEC();
}

type Objet::getType() const
{
  TRACE_EXEC();
  return this->type_;
}

bool Objet::isJouet()
{
  TRACE_EXEC();
  return (this->type_ == JOUET || this->type_ == NOUNOURS || this->type_ == PETIT_PONEY);
}

bool Objet::isEmballage()
{
  TRACE_EXEC();
  return (this->type_ == EMBALLAGE || this->type_ == PAPIER_CADEAU || this->type_ == CARTON);
}

Objet** MesTestUnitaires()
{
  TRACE_EXEC();
  Objet** ret = new Objet*[2];

  ret[0] = new PetitPoney("poney gay");
  ret[1] = new Nounours("bisounours");
  return (ret);
}

Objet* MesTestUnitaires(Objet** src)
{
  TRACE_EXEC();
  PapierCadeau* ret = static_cast<PapierCadeau*>(src[2]);
  Carton* b = static_cast<Carton*>(src[1]);
  Nounours* c = static_cast<Nounours*>(src[0]);
  int i;

  for (i = 0; src[i] != NULL && i < 3; ++i);
  if (i < 2)
  {
    std::cerr << "Erreur : pas assez de parametres" << std::endl;
    return (NULL);
  }
  ret->setObjet(b);
  b->setObjet(c);
  return (ret);
}
