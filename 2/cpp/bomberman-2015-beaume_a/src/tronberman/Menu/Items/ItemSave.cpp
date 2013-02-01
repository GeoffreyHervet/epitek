#include	<algorithm>

#include	"ItemSave.hpp"
#include	"DirectoryReader.hpp"
#include	"Config.hpp"

namespace	Menu
{
  ItemSave::ItemSave(std::string const& name, std::string const& dir)
    : AMenuObjectEditable(name)
  {
    this->_values = DirectoryReader::getBackups(dir);
    this->_it = this->_values.begin();
  }

  ItemSave::~ItemSave()
  {}

  std::string const&	ItemSave::next(void)
  {
    ++this->_it;
    if (this->_it == this->_values.end())
      this->_it = this->_values.begin();
    return this->value();
  }

  std::string const&	ItemSave::prev(void)
  {
    if (this->_it == this->_values.begin())
      this->_it = this->_values.end();
    --this->_it;
    return this->value();
  }
}
