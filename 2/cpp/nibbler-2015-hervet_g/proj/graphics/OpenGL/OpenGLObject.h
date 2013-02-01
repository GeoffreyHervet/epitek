#ifndef		OPENGL_OBJECT_H_
# define	OPENGL_OBJECT_H_

#include	<vector>
#include	<deque>
#include	<map>

#include	"../../class/CoreProto.h"
#include	"../../interfaces/IGraphic.h"

class		OpenGLObject : public Nibbler::IGraphic
{
public:
  # define	ESCAPE	27
  # define	SPACE	32

  OpenGLObject(int argc, char **argv, int winWidth = 30, int winHeight = 30);
  virtual ~OpenGLObject();

  virtual bool			displayMap(std::vector<std::vector<bool> > const&);
  virtual bool			displaySnake(std::deque<std::pair<unsigned char,unsigned char> > const&, Nibbler::eEvent);
  virtual Nibbler::eEvent	getEvent();
  virtual bool			reset_queue(unsigned char, unsigned char);
  virtual bool			displayFood(const std::vector<Nibbler::tFood> &);
  virtual bool			displayScore(unsigned int score);

private:
  OpenGLObject();
  OpenGLObject(OpenGLObject const&);
  OpenGLObject&	operator=(OpenGLObject const&);

  float		normalize(float, float) const;
  bool		displaySquare(float, float) const;
  static void	keyMoves(int, int, int);
  static void	keyOthersEvents(unsigned char, int, int);

  float							_sizeCase;
  float							_originX;
  float							_originY;
  float							_winHeight;
  float							_winWidth;
  int							_window;
  static Nibbler::eEvent				_event;
  static std::map<unsigned char, Nibbler::eEvent>	_keyMove;
};

#endif // !OPENGL_OBJECT_H_
