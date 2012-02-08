//
// header for norme in /
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.eu>
//
// Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
// Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
//

#include	"LittleHand.h"


void		LittleHand::sortCagette(Cagette &vrac,
    Cagette &citrons,
    Cagette &bananas,
    Cagette &citronsVerts)
{
  Fruit		*item = NULL;
  void		*tab[4] = {
    &citrons,
    &citrons,
    &citronsVerts,
    &bananas};

  item = vrac.pickFruit();
  while (item != NULL)
  {
    static_cast<Cagette *>(tab[item->getType()])->putFruit(item);
    item = vrac.pickFruit();
  }
}

Cagette * const *	LittleHand::organizeCoconut(Coconut const * const * coconuts_paquet)
{
  size_t			y = 0;
  int			size = 0;
  int			idx;
  Cagette		**ret;

  for (y = 0; coconuts_paquet[y] != NULL; y++);
  y = y / 6 + ((y % 2) ? 1 : 0) + 1;
  ret = new Cagette* [y];
  ret[--y] = NULL;
  while (y)
    ret[y--] = NULL;
  y = 0;
  size = 0;
  for (y = 0; coconuts_paquet[y] != NULL; y++)
  {
    ret[idx]->putFruit(static_cast<Fruit *>(const_cast<Coconut *>(coconuts_paquet[y])));
    size++;
    idx = size / 6;
  }
  return ret;
}
