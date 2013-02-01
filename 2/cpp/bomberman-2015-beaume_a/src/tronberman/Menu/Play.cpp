#include		<sstream>
#include		<algorithm>

#include		"Map.hpp"
#include		"Error.hpp"
#include		"Play.hpp"
#include		"ItemMap.hpp"
#include		"Number.hpp"
#include	"Config.hpp"

namespace		Menu
{
  Play::Play(MyGame &g, gdl::Input &in) :
    AMenu(g),
    _error_map(false)
  {
    this->_releaseKeys[gdl::Keys::Return] = !in.isKeyDown(gdl::Keys::Return);
    this->_items.push_back(new ::Menu::Number("Nombre de joueurs", 0, 2));
    this->_items.push_back(new ::Menu::Number("Nombre d'IA", 0, 30));
    this->_items.push_back(new ::Menu::ItemMap("Carte"));
  }

  Play::~Play()
  {
  }

  void			Play::update(gdl::Input &in)
  {
    AMenu::update(in);

    if ((this->escapeMainMenu(in)) || !this->_items.size())
      return;

    if (this->checkUp(in))
    {
      this->_pos = (this->_items.size() + this->_pos - 1) % this->_items.size();
      this->playOver();
    }
    if (this->checkDown(in))
    {
      this->_pos = (this->_pos + 1) % this->_items.size();
      this->playOver();
    }
    if (this->checkLeft(in))
    {
      this->_items[this->_pos]->prev();
      this->playOver();
    }
    if (this->checkRight(in))
    {
      this->playOver();
      this->_items[this->_pos]->next();
    }
    try
    {
      if (this->checkEnter(in))
      {
        Map*		m = new Map();

        if (this->_items[2]->value() == "random")
        {
          unsigned int w = rand() % 30 + 10;
          m->init(w, w);
          m->randomize();
          m->wallAround();
        }
        else
        {
          std::stringstream	ss;
          ss << Config::MapDirectory << "/" << this->_items[2]->value();
          if (!(m->loadFile(ss.str() + Config::DefaultMapExtension)))
          {
            this->_error_map = true;
            return ;
          }
        }

        this->_game.reset();
        this->_game.setMap(m);
        this->_game.setState(MyGame::GAME);

        std::stringstream b;
        b << this->_items[1]->value();
        int	bots;
        b >> bots;

        if (this->_items[0]->value() == "1")
          this->_game.getPlayers().RealsPlayers("Joueur 1", "", m);
        if (this->_items[0]->value() == "2")
          this->_game.getPlayers().RealsPlayers("Joueur 1", "Joueur 2", m);
        if (bots)
          this->_game.getPlayers().putSomeBots(bots, m, this->_game.getBombs());

        this->_game.newPart();
        this->_game.initCam();
      }
    }
    catch (...)
    {
      this->_error_map = true;
      std::cerr << "!" << std::endl;
    }
  }

  void			Play::draw(gdl::Window &)
  {
    int			i = 0;

    for (std::vector<AMenuObjectEditable *>::const_iterator it = this->_items.begin();
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

      std::stringstream	ss;
       ss << "< " << (*it)->value() << " >";

      this->_txt.setPosition(600 + 50, (i+1) * 50);
      this->_txt.setText(ss.str());
      this->_txt.draw();
      ++i;
    }
    if (this->_error_map)
    {
      this->_txt.setPosition(80, (i+1) * 50);
      this->_txt.setText("Erreur de chargement de la map");
      this->_txt.draw();
    }
  }

  void			Play::AMenu::Reseter::operator()(std::pair<const gdl::Keys::Key, bool> &p) const
  {
    if (!this->_in->isKeyDown(p.first))
      p.second = true;
  }
}
