//
// Cook.hpp for  in /home/tortor_t//Documents/prog/plazza/src
// 
// Made by thomas tortorini-kanan
// Login   <tortor_t@epitech.net>
// 
// Started on  Wed Apr 11 16:36:33 2012 thomas tortorini-kanan
// Last update Fri Apr 13 22:52:28 2012 thomas tortorini-kanan
//

#ifndef				COOK_HPP
#define				COOK_HPP

#include			<iostream>
#include			<cmath>
#include			"Pizza.hpp"
#include			"Menu.hpp"

class				Cook
{

  double			m_rad;
  double			m_dist;
  Pizza const*			m_pizza;
  Pizza::eSize			m_pizza_size;
  unsigned			m_ingr_remain;

public:

  Cook(void)
  {
    this->m_rad = 0;
    this->m_dist = 1.0;
    this->m_pizza = NULL;
    this->m_ingr_remain = 0;
  }

  void				setRad(double rad) { this->m_rad = rad; }
  void				setDist(double dist) { this->m_dist = dist; }
  void				setPizza(Pizza const* pizza, Pizza::eSize size)
  {
    this->m_pizza = pizza;
    this->m_pizza_size = size;
    this->m_ingr_remain = pizza->getIngrs().size();
  }

  double			getRad(void) const { return this->m_rad; }
  double			getDist(void) const { return this->m_dist; }
  Pizza const*			getPizza(void) const { return this->m_pizza; }
  unsigned			getNextIngr(void)
  {
    return !this->m_ingr_remain ? 0 :
      this->m_pizza->getIngrs()[--this->m_ingr_remain];
  }

  void				print(Menu const& menu) const
  {
    std::cout << "Cook(" << this->m_rad << "; " << this->m_dist << ") ";
    if (this->m_pizza)
      {
	this->m_pizza->print(menu.getIngrs());
	std::cout << " (size: " << this->m_pizza_size << ")";
      }
    else
      std::cout << " :)";
    std::cout << "\n";
  }

};

#endif
