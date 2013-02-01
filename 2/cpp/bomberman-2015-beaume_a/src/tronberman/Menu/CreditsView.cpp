#include	"CreditsView.hpp"


namespace	Menu
{

  CreditsView::CreditsView(MyGame &g, gdl::Input &in) :
    AMenu(g)
  {
    this->_txt.setSize(30);
    this->_releaseKeys[gdl::Keys::Return] = !in.isKeyDown(gdl::Keys::Return);
    this->_boulzors.push_back("Thomas Tortorini -> .");
    this->_boulzors.push_back("Pierre Collet -> Etudiant EPITECH");
    this->_boulzors.push_back("/* Aymeric Beaumet -> Chef // de groupe */");
    this->_boulzors.push_back("Jonathan Salwan -> Haxxor");
    this->_boulzors.push_back("Mathieu Ghennassia -> Et 10 teur");
    this->_boulzors.push_back("Geoffrey Hervet -> Soutien moral");
  }

  CreditsView::~CreditsView()
  {
  }

  void		CreditsView::update(gdl::Input &in)
  {
    if (in.isKeyDown(gdl::Keys::Escape))
      this->_game.setMainMenu();
  }

  void		CreditsView::draw(gdl::Window &)
  {
    int i = 0;
    for (std::vector<std::string>::const_iterator it = this->_boulzors.begin();
        it != this->_boulzors.end();
        ++it)
    {
      this->_txt.setPosition(30 + 50, (i+1) * 50);
      this->_txt.setText(*it);
      this->_txt.draw();
      ++i;
    }
  }

}
