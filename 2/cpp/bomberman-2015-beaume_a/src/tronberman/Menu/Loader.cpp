#include		<sstream>
#include		<algorithm>

#include		"Error.hpp"
#include		"Loader.hpp"
#include		"ItemSave.hpp"
#include		"Number.hpp"

namespace Menu
{
  Loader::Loader(MyGame &g, gdl::Input &in) :
    AMenu(g)
  {
    this->_releaseKeys[gdl::Keys::Return] = !in.isKeyDown(gdl::Keys::Return);
    this->_item = new ::Menu::ItemSave("Sauvegarde");
  }

  Loader::~Loader()
  {
  }

  void			Loader::update(gdl::Input &in)
  {
    AMenu::update(in);

    if (in.isKeyDown(gdl::Keys::Escape))
    {
      this->_game.setMainMenu();
      return ;
    }
    if (this->checkLeft(in))
    {
      this->_item->prev();
      this->playOver();
    }
    if (this->checkRight(in))
    {
      this->_item->next();
      this->playOver();
    }
    if (this->checkEnter(in))
    {
      this->_game.loadGame(this->_item->value());
      return;
    }
  }

  void			Loader::draw(gdl::Window &)
  {
    if (this->_item->getSize() == 0)
    {
      this->_txt.setText("Aucune sauvegarde");
      this->_txt.setPosition(30, 50);
      this->_txt.draw();
      return;
    }

    this->_txt.setPosition(30 + 50, 1 * 50);
    this->_txt.setText(this->_item->getName());
    this->_txt.draw();

    std::stringstream	ss;

    ss << "< " << this->_item->value() << " >";
    this->_txt.setPosition(600 + 50, 50);
    this->_txt.setText(ss.str());
    this->_txt.draw();
  }

}
