#ifndef CREDITSVIEW_HPP_
# define CREDITSVIEW_HPP_

# include	<vector>
# include	<Text.hpp>

# include	"AMenu.hpp"
# include	"AMenuObject.hpp"
# include	"MyGame.hpp"

namespace	Menu
{
  class		CreditsView : public  AMenu
  {
    private:
      CreditsView(const CreditsView &);
      CreditsView &operator=(const CreditsView &);
    public:
      CreditsView(MyGame &, gdl::Input &);
      ~CreditsView();

      void	update(gdl::Input &);
      void	draw(gdl::Window &);

    private:
      std::vector<std::string>		 _boulzors;
  };
}

#endif /* CREDITSVIEW_HPP_ */
