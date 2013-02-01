#include <iostream>
#include <QApplication>
#include <QtGui>
#include <map>
#include <string>
#include <deque>

#include "IGraphic.h"

#define SQUARE_SIZE (this->_squareSize)

class	QtDisplay
  : public QMainWindow,
    public Nibbler::IGraphic
{
    bool			_haveLastPos;
    unsigned char		_width;
    unsigned char		_height;
    Nibbler::eEvent		_direction;
    QApplication		*_app;
    QGraphicsView		*_view;
    QGraphicsTextItem		*_score;
    QGraphicsScene		*_scene;
    std::deque<Nibbler::eEvent> _lastEvent;
    std::map<Qt::Key, Nibbler::eEvent> _event;
    std::pair<unsigned char, unsigned char> _lastPosQ;
    unsigned int		_squareSize;

    QtDisplay(const QtDisplay &);
    QtDisplay &operator =(const QtDisplay &);
   
  public:
    QtDisplay(unsigned char, unsigned char);
    virtual ~QtDisplay();
    bool eventFilter(QObject *object, QEvent *event);
    void keyPressEvent(QKeyEvent *event);

    Nibbler::eEvent	getEvent(void);
    bool		displaySnake(std::deque<std::pair<unsigned char,unsigned char> > const &, Nibbler::eEvent);
    bool		displayMap(const std::vector<std::vector<bool> > &);

    bool		reset_queue(unsigned char, unsigned char) { return true; };
    bool		displayFood(const std::vector<Nibbler::tFood>&);
    bool		displayScore(unsigned int s);

    void		setApp(QApplication *a){this->_app = a;};

  protected:
    void		initEvents(void);
    void		initWindow(void);
    void		initScene(void);
}; 
