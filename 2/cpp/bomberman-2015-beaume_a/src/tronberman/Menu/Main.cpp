#include <iostream>
#include <algorithm>
#include <sstream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <Text.hpp>

#include "Error.hpp"
#include "Main.hpp"
#include "Deleter.hpp"
#include "IMenu.hpp"

namespace	Menu
{
  Main::Main(MyGame &g, gdl::Input &in) :
    AMenu(g)
  {
    this->_releaseKeys[gdl::Keys::Return] = !in.isKeyDown(gdl::Keys::Return);
  }

  Main::~Main()
  {
  }

  void			Main::clear(void)
  {
    std::for_each(this->_items.begin(), this->_items.end(), deleter());
  }

  Main			&Main::operator<<(AMenuObject *item)
  {
    this->_items.push_back(item);
    return *this;
  }

  void		Main::update(gdl::Input &i)
  {
    AMenu::update(i);

    if (!this->_items.size())
      return;

    if (this->checkUp(i)) 
    {
      this->_pos = (this->_items.size() + this->_pos - 1) % this->_items.size();
      this->playOver();
    }
    if (this->checkDown(i))
    {
      this->_pos = (this->_pos + 1) % this->_items.size();
      this->playOver();
    }
    if (this->checkEnter(i))
    {
      this->_items[this->_pos]->selected(*this, this->_game, i);
      return;
    }
  }

  void Main::draw(gdl::Window &)
  {
    int i = 0;
    for (std::vector<AMenuObject *>::const_iterator it = this->_items.begin();
        it != this->_items.end();
        ++it)
    {
      if (i == this->_pos)
      {
        this->_txt.setText(">");
        this->_txt.setPosition(30, (i+1) * 50);
        this->_txt.draw();
      }
      this->_txt.setPosition(30 + 50, (i+1) * 50);
      this->_txt.setText((*it)->getName());
      this->_txt.draw();
      ++i;
    }
  }

}
