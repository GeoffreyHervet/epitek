#ifndef SETTINGS_HPP_
# define SETTINGS_HPP_

# include	"AMenuObject.hpp"

namespace	Menu
{
  class		SettingsOpener : public AMenuObject
  {
    private:
      SettingsOpener(const SettingsOpener &);
      SettingsOpener &operator=(const SettingsOpener);
    public:
      SettingsOpener(const std::string &);
      ~SettingsOpener();

      bool	 	selected(IMenu &, MyGame &, gdl::Input &);
  };
}

#endif /* SETTINGS_HPP_ */
