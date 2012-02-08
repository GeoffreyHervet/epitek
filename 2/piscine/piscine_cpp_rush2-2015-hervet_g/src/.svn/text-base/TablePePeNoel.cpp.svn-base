#include <iostream>
#include <string>

#include "Trace.hh"

#include "TablePePeNoel.hh"

TablePePeNoel::TablePePeNoel()
{
  TRACE_EXEC();
  for (int i = 0; i < 10; ++i)
    this->objets_[i] = NULL;
  this->nbrObjets_ = 0;
  this->maxObj_ = 10;
}

TablePePeNoel::TablePePeNoel(TablePePeNoel const& src)
{
  TRACE_EXEC();
  for (int i = 0; i < 10; i++)
    this->objets_[i] = src.objets_[i];
  this->nbrObjets_ = src.nbrObjets_;
  this->maxObj_ = 10;
}

TablePePeNoel const& TablePePeNoel::operator=(TablePePeNoel const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    for (int i = 0; i < 10; i++)
      this->objets_[i] = src.objets_[i];
    this->nbrObjets_ = src.nbrObjets_;
    this->maxObj_ = 10;
  }
  return (src);
}

TablePePeNoel::~TablePePeNoel()
{
  TRACE_EXEC();
}

bool TablePePeNoel::poser(Objet * obj)
{
  int i;

  TRACE_EXEC();
  if (this->nbrObjets_ >= 10)
  {
    std::cout << "Putain d'elfe t'as encore casse une table !" << std::endl;
    return false;
  }
  for (i = 0; i < 10 && this->objets_[i] != NULL; ++i);

  this->objets_[i] = obj;
  this->nbrObjets_++;
  std::cout << "Un elfe pose un objet sur la table." << std::endl;
  return true;
}

Objet* TablePePeNoel::prendre(int i)
{
  TRACE_EXEC();
  Objet* tmp;

  if (i >= 10)
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

Objet* TablePePeNoel::prendre()
{
  TRACE_EXEC();
  int i;

  for (i = 0; i < 10; ++i)
    if (this->objets_[i] == NULL)
      break;
  if (i < 10)
    return (this->prendre(i));
  return (NULL);
}

Objet* TablePePeNoel::prendre(Objet* obj)
{
  TRACE_EXEC();
  for (int i = 0; i < 10; i++)
    if (this->objets_[i] == obj)
	return (this->prendre(i));
  std::cerr << "Erreur : objet sur la table introuvable (" << obj << ")" << std::endl;
  return (NULL);
}

Objet** TablePePeNoel::Regarder()
{
  TRACE_EXEC();
  return (this->objets_);
}

ITable *creerTable()
{
  TRACE_EXEC();
  return new TablePePeNoel;
}
