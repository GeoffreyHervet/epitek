//
// Menu.hpp for  in /home/tortor_t//Documents/prog/plazza/src
// 
// Made by thomas tortorini-kanan
// Login   <tortor_t@epitech.net>
// 
// Started on  Fri Apr 13 15:47:24 2012 thomas tortorini-kanan
// Last update Fri Apr 13 23:17:22 2012 thomas tortorini-kanan
//

#ifndef					MENU_HPP
#define					MENU_HPP

#include				<vector>
#include				<string>
#include				<sstream>
#include				<iostream>
#include				"Ingredients.hpp"
#include				"Pizza.hpp"
#include				"strtools.hpp"

class					Menu
{
  
  Ingredients				m_ingrs;
  std::vector<Pizza>			m_pizzas;

  bool					pizzaExist(std::string const& name)
  {
    for (unsigned i = 0; i < this->m_pizzas.size(); ++i)
      if (this->m_pizzas[i].getName() == name)
	return true;
    return false;
  }

public:

  Ingredients const&			getIngrs(void) const { return this->m_ingrs; }
  
  Pizza const*				getPizza(unsigned i) const
  {
    if (i < this->m_pizzas.size())
      return &this->m_pizzas[i];
    return NULL;
  }

  Pizza const*				getPizza(std::string const& name) const
  {
    for (unsigned i = 0; i < this->m_pizzas.size(); ++i)
      if (this->m_pizzas[i].getName() == name)
	return &this->m_pizzas[i];
    return NULL;
  }

  bool					newPizza(std::string const& s_src)
  {
    Pizza				pizza;
    std::string                         s(s_src), tok;
    std::stringstream			buf, my_atoi;
    unsigned				i = 0, sec_tmp, nb_ingrs;

    strReplaceChar(strToLower(s), '\t', ' ');
    buf << s;
    while (getline(buf, tok, ' '))
      if (tok != "")
	switch (++i)
	  {
	  case 1:
	    if (this->pizzaExist(tok))
	      return false;
	    nb_ingrs = this->m_ingrs.getNbIngrs();
	    pizza.setName(tok);
	    break;
	  case 2:
	    my_atoi << tok;
	    my_atoi >> sec_tmp;
	    pizza.setSec(sec_tmp);
	    break;
	  default:
	    pizza.setIngr(this->m_ingrs.newIngredient(tok));
	  }
    this->m_pizzas.push_back(pizza);
    return nb_ingrs != this->m_ingrs.getNbIngrs();
  }

  void					print(void) const
  {
    this->m_ingrs.print();
    std::cout << "Pizzas:\n";
    for (unsigned i = 0; i < this->m_pizzas.size(); ++i)
      {
	this->m_pizzas[i].print(this->m_ingrs);
	std::cout << "\n";
      }
  }

};

#endif
