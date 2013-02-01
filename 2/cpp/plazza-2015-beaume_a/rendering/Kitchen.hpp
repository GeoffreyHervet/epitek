//
// kitchen.hpp for  in /home/tortor_t//Documents/prog/plazza/src
// 
// Made by thomas tortorini-kanan
// Login   <tortor_t@epitech.net>
// 
// Started on  Sat Mar 31 06:56:06 2012 thomas tortorini-kanan
// Last update Wed Apr 11 21:03:09 2012 thomas tortorini-kanan
//

#ifndef				KITCHEN_HPP
#define				KITCHEN_HPP

#include			<iostream>
#include			<vector>
#include			<cmath>
#include			"Cook.hpp"
#include			"Pizza.hpp"
#include			"Menu.hpp"

#define				NB_INGR_START	5
#define				RAY_COOK	5
#define				KITCHEN_RAY	50

class				Kitchen
{
  
  struct			Command
  {
    Pizza const*		pizza;
    Pizza::eSize		size;
  };

  double			m_x, m_y;
  std::vector<unsigned>		m_ingrs;
  std::vector<Cook>		m_cooks;
  std::vector<Command>		m_commands;

public:

  Kitchen(unsigned nb_cooks, unsigned nb_ingrs, double x = 0, double y = 0)
  {
    this->m_x = x;
    this->m_y = y;
    this->enlargeNbCooks(nb_cooks);
    this->enlargeNbIngrs(nb_ingrs);
  }

  double			getPosX(void) const { return this->m_x; }
  double			getPosY(void) const { return this->m_y; }
  double			getRayon(void) const { return this->m_cooks.size() * (RAY_COOK * 2 + 10) / M_PI / 2.0; } 
  unsigned			getNbCooks(void) const { return this->m_cooks.size(); }
  unsigned			getNbIngrs(void) const { return this->m_ingrs.size(); }
  unsigned			getIngr(unsigned i) const { return this->m_ingrs[i]; }
  Cook const&			getCook(unsigned i) const { return this->m_cooks[i]; }

  void				setPosX(double x) { this->m_x = x; }
  void				setPosY(double y) { this->m_y = y; }

  void				enlargeNbCooks(int nb_new_cooks)
  {
    Cook			cook;

    for (int i = 0; i < nb_new_cooks; ++i)
      this->m_cooks.push_back(cook);
  }

  bool				commandPizza(Pizza const* pizza, Pizza::eSize size)
  {
    Command			com = {pizza, size};

    if (!pizza || this->m_commands.size() >= this->m_cooks.size())
      return false;
    this->m_commands.push_back(com);
    this->leavePizzas();
    return true;
  }

  void				ingrReload(int nb)
  {
    for (unsigned i = 0; i < this->m_ingrs.size(); ++i)
      this->m_ingrs[i] += nb;
  }
  
  void				enlargeNbIngrs(int nb_new_ingrs)
  {
    for (int i = 0; i < nb_new_ingrs; ++i)
      this->m_ingrs.push_back(NB_INGR_START);
  }

  void				leavePizzas(void)
  {
    unsigned			i, j;

    for (i = 0; i < this->m_commands.size(); ++i)
      {
	for (j = 0; j < this->m_cooks.size(); ++j)
	  if (!this->m_cooks[j].getPizza())
	    {
	      this->m_cooks[j].setPizza(this->m_commands[i].pizza, this->m_commands[i].size);
	      this->m_commands.erase(this->m_commands.begin() + i);
	      --i;
	      break;
	    }
	if (j >= this->m_cooks.size())
	  return;
      }
  }

  void				moveCooks(double frametime)
  {
    static double		a;
    unsigned			i, nb_cooks = 0;
    double			rad_div;

    a += .1 * frametime;
    for (i = 0; i < this->m_cooks.size(); ++i)
      if (!this->m_cooks[i].getPizza())
	++nb_cooks;
    rad_div = 2 * M_PI / nb_cooks;
    for (i = 0; i < this->m_cooks.size(); ++i)
      {
	if (this->m_cooks[i].getPizza())
	  this->m_cooks[i].setRad(this->m_cooks[i].getRad() - 2 * frametime);
	else
	  {
	    double rad = (rad_div * i - this->m_cooks[i].getRad()) * .2;
	    this->m_cooks[i].setRad(this->m_cooks[i].getRad() + rad + a);
	  }
	double dist = (this->getRayon() + KITCHEN_RAY * (this->m_cooks[i].getPizza() != NULL)
		       - this->m_cooks[i].getDist()) * 5 * frametime;
	this->m_cooks[i].setDist(this->m_cooks[i].getDist() + dist);
      }
  }

  void				print(Menu const& menu) const
  {
    std::cout << "Cuisine(" << this->m_x << "; " << this->m_y << ")\n";
    std::cout << " * pizzas en attente: " << this->m_commands.size() << "\n";
    for (unsigned i = 0; i < this->m_commands.size(); ++i)
      {
	this->m_commands[i].pizza->print(menu.getIngrs());
	std::cout << " (size: " << this->m_commands[i].size << ")\n";
      }
    std::cout << " * cuisiniers: " << this->m_cooks.size() << "\n";
    for (unsigned i = 0; i < this->m_cooks.size(); ++i)
      {
	std::cout << "   " << i << ". ";
	this->m_cooks[i].print(menu);
      }
  }

};

#endif
