#include	<GL/gl.h>
#include	<GL/freeglut.h>
#include	<iostream>
#include	<sstream>
#include	<stdexcept>

#include	"OpenGLObject.h"

std::map<unsigned char, Nibbler::eEvent>	OpenGLObject::_keyMove;
Nibbler::eEvent					OpenGLObject::_event;

OpenGLObject::OpenGLObject(int argc, char **argv, int winHeight, int winWidth)
  : _sizeCase(20), _winHeight(winHeight * _sizeCase), _winWidth(winWidth * _sizeCase)
{
  glutInit(&argc, argv);
  glutInitWindowPosition(200, 200);
  glutInitWindowSize(_winHeight, _winWidth);
  if (!glutCreateWindow("Nibbler"))
    throw std::runtime_error("glut error : Can't create window.");
  glViewport(0, 0, _winHeight, _winWidth);
  _window = glutGetWindow();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glutSpecialFunc(OpenGLObject::keyMoves);
  glutKeyboardFunc(OpenGLObject::keyOthersEvents);

  _originX = -1.f;
  _originY = 1.f;

  _keyMove[GLUT_KEY_LEFT] = Nibbler::MV_LEFT;
  _keyMove[GLUT_KEY_RIGHT] = Nibbler::MV_RIGHT;
  _keyMove[GLUT_KEY_UP] = Nibbler::MV_UP;
  _keyMove[GLUT_KEY_DOWN] = Nibbler::MV_DOWN;
  _keyMove[SPACE] = Nibbler::PAUSE;
  _keyMove[ESCAPE] = Nibbler::EXIT;

  _event = Nibbler::UNKNOWN;
}

OpenGLObject::~OpenGLObject()
{
  glutDestroyWindow(_window);
}

float	OpenGLObject::normalize(float value, float divide) const
{
  return 2.f * value / divide;
}

bool	OpenGLObject::displaySquare(float x, float y) const
{
  glPushMatrix();
  glTranslatef(x, y, 0.f);
  glRectf(0.f, 0.f, normalize(_sizeCase, _winWidth),
	  normalize(_sizeCase, _winHeight));
  glPopMatrix();

  return true;
}

bool	OpenGLObject::displaySnake(std::deque<std::pair<unsigned char,unsigned char> > const& snake, Nibbler::eEvent direction)
{
  (void)direction;

  glColor3f(.52f, .73f, .4f);
  this->displaySquare(_originX + normalize(_sizeCase, _winWidth) * 4.f,
		      _originY - normalize(_sizeCase, _winHeight) * 2.f);

  glColor3f(0.f, .66f, .47f);
  for (unsigned int i = 0; i < snake.size(); ++i)
    this->displaySquare(_originX + normalize(_sizeCase, _winWidth) * snake[i].first,
			_originY - normalize(_sizeCase, _winHeight) * snake[i].second
			- normalize(_sizeCase, _winHeight));
  return true;
}

bool	OpenGLObject::displayMap(std::vector<std::vector<bool> > const& map)
{
  glClearColor(.52f, .73f, .4f, 0.f);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.f, 0.4f, 0.1f);

  for (unsigned int y = 0; y < map.size(); ++y)
    {
      for (unsigned x = 0; x < map[y].size(); ++x)
  	{
	  if (map[y][x])
	    this->displaySquare(_originX + normalize(_sizeCase, _winWidth) * x,
				_originY - normalize(_sizeCase, _winHeight) * y
				- normalize(_sizeCase, _winHeight));
  	}
    }
  return true;
}

void	OpenGLObject::keyMoves(int key, int x, int y)
{
  (void)x;
  (void)y;
  _event = _keyMove[key];
}

void	OpenGLObject::keyOthersEvents(unsigned char key, int x, int y)
{
  (void)x;
  (void)y;
  _event = _keyMove[key];
}

Nibbler::eEvent OpenGLObject::getEvent()
{
  _event = Nibbler::UNKNOWN;
  glutMainLoopEvent();

  return _event;
}

bool OpenGLObject::reset_queue(unsigned char x, unsigned char y)
{
  if (!x && !y)
    return true;

  glColor3f(.52f, .73f, .4f);

  this->displaySquare(_originX + normalize(_sizeCase, _winWidth) * x,
		      _originY - normalize(_sizeCase, _winHeight) * y
		      - normalize(_sizeCase, _winHeight));
  return true;
}

bool OpenGLObject::displayFood(const std::vector<Nibbler::tFood> &food)
{
  glColor3f(0.57f, 0.f, .09f);

  for (unsigned int y = 0; y < food.size(); ++y)
    this->displaySquare(_originX + normalize(_sizeCase, _winWidth) * food[y].x,
			_originY - normalize(_sizeCase, _winHeight) * food[y].y
			- normalize(_sizeCase, _winHeight));

  return true;
}

bool OpenGLObject::displayScore(unsigned int score)
{
  std::ostringstream	os;
  std::string		str("Score: ");

  os << score;
  str += os.str();
  const unsigned char	*text = reinterpret_cast<const unsigned char *>(str.c_str());

  glColor3f(0.f, 0.f, 0.f);
  glRasterPos2f(_originX + normalize(_sizeCase, _winWidth),
		_originY - normalize(_sizeCase, _winHeight) * 2.f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

  glFlush();
  return true;
}

extern	"C"
{
  Nibbler::IGraphic	*ctor(int width, int height, int ac, char **av)
  {
    std::cout << "OK" << std::endl;
    Nibbler::IGraphic *k = new OpenGLObject(ac, av, width, height);
    std::cout << "OK" << std::endl;
    return k;
  }
}
