#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Trace.hh"

#include "TableAleat.hh"
#include "Nounours.hh"
#include "PetitPoney.hh"
#include "Carton.hh"
#include "PapierCadeau.hh"

TableAleat::TableAleat(unsigned int maxObj)
{
  TRACE_EXEC();
  this->maxObj_ = maxObj;
  this->objets_ = new Objet*[this->maxObj_];
  for (unsigned int i = 0; i < this->maxObj_; ++i)
    {
      this->objets_[i] = NULL;
    }
  this->nbrObjets_ = 0;
  srand(time(NULL));
  this->fillRandom();
}

TableAleat::TableAleat(TableAleat const& src)
{
  TRACE_EXEC();
  this->objets_ = new Objet*[this->maxObj_];
  for (unsigned int i = 0; i < this->maxObj_; i++)
    this->objets_[i] = src.objets_[i];
  this->nbrObjets_ = src.nbrObjets_;
  this->maxObj_ = src.maxObj_;
  srand(time(NULL));
}

TableAleat const& TableAleat::operator=(TableAleat const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    if (this->objets_ != NULL)
      delete [] this->objets_;
    this->objets_ = new Objet*[this->maxObj_];
    for (unsigned int i = 0; i < this->maxObj_; i++)
      this->objets_[i] = src.objets_[i];
    this->nbrObjets_ = src.nbrObjets_;
    this->maxObj_ = src.maxObj_;
  }
  return (src);
}

TableAleat::~TableAleat()
{
  TRACE_EXEC();
  delete [] this->objets_;
}

bool TableAleat::poser(Objet * obj)
{
  unsigned int i;

  TRACE_EXEC();
  if (this->nbrObjets_ >= this->maxObj_)
  {
    std::cout << "Putain d'elfe t'as encore casse une table !" << std::endl;
    return false;
  }
  for (i = 0; i < this->maxObj_ && this->objets_[i] != NULL; ++i);

  this->objets_[i] = obj;
  this->nbrObjets_++;
  std::cout << "Un elfe pose un objet sur la table." << std::endl;
  return true;
}

Objet* TableAleat::prendre(int i)
{
  TRACE_EXEC();
  Objet* tmp;

  if (i >= (int)this->maxObj_)
  {
    std::cerr << "Erreur : objet sur la table introuvable (" << i << ")" << std::endl;
    return (NULL);
  }
  tmp = this->objets_[i];
  if (tmp == NULL)
  {
    std::cerr << "Erreur : objet NULL" << std::endl;
    return (NULL);
  }
  this->nbrObjets_--;
  this->objets_[i] = NULL;
  return (tmp);
}

Objet* TableAleat::prendre()
{
  TRACE_EXEC();
  unsigned int i;

  for (i = 0; i < this->maxObj_; ++i)
    if (this->objets_[i] == NULL)
      break;
  if (i < this->maxObj_)
    return (this->prendre(i));
  return (NULL);
}

Objet* TableAleat::prendre(Objet* obj)
{
  TRACE_EXEC();
  for (unsigned int i = 0; i < this->maxObj_; i++)
    if (this->objets_[i] == obj)
	return (this->prendre(i));
  std::cerr << "Erreur : objet sur la table introuvable (" << obj << ")" << std::endl;
  return (NULL);
}

Objet** TableAleat::Regarder()
{
  TRACE_EXEC();
  return (this->objets_);
}

void TableAleat::fillRandom()
{
  for (unsigned int i = 0; i < this->maxObj_; i++)
  {
    switch (rand() % 4)
    {
      case 0 :
        this->objets_[i] = new Nounours("random nounourse"); break;
      case 1 :
        this->objets_[i] = new PetitPoney("mon petit ponay"); break;
      case 2:
        this->objets_[i] = new Carton; break;
      case 3 :
        this->objets_[i] = new PapierCadeau; break;
    }
  }
  this->nbrObjets_ = this->maxObj_;
}
