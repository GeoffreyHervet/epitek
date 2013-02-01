#ifndef AMENU_HPP_
# define AMENU_HPP_

# include <vector>
# include <string>
# include <map>

# include <Window.hpp>
# include <Input.hpp>

# include "MyGame.hpp"
# include "IMenu.hpp"

namespace	Menu
{
  class		AMenu : public IMenu
  {
    public:
      AMenu(MyGame &);
      ~AMenu();

    protected:
      void		 playOver(void);
      virtual void	 update(gdl::Input &);
      bool		 escapeMainMenu(gdl::Input &);

      bool		 checkUp(gdl::Input &i) { return this->checkBind(i, 0); };
      bool		 checkDown(gdl::Input &i) { return this->checkBind(i, 1); };
      bool		 checkRight(gdl::Input &i) { return this->checkBind(i, 2); };
      bool		 checkLeft(gdl::Input &i) { return this->checkBind(i, 3); };

      bool		 checkEnter(gdl::Input &);

    private:
      bool		 checkBind(gdl::Input &, int);

    public:
      virtual void	 init(const gdl::Window &);

    protected:
      int				_pos;
      gdl::Text				_txt;
      MyGame &				_game;
      ISoundManager			*_sm;
      std::map<gdl::Keys::Key, bool>	_releaseKeys;
      std::vector< std::vector<gdl::Keys::Key>	> _binds;

    private:
      class		Reseter
      {
        public:
          Reseter(gdl::Input *in):_in(in) {};
          ~Reseter(){};
          void	operator()(std::pair<const gdl::Keys::Key, bool> &p) const;

        private:
          gdl::Input			*_in;
      };
  };
}

#endif /* AMENU_HPP_ */
