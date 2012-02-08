//
// header for norme in /
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.eu>
//
// Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
// Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
//

#include	"droid.hh"

Droid::Droid(const std::string &id)
  : _id(id),
    _status(new std::string("Standing by")),
    _attack(25),
    _toughness(15),
    _energy(50),
    _battleData(new DroidMemory)
{
  std::cout << "Droid '" << this->getId() << "' Activated" << std::endl;
}

Droid::Droid(const Droid &item)
  : _id(item.getId()),
    _status(new std::string(*(item.getStatus()))),
    _attack(item.getAttack()),
    _toughness(item.getToughness()),
    _energy(item.getEnergy()),
    _battleData(new DroidMemory)
{
  std::cout << "Droid '" << this->getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  delete this->_status;
  std::cout << "Droid '" << this->getId() << "' Destroyed" << std::endl;
}

/* =============================================================== */

Droid &		Droid::operator=(const Droid &item)
{
  if (&item != this)
  {
    this->_id = item.getId();
    this->_status = new std::string(*(item.getStatus()));
    this->_energy = item.getEnergy();
  }
  return *this;
}

bool		Droid::operator==(const Droid &item) const
{
  return (*(this->getStatus()) == *(item.getStatus()));
}


bool		Droid::operator!=(const Droid &item) const
{
  return (!((*this) == item));
}

Droid &		Droid::operator<<(size_t &nbr)
{
  size_t	tmp = nbr;
  if (this->_energy == 100)
    return *this;
  if (this->_energy + nbr > 100)
    tmp = 100 - this->_energy;
  this->_energy += tmp;
  nbr -= tmp;
  return *this;
}

std::ostream&	operator<<(std::ostream &stream, const Droid &item) //, const Droid &);
{
  stream << "Droid '" << item.getId()
         << "', " << *(item.getStatus())
         << ", " << item.getEnergy();
  return stream;
}

/* =============================================================== */

std::string	Droid::getId(void) const
{
  return this->_id;
}

std::string *	Droid::getStatus(void) const
{
  return this->_status;
}

size_t		Droid::getEnergy(void) const
{
  return this->_energy;
}

size_t		Droid::getAttack(void) const
{
  return this->_attack;
}

size_t		Droid::getToughness(void) const
{
  return this->_toughness;
}

DroidMemory *	Droid::getBattleData(void) const
{
  return this->_battleData;
}

/* =============================================================== */

void		Droid::setStatus(const std::string *st)
{
  if (this->_status)
    delete (this->_status);
  this->_status = new std::string(*st);
}

void		Droid::setId(const std::string &id)
{
  this->_id = id;
}

void		Droid::setEnergy(const size_t energy)
{
  if (energy > 100)
    this->_energy = 100;
  else
    this->_energy = energy;
}
void		Droid::setBattleData(DroidMemory *mem)
{
  delete this->_battleData;
  this->_battleData = mem;
}
