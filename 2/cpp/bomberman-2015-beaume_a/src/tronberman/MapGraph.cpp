# include		"MapGraph.hpp"

MapGraph::MapGraph(void)
{
  _map = NULL;
  _tex[Map::GROUND] = gdl::Image::load("res/img/map/ground.bmp");
  _tex[Map::BOX] = gdl::Image::load("res/img/map/box.bmp");
  _tex[Map::WALL] = gdl::Image::load("res/img/map/wall.bmp");

  _tex[Map::BOMB] = gdl::Image::load("res/img/map/bomb0.bmp");
  _tex[Map::BOMB2] = gdl::Image::load("res/img/map/bomb1.bmp");
  _tex[Map::BOMB3] = gdl::Image::load("res/img/map/bomb2.bmp");
  _tex[Map::BOMB4] = gdl::Image::load("res/img/map/bomb3.bmp");
  _tex[Map::BOMB5] = gdl::Image::load("res/img/map/bomb4.bmp");
  _tex[Map::LAST_BOMB] = gdl::Image::load("res/img/map/bomb5.bmp");

  _tex[Map::SLOWER] = gdl::Image::load("res/img/map/slower.bmp");
  _tex[Map::DECR_BOMBS] = gdl::Image::load("res/img/map/decrbombs.bmp");
  _tex[Map::INCR_BOMBS] = gdl::Image::load("res/img/map/incrbombs.bmp");
  _tex[Map::DECR_POWER] = gdl::Image::load("res/img/map/decrpower.bmp");
  _tex[Map::INCR_POWER] = gdl::Image::load("res/img/map/incrpower.bmp");
  _tex[Map::FASTER] = gdl::Image::load("res/img/map/faster.bmp");
}

Map const*		MapGraph::getMap(void) const
{
  return this->_map;
}

Cube const*		MapGraph::getCube(unsigned x, unsigned y) const
{
  if (x >= this->_map->getW() || y >= this->_map->getH())
    return NULL;
  return &this->_tab[y][x];
}

void			MapGraph::newMap(Map* map)
{
  unsigned		x, y;

  this->_map = map;
  this->_time = 0;
  this->_opening_h = map->getH();
  this->_objs = new Cube[map->getH() * map->getW()];
  this->_tab = new Cube*[map->getH()];
  for (y = 0; y < map->getH(); ++y)
    this->_tab[y] = this->_objs + map->getW() * y;
  for (y = 0; y < map->getH(); ++y)
    for (x = 0; x < map->getW(); ++x)
      {
	this->_tab[y][x].setTex(this->_tex + Map::GROUND);
	this->_tab[y][x].setPos(x, y);
      }
}

void			MapGraph::update(gdl::GameClock const& clock, gdl::Input& input)
{
  unsigned		x, y;

  if (!this->_map)
    return;
  if (this->_opening_h > 0 &&
      clock.getTotalGameTime() - this->_time > 1. / this->_map->getH())
    this->opening(clock.getTotalGameTime());
  for (y = 0; y < this->_map->getH(); ++y)
    for (x = 0; x < this->_map->getW(); ++x)
      {
	if (this->_tab[y][x].getScaleZ() > .8)
	  this->_tab[y][x].setTex(this->_tex + this->_map->getCase(x, y));
	this->_tab[y][x].update(clock, input);
      }
}

void			MapGraph::draw(void) const
{
  if (!this->_map)
    return;
  int i = this->_map->getW() * this->_map->getH() - 1;
  for (; i >= 0; --i)
    this->_objs[i].draw();
}

void			MapGraph::putBomb(Bombs::Bomb* b, double timeCurr, double duration)
{
  unsigned		u = Map::BOMB + (b->power - 1) / 2;

  if (u > Map::LAST_BOMB)
    u = Map::LAST_BOMB;
  this->_map->setCase(b->x, b->y, Map::BOMB);
  this->_tab[b->y][b->x].setTex(this->_tex + u);
  this->_tab[b->y][b->x].setScale(1, timeCurr, duration);
}

void			MapGraph::putGround(unsigned x, unsigned y, double timeCurr)
{
  Map::eMap		e;

  if (this->_map->getCase(x, y) != Map::GROUND)
    {
      e = static_cast<Map::eMap>(rand() % 2 ? Map::GROUND : Map::SLOWER + rand() % Map::NB_BONUS);
      this->_map->setCase(x, y, e);
      this->_tab[y][x].setTex(this->_tex + e);
      this->_tab[y][x].setScale(.1, timeCurr, .7);
    }
}

void			MapGraph::opening(double time)
{
  int x = this->_map->getW() - 1;

  for (; x >= 0; --x)
    {
      this->_tab[this->_opening_h - 1][x].setRotZ(0, time);
      this->_tab[this->_opening_h - 1][x].setScale(this->_map->getCase(x, this->_opening_h - 1) == Map::GROUND ? .1 : 1., time, 1);
    }
  --this->_opening_h;
  this->_time = time;
}
