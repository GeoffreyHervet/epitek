//
// header for norme in /
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.eu>
//
// Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
// Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
//

#include	"Cagette.h"

static void delete_rec(FruitNode *f)
{
  if (f->next != NULL)
    delete_rec(f->next);
 // delete f->value;
  delete f;
}

Cagette::~Cagette()
{
  if (this->_list != NULL)
    delete_rec(this->_list);
}

int		Cagette::nbFruits()
{
  int		len = 0;
  FruitNode	*item = this->_list;

  while (item != NULL)
  {
    len++;
    item = item->next;
  }
  return len;
}

bool		Cagette::inCagette(const Fruit *f) const
{
  FruitNode	*item = this->_list;

  while (item != NULL)
  {
    if (item->value == f)
      return true;
    item = item->next;
  }
  return false;
}

bool		Cagette::putFruit(Fruit *f)
{
  FruitNode	*item = new FruitNode(f, this->_list);

  if (item == NULL || f == NULL)
    return false;
  if (this->nbFruits() >= this->_size || this->inCagette(f))
    return false;
  this->_list = item;
  return true;
}

Fruit		*Cagette::pickFruit()
{
  Fruit		*ret = NULL;
  FruitNode	*after = NULL;

  if (this->_list == NULL)
    return NULL;
  ret = this->_list->value;
  after = this->_list->next;
  delete this->_list;
  this->_list = after;
  return ret;
}

Cagette		&Cagette::operator=(const Cagette &c)
{
  if (this != &c)
  {
    this->_list = NULL;
    this->_size = c.getSize();
  }
  return *this;
}
