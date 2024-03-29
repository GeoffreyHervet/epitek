/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
*/

#ifndef __FRUIT_H_
# define __FRUIT_H_                                                                                                                                                             _

# include	<string>

class		Fruit
{
  int		_vitamins;
  std::string	_name;

  public:
    virtual ~Fruit() {};
    Fruit(int v, std::string const &n): _vitamins(v), _name(n){};

    const std::string	&getName() const { return this->_name; };
    int			getVitamins() const { return this->_vitamins; }; 
};

#endif /* !__FRUIT_H_ */
