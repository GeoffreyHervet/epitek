#include	<algorithm>
#include	<unistd.h>

#include	"Error.hpp"
#include	"MenuGame.hpp"
#include	"SaveGame.hpp"
#include	"Resume.hpp"
#include	"BackToMain.hpp"
#include	"Restart.hpp"

namespace	Menu
{
  Game::Game(MyGame &g, gdl::Input &in) :
    AMenu(g)
  {
    this->_releaseKeys[gdl::Keys::Return] = !in.isKeyDown(gdl::Keys::Return);
    this->_items.push_back(new ::Menu::Resume("Reprendre"));
    this->_items.push_back(new ::Menu::Restart("Recommencer"));
    this->_items.push_back(new ::Menu::SaveGame("Sauvegarder"));
    this->_items.push_back(new ::Menu::BackToMain("Retourner au Menu"));
  }

  Game::~Game()
  {
  }

  void		Game::update(gdl::Input &i)
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
      return ;
    }
  }

  void		Game::draw(gdl::Window &w)
  {
    this->init(w);

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

    this->_game.initCam();
  }

  void		Game::reset(void)
  {
    this->_pos = 0;
  }

}
