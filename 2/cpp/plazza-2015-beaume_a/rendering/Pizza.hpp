//
// Pizza.hpp for  in /home/tortor_t//Documents/prog/plazza/src
// 
// Made by thomas tortorini-kanan
// Login   <tortor_t@epitech.net>
// 
// Started on  Thu Apr 12 17:16:37 2012 thomas tortorini-kanan
// Last update Fri Apr 13 22:57:19 2012 thomas tortorini-kanan
//

#ifndef					PIZZA_HPP
#define					PIZZA_HPP

#include				<iostream>
#include				<string>
#include				<vector>
#include				"Ingredients.hpp"

class					Pizza
{

  std::string				m_name;
  std::vector<unsigned>			m_ingrs;
  unsigned				m_sec;

public:

  enum eSize {S = 1, M = 2, L = 4, XL = 8, XXL = 16};

  std::string const&			getName(void) const { return this->m_name; }
  std::vector<unsigned> const&		getIngrs(void) const { return this->m_ingrs; }
  unsigned				getSec(void) const { return this->m_sec; }

  void					setName(std::string const& name) { this->m_name = name; }
  void					setIngr(unsigned ingr) { this->m_ingrs.push_back(ingr); }
  void					setSec(unsigned sec) { this->m_sec = sec; }

  void					print(Ingredients const& ingrs) const
  {
    std::cout << "\"" << this->m_name << "\" :\t";
    for (unsigned i = 0; i < this->m_ingrs.size(); ++i)
      {
	if (i)
	  std::cout << ", ";
	std::cout << ingrs.getName(this->m_ingrs[i]);
      }
    std::cout << std::flush;
  }

};

#endif
