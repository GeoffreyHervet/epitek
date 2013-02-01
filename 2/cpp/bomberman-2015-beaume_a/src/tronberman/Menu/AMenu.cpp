# include	<algorithm>

# include	"Error.hpp"
# include	"AMenu.hpp"

namespace	Menu
{

  AMenu::AMenu(MyGame &g) :
    _pos(0),
    _txt("./res/font/DisplayOTF.otf"),
    _game(g),
    _sm(g.getSoundManager())
  {
    this->_txt.setSize(50);

    this->_releaseKeys[gdl::Keys::W] = true;
    this->_releaseKeys[gdl::Keys::K] = true;
    this->_releaseKeys[gdl::Keys::Up] = true;

    this->_releaseKeys[gdl::Keys::S] = true;
    this->_releaseKeys[gdl::Keys::J] = true;
    this->_releaseKeys[gdl::Keys::Down] = true;

    this->_releaseKeys[gdl::Keys::D] = true;
    this->_releaseKeys[gdl::Keys::L] = true;
    this->_releaseKeys[gdl::Keys::Right] = true;

    this->_releaseKeys[gdl::Keys::A] = true;
    this->_releaseKeys[gdl::Keys::H] = true;
    this->_releaseKeys[gdl::Keys::Left] = true;

    this->_releaseKeys[gdl::Keys::Return] = true;

    std::vector<gdl::Keys::Key>		binds;
    binds.push_back(gdl::Keys::W);
    binds.push_back(gdl::Keys::K);
    binds.push_back(gdl::Keys::Up);
    this->_binds.push_back(binds);
    binds.clear();

    binds.push_back(gdl::Keys::S);
    binds.push_back(gdl::Keys::J);
    binds.push_back(gdl::Keys::Down);
    this->_binds.push_back(binds);
    binds.clear();

    binds.push_back(gdl::Keys::D);
    binds.push_back(gdl::Keys::L);
    binds.push_back(gdl::Keys::Right);
    this->_binds.push_back(binds);
    binds.clear();

    binds.push_back(gdl::Keys::A);
    binds.push_back(gdl::Keys::H);
    binds.push_back(gdl::Keys::Left);
    this->_binds.push_back(binds);
    binds.clear();
  }

  AMenu::~AMenu()
  {
  }

  void		AMenu::playOver(void)
  {
    if (this->_sm)
    {
      try { this->_sm->playSound("./res/sounds/hover.wav"); }
      catch (const ::Error &e) { std::cerr << "[" << e.level() << "]" << e.what() << std::endl; }
    }
  }

  bool		AMenu::escapeMainMenu(gdl::Input &in)
  {
    if (!in.isKeyDown(gdl::Keys::Escape))
      return false;
    this->_game.setMainMenu();
    return true;
  }

  void		AMenu::update(gdl::Input &in)
  {
    std::for_each(this->_releaseKeys.begin(), this->_releaseKeys.end(), AMenu::Reseter(&in));
  }


  bool		AMenu::checkBind(gdl::Input &in, int idx)
  {
    bool	ret = false;

    for (std::vector<gdl::Keys::Key>::iterator it = this->_binds[idx].begin();
        it != this->_binds[idx].end();
        ++it)
      if (in.isKeyDown(*it) && this->_releaseKeys[*it])
      {
        this->_releaseKeys[*it] = false;
        ret = true;
      }

    return ret;
  }

  bool		AMenu::checkEnter(gdl::Input &in)
  {
    if (in.isKeyDown(gdl::Keys::Return) && this->_releaseKeys[gdl::Keys::Return])
    {
      this->_releaseKeys[gdl::Keys::Return] = false;
      if (this->_sm)
      {
        try { this->_sm->playSound("./res/sounds/ok.mp3"); }
        catch (const ::Error &e) { std::cerr << "[" << e.level() << "]" << e.what() << std::endl; }
      }
      return true;
    }
    return false;
  }

  void		AMenu::init(const gdl::Window &w)
  {
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w.getWidth(), 0.0, (GLdouble)w.getHeight());
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
  }

}
