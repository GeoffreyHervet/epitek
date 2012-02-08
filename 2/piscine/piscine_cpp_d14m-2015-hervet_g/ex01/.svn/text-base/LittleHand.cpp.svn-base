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
