#include <sstream>
#include <algorithm>

#include "QtDisplay.h"

QtDisplay::QtDisplay(unsigned char w, unsigned char h)
  : QMainWindow(),
    _haveLastPos(false),
    _width(w),
    _height(h),
    _direction(Nibbler::UNKNOWN)
{
  this->initWindow();
  this->initEvents();
  this->initScene();
}

QtDisplay::~QtDisplay()
{
  delete this->_view;
  delete this->_scene;
  delete this->_score;
}

Nibbler::eEvent		QtDisplay::getEvent(void)
{
  if (this->_lastEvent.empty())
    return Nibbler::UNKNOWN;

  Nibbler::eEvent	ret;
  ret = this->_lastEvent.front();
  this->_lastEvent.pop_front();
  return ret;
}

bool	QtDisplay::displayMap(const std::vector<std::vector<bool> > &map)
{
  QPen		pen_bl(Qt::black, 1, Qt::SolidLine);
  QBrush	brush_bl(Qt::black);
  QPen		pen_wh(Qt::white, 1, Qt::SolidLine);
  QBrush	brush_wh(Qt::white);

  unsigned char y = 0;
  for (std::vector<std::vector<bool> >::const_iterator it = map.begin(); it != map.end(); ++it)
  {
    unsigned char x = 0;
    for (std::vector<bool>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
    {
      if (*it2)
        this->_scene->addRect(QRect(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), pen_bl, brush_bl);
      else
        this->_scene->addRect(QRect(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), pen_wh, brush_wh);
      ++x;
    }
    ++y;
  }
  this->_app->processEvents();
  return true;
}

bool			QtDisplay::displaySnake(const std::deque<std::pair<unsigned char,unsigned char> > &snake, Nibbler::eEvent)
{
  QPen			pen(Qt::green, 1, Qt::SolidLine);
  QBrush		brush(Qt::green);

  if (this->_haveLastPos)
  {
    QPen		_pen(Qt::white, 1, Qt::SolidLine);
    QBrush		_brush(Qt::white);

    this->_scene->addRect(QRect(this->_lastPosQ.first * SQUARE_SIZE, this->_lastPosQ.second * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), _pen, _brush);
    this->_scene->addRect(QRect(snake[0].first * SQUARE_SIZE, snake[0].second * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), pen, brush);
    this->_scene->addRect(QRect(snake.back().first * SQUARE_SIZE, snake.back().second * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), pen, brush);
  }
  else
  {
    for (std::deque<std::pair<unsigned char, unsigned char> >::const_iterator it = snake.begin(); it != snake.end(); ++it)
    {
      this->_scene->addRect(QRect((*it).first * SQUARE_SIZE, (*it).second * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), pen, brush);
    }
    this->_haveLastPos = true;
  }

  this->_lastPosQ = snake.back();
  this->_app->processEvents();
  return true;
}

bool QtDisplay::eventFilter(QObject *, QEvent *)
{
  return false;
}

bool			QtDisplay::displayFood(const std::vector<Nibbler::tFood> &food)
{
  QPen			pen(Qt::red, 1, Qt::SolidLine);
  QBrush		brush(Qt::red);

  for (std::vector<Nibbler::tFood>::const_iterator it = food.begin(); it != food.end(); ++it)
    this->_scene->addRect(QRect((*it).x * SQUARE_SIZE, (*it).y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), pen, brush);
  this->_app->processEvents();
  return true;
}

/*
** save the last key wich was pressed
*/

void QtDisplay::keyPressEvent(QKeyEvent *event)
{
  if (this->_event[static_cast<Qt::Key>(event->key())] && !std::count(this->_lastEvent.begin(), this->_lastEvent.end(), event->key()))
    this->_lastEvent.push_back(this->_event[static_cast<Qt::Key>(event->key())]);
}

/*
** INITTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
*/

void		QtDisplay::initEvents(void)
{
  this->_event[Qt::Key_Escape] = Nibbler::EXIT;
  this->_event[Qt::Key_Left] = Nibbler::MV_LEFT;
  this->_event[Qt::Key_Right] = Nibbler::MV_RIGHT;
  this->_event[Qt::Key_Up] = Nibbler::MV_UP;
  this->_event[Qt::Key_Down] = Nibbler::MV_DOWN;
  this->_event[Qt::Key_Space] = Nibbler::PAUSE;
  this->_event[Qt::Key_H] = this->_event[Qt::Key_Left];
  this->_event[Qt::Key_J] = this->_event[Qt::Key_Down];
  this->_event[Qt::Key_K] = this->_event[Qt::Key_Up];
  this->_event[Qt::Key_L] = this->_event[Qt::Key_Right];
  this->_event[Qt::Key_A] = this->_event[Qt::Key_Left];
  this->_event[Qt::Key_S] = this->_event[Qt::Key_Down];
  this->_event[Qt::Key_W] = this->_event[Qt::Key_Up];
  this->_event[Qt::Key_D] = this->_event[Qt::Key_Right];
  this->_event[Qt::Key_Q] = this->_event[Qt::Key_Escape];
  this->_event[Qt::Key_Control] = this->_event[Qt::Key_Escape];
}

void		QtDisplay::initWindow(void)
{
  QDesktopWidget screen;

  this->_squareSize = (800 / this->_width > 600 / this->_height) ? 600 / this->_height : 800 / this->_width;
  if (this->_squareSize > 20)
    this->_squareSize = 20;

  this->setFixedSize(this->_width * SQUARE_SIZE, this->_height * SQUARE_SIZE);
  this->setWindowTitle("Nibbler using Qt");

  /* Center on screen ! */

  QRect		geo = screen.screenGeometry(this);
  int		centerX = geo.center().x();
  int		centerY = geo.center().y();

  this->move(centerX - this->width() / 2, centerY - this->height() / 2);
}


bool		QtDisplay::displayScore(unsigned int s)
{
  std::stringstream	ss;

  ss << s;

  if (this->_score == NULL)
  {
    this->_score = new QGraphicsTextItem();
    this->_scene->addItem(this->_score);
  }
  else
  {
    this->_scene->removeItem(this->_score);
    this->_scene->addItem(this->_score);
  }
  this->_score->setY(SQUARE_SIZE);
  this->_score->setX(SQUARE_SIZE);
  this->_score->setPlainText(QString(ss.str().c_str()));
  this->_score->adjustSize();
  this->_score->setVisible(true);
  this->_score->show();
  this->_score->ensureVisible();
  this->_view->show();
  this->_app->processEvents();
  return true;
}

void		QtDisplay::initScene(void)
{
  this->_scene = new QGraphicsScene(this);
  this->_view = new QGraphicsView(this->_scene,this);
  this->_view->setCacheMode(QGraphicsView::CacheBackground);
  this->_view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  this->_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setCentralWidget(this->_view);
  this->_score = NULL;
}
