#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Trace.hh"

#include "TapisRoulantAleat.hh"
#include "Emballage.hh"
#include "PapierCadeau.hh"
#include "Carton.hh"
#include "serialize.hh"

TapisRoulantAleat::TapisRoulantAleat()
{
  TRACE_EXEC();
  this->objet_ = NULL;
}

TapisRoulantAleat::TapisRoulantAleat(TapisRoulantAleat const& src)
{
  TRACE_EXEC();
  this->objet_ = src.objet_;
}

TapisRoulantAleat const& TapisRoulantAleat::operator=(TapisRoulantAleat const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    this->objet_ = src.objet_;
  }
  return (src);
}

TapisRoulantAleat::~TapisRoulantAleat()
{
  TRACE_EXEC();
}

bool TapisRoulantAleat::poser(Objet * obj)
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

Objet* TapisRoulantAleat::prendre()
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

Objet* TapisRoulantAleat::Regarder() const
{
  TRACE_EXEC();
  return (this->objet_);
}

Emballage* TapisRoulantAleat::IN()
{
  TRACE_EXEC();
  if (rand() % 2)
    return (new PapierCadeau());
  return (new Carton());
}

bool TapisRoulantAleat::OUT()
{
  TRACE_EXEC();

  if (this->objet_)
  {
    std::cout << "Objet pret a la livraison PePe !" << std::endl;
    serializeGift(this->objet_);
    this->objet_ = NULL;
    return (true);
  }
  std::cerr << "Erreur : aucun emballage a envoyer au pere noel" << std::endl;
  return (false);
}
