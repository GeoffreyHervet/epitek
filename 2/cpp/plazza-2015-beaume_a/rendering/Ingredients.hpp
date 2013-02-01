//
// Ingredients.cpp for  in /home/tortor_t//Documents/prog/plazza/src
// 
// Made by thomas tortorini-kanan
// Login   <tortor_t@epitech.net>
// 
// Started on  Fri Apr 13 10:48:06 2012 thomas tortorini-kanan
// Last update Fri Apr 13 23:17:04 2012 thomas tortorini-kanan
//

#ifndef					INGREDIENTS_HPP
#define					INGREDIENTS_HPP

#include				<string>
#include				<vector>

class					Ingredients
{

  std::vector<std::string>		m_ingrs;

public:

  std::string const&			getName(unsigned i) const { return this->m_ingrs[i]; }
  unsigned				getNbIngrs(void) const { return this->m_ingrs.size(); }

  unsigned				newIngredient(std::string const& ingr)
  {
    unsigned				i;

    for (i = 0; i < this->m_ingrs.size(); ++i)
      if (this->m_ingrs[i] == ingr)
	return i;
    this->m_ingrs.push_back(ingr);
    return i;
  }

  void					print(void) const
  {
    std::cout << "Ingredients:\n";
    for (unsigned i = 0; i < this->m_ingrs.size(); ++i)
      std::cout << "  " << i << ". " << this->m_ingrs[i] << "\n";
  }

};

#endif
