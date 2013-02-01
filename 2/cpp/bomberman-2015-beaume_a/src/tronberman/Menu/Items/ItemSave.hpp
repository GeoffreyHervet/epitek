#ifndef SAVE_HPP_
# define SAVE_HPP_

# include	<list>

# include	"AMenuObjectEditable.hpp"
# include	"Config.hpp"

namespace Menu
{
  class		ItemSave : public AMenuObjectEditable
  {
    public:
      ItemSave(const std::string &name, const std::string &dir = Config::BackupsDirectory);
      ~ItemSave();

      const std::string & next();
      const std::string & prev();

      const std::string & value() const { return *(this->_it); };

      void	operator()(const std::string &val) {this->_values.push_back(val);};

      unsigned int	getSize() const { return this->_values.size(); }

    private:
      std::list<std::string>	_values;
      std::list<std::string>::const_iterator _it;
  };
}

#endif /* !SAVE_HPP_ */
