/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
*/

#ifndef __CAGETTE_H_
# define __CAGETTE_H_

#include		"Fruit.h"
#include		"FruitNode.h"

class			Cagette
{
  FruitNode		*_list;

  int			_size;

  public:
    Cagette(int size) : _list(NULL), _size(size) {} ;
    ~Cagette();

    int			nbFruits();
    const int		getSize() const { return this->_size; };

    bool		putFruit(Fruit *f); // Ajout un fruit dans la cag
    Fruit		*pickFruit(); // Retire un fruit de la cagette
    const FruitNode	*head() const { return this->_list; };

  protected:
    bool		inCagette(const Fruit *) const;

  private:
    Cagette		&operator=(const Cagette &c);
    Cagette(const Cagette &c){};
};

#endif /* !__CAGETTE_H_ */
