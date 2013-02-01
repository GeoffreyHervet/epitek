#ifndef			MYGAME_HPP
# define		MYGAME_HPP

# include		<list>
# include		<ostream>

# include		<GL/gl.h>
# include		<GL/glu.h>
# include		<Game.hpp>
# include		<Input.hpp>
# include		<GameClock.hpp>
# include		<Text.hpp> 

class			MyGame;

# include		"Map.hpp"
# include		"MapGraph.hpp"
# include		"Camera.hpp"
# include		"Lights.hpp"
# include		"Skybox.hpp"
# include		"Blasts.hpp"
# include		"Bombs.hpp"
# include		"ISoundManager.hpp"
# include		"Players.hpp"
# include		"IMenu.hpp"
# include		"Content.hpp"

class			MyGame : public gdl::Game
{

public:
  enum			State
  {
    STOP,
    MENU,
    GAMEMENU,
    GAME
  };

  MyGame();
  virtual ~MyGame() {};
  
  void			initialize(void);
  void			update(void);
  void			draw(void);
  void			unload(void);

  Map			*getMap(void) { return this->_map; };
  void			setMap(Map* map);

  void			setState(State s) { this->_state = s; };
  State			getState(void) const { return this->_state; };

  Players		&getPlayers(void) { return this->_players; };
  MapGraph		&getMapGraph(void) { return this->_mapGraph; };
  Blasts		&getBlasts(void) { return this->_blasts; };
  Camera		&getCamera(void) { return this->_camera; };
  Bombs			&getBombs(void) { return this->_bombs; };

  void			initCam(void);
  void			setMenu(Menu::IMenu *);
  void			setMainMenu();
  void			reset(void);

  void			restart(void);
  void			newPart(void);

  void			saveGame(void);
  void			loadGame(const std::string &);

  ISoundManager*	getSoundManager(void) const { return this->_soundManager; };
  gdl::GameClock const&	getClock(void) const { return this->gameClock_; };
  gdl::Input&		getInput(void) { return this->input_; };

  double		totalTime(void) const { return gameClock_.getTotalGameTime(); }
  double		frameTime(void) const { return gameClock_.getElapsedTime(); }

private:

  bool	        	_intro;
  Camera		_camera;

  // winner
  bool			_haveWinner;
  double		_timeWinner;
  gdl::Text		_txt;

  Players		_players;
  Bombs			_bombs;
  Lights		_lights;
  Blasts		_blasts;

  Map*			_map;
  MapGraph		_mapGraph;
  
  bool			_escapeFree;
  State			_state;
  Menu::IMenu*		_menu;
  ISoundManager*	_soundManager;
  Skybox		_skybox;
  Content		_contentGame;

};

#endif
