#include		<fstream>
#include		<sstream>
#include		<stdio.h>
#include		<time.h>
#include		<iostream>

#include		"MyGame.hpp"
#include		"FastGame.hpp"
#include		"Quit.hpp"
#include		"Zlock.hpp"
#include		"Credits.hpp"
#include		"Main.hpp"
#include		"PrePlay.hpp"
#include		"LoadGame.hpp"
#include		"FmodManager.hpp"
#include		"Error.hpp"
#include		"MenuGame.hpp"
#include		"Config.hpp"

MyGame::MyGame() :
  _intro(true),
  _camera(this->_intro),
  _haveWinner(false),
  _timeWinner(0),
  _txt("./res/font/DisplayOTF.otf"),
  _players(this->_intro)
{
}

void			MyGame::initialize(void)
{
  this->_txt.setSize(50);
  this->setState(MyGame::MENU);
  this->window_.setTitle("Tronberman");
  this->window_.setWidth(1200);
  this->window_.setHeight(675);
  this->window_.create();
  this->_menu = 0;

  this->_lights.initialize();

  try {
    this->_soundManager = new FmodManager();
    this->_soundManager->setVolume(100);
    this->_soundManager->setFlag(ISoundManager::LOOP);
    this->_soundManager->playSound("./res/sounds/bomberman.mp3", 0, 50);
    this->_soundManager->unsetFlag(ISoundManager::LOOP);
  }
  catch (const Error& e) {
    std::cerr << "[" << e.level() << "]" << e.what() << std::endl;
    this->_soundManager = 0;
  }

  this->_bombs.setSoundManager(this->_soundManager);
  this->_camera.setSoundManager(this->_soundManager);
  this->_escapeFree = true;
  this->setMainMenu();
  srand(time(NULL));
}

void			MyGame::setMainMenu(void)
{
  if (this->_menu)
    delete this->_menu;

  Menu::Main *menu = new Menu::Main(*this, this->input_);

  *menu
    << new Menu::FastGame("Partie rapide")
    << new Menu::PrePlay("Nouvelle partie")
    << new Menu::LoadGame("Charger une partie")
    << new Menu::Credits("Credits")
    << new Menu::Zlock("Verrouiller l'ecran")
    << new Menu::Quit("Quitter le jeu");
  this->_menu = menu;

  if (this->_state == MyGame::MENU)
    this->_menu->init(this->window_);
}


void			MyGame::update(void)
{
  this->_camera.update(gameClock_, input_);
  this->_skybox.update(gameClock_, input_);

  if (!this->_escapeFree && !this->input_.isKeyDown(gdl::Keys::Escape))
    this->_escapeFree = true;

  if (this->_state == MyGame::MENU)
    this->_menu->update(this->input_);
  else
    {
      if (this->_escapeFree && this->input_.isKeyDown(gdl::Keys::Escape))
      {
        this->_escapeFree = false;
        if (this->_state != MyGame::GAMEMENU)
        {
            if (this->_menu)
              delete this->_menu;
            this->_menu = new Menu::Game(*this, this->input_);
          this->_state = MyGame::GAMEMENU;
        }
        else
          this->_state = MyGame::GAME;
      }

      if (this->_state == MyGame::GAMEMENU)
      {
        this->_menu->update(this->input_);
        this->_bombs.wait(this->gameClock_.getElapsedTime());
      }

      else
      {
        this->_lights.update(gameClock_, input_);
        this->_mapGraph.update(gameClock_, input_);
        if (!this->_haveWinner)
          this->_players.update(*this);
        this->_bombs.update(*this);
        this->_blasts.update(this->_mapGraph, this->gameClock_.getElapsedTime());
      }
      if (!this->_haveWinner && (this->_haveWinner = this->_players.haveAWinner()))
        this->_timeWinner = 3;
      else if (this->_timeWinner > 0)
        this->_timeWinner -= this->gameClock_.getElapsedTime();
      else if (this->_haveWinner && this->_timeWinner < 0)
      {
        this->setMainMenu();
        this->_state = MENU;
      }
    }
}

void			MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  this->_camera.draw();
  this->_skybox.draw();

  if (this->_state == MyGame::STOP)
    this->window_.close();
  else if (this->_state == MyGame::MENU)
  {
    this->_menu->init(this->window_);
    this->_menu->draw(this->window_);
    this->initCam();
    return ;
  }
  else
    {
      this->_mapGraph.draw();
      this->_players.draw();
      this->_blasts.draw(this->_camera.getThetaDeg(), this->_camera.getPhyDeg());
      if (this->_state == MyGame::GAMEMENU)
        this->_menu->draw(this->window_);
      this->_camera.showCounter();
    }
  if (this->_haveWinner && this->_timeWinner > 0)
  {
    this->_menu->init(this->window_);
    this->_txt.setPosition(300, 30);
    std::stringstream	ss("");
    ss << "Le gagnant est : " << this->_players.getWinner();
    this->_txt.setText(ss.str());
    this->_txt.draw();
    this->initCam();
  }
}

void			MyGame::reset(void)
{
  this->_bombs = Bombs();
  this->_bombs.setSoundManager(this->_soundManager);
  this->_players.reset();
  this->_blasts = Blasts();
  this->_intro = true;
}

void			MyGame::restart(void)
{
  this->_state = MyGame::GAME;
  this->initCam();
  this->setMap(new Map(*(this->_contentGame.getMap())));
  this->reset();
  this->_haveWinner = false;

  std::vector<std::string> const players = this->_contentGame.getPlayers();
  if (players.size() == 1)
    this->_players.RealsPlayers(players[0], "", this->_map);
  else if (players.size() == 2)
    this->_players.RealsPlayers(players[0], players[1], this->_map);
  if (this->_contentGame.getNbIA())
    this->_players.putSomeBots(this->_contentGame.getNbIA(), this->_map, this->_bombs);
}

void			MyGame::newPart(void)
{
  this->_contentGame.reset();
  this->_contentGame.setMap(*(this->_map));
  this->_contentGame.setNbIA(this->_players.getNbIA());
  this->_contentGame.setPlayers(this->_players.getHumans());
  this->_haveWinner = false;
}

void			MyGame::setMap(Map* map)
{
  this->_haveWinner = false;
  this->_map = map;
  this->_contentGame.setMap(*map);
  this->_mapGraph.newMap(map);
  this->_camera.centerToMap(map, this->gameClock_.getTotalGameTime());
}

void			MyGame::unload(void)
{
}

void			MyGame::initCam(void)
{
  this->_camera.init();
}

void			MyGame::saveGame(void)
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  strftime (buffer,80,"%Y-%m-%d_%Hh%Mm%Ss",timeinfo);
  std::stringstream	ss("");
  ss << Config::BackupsDirectory << "/" << buffer << Config::DefaultBackupExtension;
  std::ofstream		file(ss.str().c_str(), std::ios_base::out | std::ios_base::trunc);
  file << this->_contentGame.serialize();
}

void			MyGame::loadGame(const std::string &file)
{
  std::stringstream	ss("");
  ss << Config::BackupsDirectory << "/" << file << Config::DefaultBackupExtension;
  this->_contentGame.unserialize(ss.str());
  this->restart();
}

void			MyGame::setMenu(Menu::IMenu *m)
{
  delete this->_menu;
  this->_menu = m;
  this->_menu->init(this->window_);
}
