#include		"Settings.hhp"

namespace		Menu
{
  SettingsOpener::SettingsOpener(const std::string &s)
    : AMenuObject(s)
  {
  }

  SettingsOpener::~SettingsOpener()
  {
  }

   SettingsOpener::selected(::Menu::IMenu &, MyGame &game, gdl::Input &)
   {

   }
};
