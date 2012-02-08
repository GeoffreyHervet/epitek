/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
*/

#ifndef __FRUITNODE_H_
# define __FRUITNODE_H_

# include	"Fruit.h"

struct		FruitNode
{
  Fruit		*value;
  FruitNode	*next;

  public:
    FruitNode(Fruit *v, FruitNode *n) : value(v), next(n) {};
};

#endif /* !__FRUITNODE_H_ */
