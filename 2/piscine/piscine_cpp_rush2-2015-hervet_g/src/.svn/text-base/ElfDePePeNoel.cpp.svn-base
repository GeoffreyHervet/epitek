#include <iostream>
#include <string>

#include "Trace.hh"

#include "Objet.hh"
#include "Emballage.hh"
#include "ElfDePePeNoel.hh"

ElfDePePeNoel::ElfDePePeNoel()
  : objet_(NULL)
{
  TRACE_EXEC();
  this->table_ = NULL;
  this->tapisRoulant_ = NULL;
  this->emballage_ = NULL;
  this->papierCadeau_ = NULL;
  this->carton_ = NULL;
  this->jouet_ = NULL;
}

ElfDePePeNoel::ElfDePePeNoel(ElfDePePeNoel const& other)
  : objet_(other.objet_)
{
  TRACE_EXEC();
  this->table_ = other.table_;
  this->tapisRoulant_ = other.tapisRoulant_;
  this->emballage_ = other.emballage_;
  this->papierCadeau_ = other.papierCadeau_;
  this->carton_ = other.carton_;
  this->jouet_ = other.jouet_;
}

ElfDePePeNoel const& ElfDePePeNoel::operator=(ElfDePePeNoel const& other)
{
  TRACE_EXEC();
  if (this != &other)
    {
      this->table_ = other.table_;
      this->tapisRoulant_ = other.tapisRoulant_;
      this->emballage_ = other.emballage_;
      this->objet_ = other.objet_;
      this->papierCadeau_ = other.papierCadeau_;
      this->carton_ = other.carton_;
      this->jouet_ = other.jouet_;
    }
  return (other);
}

ElfDePePeNoel::~ElfDePePeNoel()
{
  TRACE_EXEC();
}

Emballage* ElfDePePeNoel::getEmballage()
{
  TRACE_EXEC();
  std::cout << "siffle en travaillant" << std::endl;
  return (this->emballage_ = this->tapisRoulant_->IN());
}

void ElfDePePeNoel::envoyerObjetAPePeNoel()
{
  TRACE_EXEC();
  this->tapisRoulant_->OUT();
}

void ElfDePePeNoel::setTable(ITable* table)
{
  TRACE_EXEC();
  this->table_ = table;
}

void ElfDePePeNoel::setTapisRoulant(ITapisRoulant* tr)
{
  TRACE_EXEC();
  this->tapisRoulant_ = tr;
}

bool ElfDePePeNoel::checkPapierCadeau()
{
  TRACE_EXEC();
  Objet** obj;
  unsigned int i;

  if (this->emballage_ && this->emballage_->getType() == PAPIER_CADEAU)
    {
      this->papierCadeau_ = static_cast<PapierCadeau*>(this->emballage_);
      this->emballage_ = NULL;
      return true;
    }
  if (this->tapisRoulant_->Regarder() && this->tapisRoulant_->Regarder()->getType() == PAPIER_CADEAU)
    {
      this->papierCadeau_ = static_cast<PapierCadeau*>(this->tapisRoulant_->prendre());
      return true;
    }

  obj = this->table_->Regarder();
  for (i = 0; i < this->table_->maxObj_; i++)
    if (obj[i] != NULL && obj[i]->getType() == PAPIER_CADEAU)
      {
	this->papierCadeau_ = static_cast<PapierCadeau*>(this->table_->prendre(i));
	return true;
      }
  return false;
}

bool ElfDePePeNoel::checkJouet()
{
  TRACE_EXEC();
  Objet** obj;
  unsigned int i;

  if (this->jouet_)
    return true;

  if (this->tapisRoulant_->Regarder() && this->tapisRoulant_->Regarder()->isJouet() == true)
    {
      this->jouet_ = static_cast<Jouet*>(this->tapisRoulant_->prendre());
      return true;
    }

  obj = this->table_->Regarder();
  for (i = 0; i < this->table_->maxObj_; i++)
    if (obj[i] != NULL && obj[i]->isJouet())
      {
	this->jouet_ = static_cast<Jouet*>(this->table_->prendre(i));
	return true;
      }
  return false;
}

bool ElfDePePeNoel::checkCarton()
{
  TRACE_EXEC();
  Objet** obj;
  unsigned int i;

  if (this->emballage_ && this->emballage_->getType() == CARTON)
    {
      this->carton_ = static_cast<Carton*>(this->emballage_);
      this->emballage_ = NULL;
      return true;
    }
  if (this->tapisRoulant_->Regarder() && this->tapisRoulant_->Regarder()->getType() == CARTON)
    {
      this->carton_ = static_cast<Carton*>(this->tapisRoulant_->prendre());
      return true;
    }

  obj = this->table_->Regarder();
  for (i = 0; i < this->table_->maxObj_; i++)
    if (obj[i] != NULL && obj[i]->getType() == CARTON)
      {
	this->carton_ = static_cast<Carton*>(this->table_->prendre(i));
	return true;
      }
  return false;
}

bool ElfDePePeNoel::findCartonAndPapier()
{
  TRACE_EXEC();
  if (this->emballage_ == NULL)
    this->getEmballage();

  while ((this->carton_ == NULL || this->papierCadeau_ == NULL))
    {
      if (this->carton_ == NULL && this->emballage_ && this->emballage_->getType() == CARTON)
	{
	  this->carton_ = static_cast<Carton*>(this->emballage_);
	  this->emballage_ = NULL;
	}
      else if (this->papierCadeau_ == NULL && this->emballage_ && this->emballage_->getType() == PAPIER_CADEAU)
	{
	  this->papierCadeau_ = static_cast<PapierCadeau*>(this->emballage_);
	  this->emballage_ = NULL;
	}
      if (this->emballage_ != NULL)
	{
	  if (this->table_->poser(this->emballage_) == false)
	    {
	      this->emballage_ = NULL;
	      break;
	    }
	}
      this->getEmballage();
    }
return (this->carton_ != NULL && this->papierCadeau_ != NULL);
}

bool ElfDePePeNoel::emballerCadeau()
{
  TRACE_EXEC();
  if ((this->checkPapierCadeau() &&
       this->checkCarton() &&
       this->checkJouet()) ||
      (this->jouet_ != NULL && this->findCartonAndPapier() == true))
    {
      this->papierCadeau_->emballeMoiCa(dynamic_cast<Objet*>(this->carton_));
      this->carton_->emballeMoiCa(dynamic_cast<Objet*>(this->jouet_));

      this->tapisRoulant_->poser(this->papierCadeau_);
      this->tapisRoulant_->OUT();

      this->carton_ = NULL;
      this->jouet_ = NULL;
      this->papierCadeau_ = NULL;
      return true;
    }
  return false;
}

void ElfDePePeNoel::emballerTousLesCadeaux()
{
  while (this->emballerCadeau() == true);
  std::cout << "pepe ya un schmolle dans le bignou" << std::endl;
}
