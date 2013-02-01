#ifndef AMENUOBJECT_HPP_
# define AMENUOBJECT_HPP_

# include <string>
# include <iostream>

namespace	Menu {
  class		AMenuObject;
}

# include "MyGame.hpp"
# include "IMenu.hpp"

namespace	Menu
{
  class		AMenuObject
  {
    public:
      AMenuObject(const std::string &n) : _name(n) {};
      virtual ~AMenuObject() {};

    public:
      const std::string	&getName() const { return this->_name; };
      void		 setName(const std::string &n) { this->_name = n; };

      virtual bool	 selected(::Menu::IMenu &, MyGame &, gdl::Input &) = 0; 
    private:
      std::string	_name;
  };
}

#endif /* AMENUOBJECT_HPP_ */
