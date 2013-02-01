#include	<iostream>
#include	<algorithm>

#include	"Error.hpp"
#include	"ItemMap.hpp"
#include	"DirectoryReader.hpp" 
namespace	Menu
{
  ItemMap::ItemMap(std::string const& name, std::string const& dir)
    : AMenuObjectEditable(name)
  {
    try { this->_values = DirectoryReader::getMaps(dir); }
    catch (const Error &e) { std::cerr << "[" << e.level() << "] " << e.what() << std::endl; }
    this->_values.push_front("random");
    this->_it = this->_values.begin();
  }

  ItemMap::~ItemMap()
  {}

  std::string const&	ItemMap::next(void)
  {
    ++this->_it;
    if (this->_it == this->_values.end())
      this->_it = this->_values.begin();
    return this->value();
  }

  std::string const&	ItemMap::prev(void)
  {
    if (this->_it == this->_values.begin())
      this->_it = this->_values.end();
    --this->_it;
    return this->value();
  }

}
