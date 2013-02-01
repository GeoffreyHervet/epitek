#ifndef		MAINWINDOW_HPP_
# define	MAINWINDOW_HPP_

# include	<QtGui>
# include	"Document.hpp"

class		MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
    MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);

  private slots:
    void	newFile();
    void	closeFile();
    void	saveAsFile();

  private:
    void	createActions();
    void	createMenus();

  private:
    // Menu File
    QMenu *		_menuFile;
    QAction *		_actNew;
    QAction *		_actSaveAs;
    QAction *		_actClose;
    QAction *		_actExit;
    // Central
    Document *		_document;
};

#endif	/*	!MAINWINDOW_HPP_ */
