#ifndef AMENUOBJECTEDITABLE_HPP_
# define AMENUOBJECTEDITABLE_HPP_

# include	"AMenuObject.hpp"

namespace	Menu
{
  class		AMenuObjectEditable : public AMenuObject
  {
    public:
      AMenuObjectEditable(const std::string &s) : AMenuObject(s) {}
      virtual ~AMenuObjectEditable(){};

      virtual const std::string &next() = 0;
      virtual const std::string &prev() = 0;

      virtual const std::string &value() const = 0;

      bool	 	selected(IMenu&, MyGame&, gdl::Input &){ return false; };
  };
};

#endif /* AMENUOBJECTEDITABLE_HPP_ */
