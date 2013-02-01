#ifndef MAP_HPP_
# define MAP_HPP_

# include	<list>

# include	"AMenuObjectEditable.hpp"
# include	"Config.hpp"

namespace	Menu
{
  class		ItemMap : public AMenuObjectEditable
  {
    public:
      ItemMap(const std::string &name, const std::string &dir = Config::MapDirectory);
      ~ItemMap();

      const std::string & next();
      const std::string & prev();

      const std::string & value() const { return *(this->_it); };

      void	operator()(const std::string &val) {this->_values.push_back(val);};

    private:
      std::list<std::string>	_values;
      std::list<std::string>::const_iterator _it;
  };
}

#endif /* MAP_HPP_ */
