#include	<algorithm>
#include	<iostream>
#include	"Error.hpp"
#include	"MyGame.hpp"
#include	"Bombs.hpp"
#include	"MapGraph.hpp"

Bombs::Bombs() : _sm(0)
{
}

void		Bombs::putBomb(MapGraph& map, Player& player, double timeCurr, double duration)
{
  Bomb*		b;

  if (!player.getAmmo() ||
      getBomb(player.getX(), player.getY()))
    return;
  b = new Bomb;
  b->x = player.getX();
  b->y = player.getY();
  player.decrAmmo();
  b->player = &player;
  b->power = player.getPower();
  b->exploding = 0;
  b->timePrev = 0;
  b->timeToExplode = timeCurr + duration;
  b->timeLeft = duration;
  b->dir[0] = true;
  b->dir[1] = true;
  b->dir[2] = true;
  b->dir[3] = true;
  _bombs.push_back(b);
  map.putBomb(b, timeCurr, duration);
}

Bombs::Bomb*	Bombs::getBomb(unsigned x, unsigned y)
{
  std::list<Bomb*>::iterator	it = _bombs.begin();

  for (; it != _bombs.end(); ++it)
    if ((*it)->x == x && (*it)->y == y)
      return *it;
  return NULL;
}

void		Bombs::killPlayer(MyGame& game, Bomb* , unsigned x, unsigned y)
{
  Player*	p;

  if (!(p = game.getPlayers().getPlayer(x, y)))
    return;
  p->kill(game.totalTime());
  if (this->_sm)
  {
    try { this->_sm->playSound("./res/sounds/death.wav", 0, 100); }
    catch (const ::Error &e) { std::cerr << "[" << e.level() << "]" << e.what() << std::endl; }
  }
}

void		Bombs::propagateBomb(MyGame& game, Bomb* b)
{
  for (unsigned u = 0; u < 4; ++u)
    if (b->dir[u])
      {
	int x = b->x + (u == 1 ? b->exploding : u == 3 ? -b->exploding : 0);
	int y = b->y + (u == 0 ? b->exploding : u == 2 ? -b->exploding : 0);
	Map::eMap cell = game.getMap()->getCase(x, y);
	if (cell != Map::GROUND)
	  b->dir[u] = false;
	if (cell != Map::UNKNOWN && cell != Map::WALL)
	  {
	    if (cell == Map::BOMB)
	      getBomb(x, y)->timeToExplode = 0;
	    else
	      {
		killPlayer(game, b, x, y);
		game.getMapGraph().putGround(x, y, game.totalTime());
		game.getBlasts().newBlast(x, y, game.totalTime());
		game.getCamera().shake(.05);
	      }
	  }
      }
}

void		Bombs::wait(double t)
{
  std::for_each(this->_bombs.begin(), this->_bombs.end(), Bombs::Waiter(t));
}

void		Bombs::update(MyGame& game)
{
  std::list<Bomb*>::iterator	it = _bombs.begin();
  double	time = game.totalTime();

  for (; it != _bombs.end(); ++it)
    {
      Bomb* b = *it;
      b->timeLeft = b->timeToExplode - time;
      if (b->timeToExplode < time && b->timePrev + .07 < time)
	{
	  b->timePrev = time;
	  if (b->exploding)
	    propagateBomb(game, b);
	  else
	    {
              if (game.getSoundManager())
		{
		  try { game.getSoundManager()->playSound("./res/sounds/boom.mp3", 0, 100); }
		  catch (const ::Error &e) { if (e.level() == Error::CRITICAL) throw; std::cerr << "[" << e.level() << "] " << e.what() << std::endl; }
		}
	      killPlayer(game, b, b->x, b->y);
	      b->player->incrAmmo();
	      game.getPlayers().getPlayer(b->x, b->y);
	      game.getBlasts().newBlast(b->x, b->y, time);
	      game.getCamera().shake(.05);
	    }
	  if (++b->exploding > b->power)
	    {
	      it = _bombs.erase(it);
	      game.getMapGraph().putGround(b->x, b->y, time);
	    }
	}
    }
}
