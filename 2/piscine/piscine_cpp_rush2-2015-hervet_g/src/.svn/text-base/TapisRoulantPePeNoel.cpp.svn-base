#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Trace.hh"

#include "TapisRoulantPePeNoel.hh"
#include "Emballage.hh"
#include "PapierCadeau.hh"
#include "Carton.hh"

TapisRoulantPePeNoel::TapisRoulantPePeNoel::TapisRoulantPePeNoel()
{
  TRACE_EXEC();
  this->objet_ = NULL;
}

TapisRoulantPePeNoel::TapisRoulantPePeNoel(TapisRoulantPePeNoel const& src)
{
  TRACE_EXEC();
  this->objet_ = src.objet_;
}

TapisRoulantPePeNoel const& TapisRoulantPePeNoel::operator=(TapisRoulantPePeNoel const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    this->objet_ = src.objet_;
  }
  return (src);
}

TapisRoulantPePeNoel::~TapisRoulantPePeNoel()
{
  TRACE_EXEC();
}

bool TapisRoulantPePeNoel::poser(Objet * obj)
{
  TRACE_EXEC();
  if (this->objet_)
  {
    std::cerr << "Erreur : il y a deja un objet sur le tapis roulant" << std::endl;
    return false;
  }
  this->objet_ = obj;
  return true;
}

Objet* TapisRoulantPePeNoel::prendre()
{
  TRACE_EXEC();
  Objet *tmp = this->objet_;

  if (tmp == NULL)
  {
    std::cerr << "Erreur : rien a prendre sur le tapis roulant" << std::endl;
    return (NULL);
  }
  this->objet_ = NULL;
  return (tmp);
}

Objet* TapisRoulantPePeNoel::Regarder() const
{
  TRACE_EXEC();
  return (this->objet_);
}

Emballage* TapisRoulantPePeNoel::IN()
{
  TRACE_EXEC();
  if (rand() % 2)
    return (new PapierCadeau());
  return (new Carton());
}

bool TapisRoulantPePeNoel::OUT()
{
  TRACE_EXEC();
  if (this->objet_)
  {
    std::cout << "Objet pret a la livraison PePe !" << std::endl;
    // delete this->objet_;
    this->objet_ = NULL;
    return (true);
  }
  std::cerr << "Erreur : aucun emballage a envoyer au pere noel" << std::endl;
  return (false);
}

ITapisRoulant *creerTapisRoulant()
{
  TRACE_EXEC();
  return (new TapisRoulantPePeNoel());
}
