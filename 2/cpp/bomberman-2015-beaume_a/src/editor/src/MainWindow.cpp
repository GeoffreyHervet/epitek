#include	"MainWindow.hpp"
#include	"NewFileDialog.hpp"

MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags)
  : QMainWindow(parent, flags),
    _menuFile(0),
    _actNew(0),
    _actSaveAs(0),
    _actExit(0),
    _document(0)
{
  this->setWindowTitle("Map editor for Bomberman by <Team Metapod>");
  this->setUnifiedTitleAndToolBarOnMac(true);
  this->resize(800, 600);
  this->move((QApplication::desktop()->width() - this->width()) / 2,
              (QApplication::desktop()->height() - this->height()) / 2);

  this->createActions();
  this->createMenus();

  this->setCentralWidget(0);
}

void		MainWindow::createActions()
{
  this->_actNew = new QAction("New", this);
  connect(this->_actNew, SIGNAL(triggered()), this, SLOT(newFile()));
  this->_actSaveAs = new QAction("Save As", this);
  connect(this->_actSaveAs, SIGNAL(triggered()), this, SLOT(saveAsFile()));
  this->_actClose = new QAction("Close", this);
  connect(this->_actClose, SIGNAL(triggered()), this, SLOT(closeFile()));
  this->_actExit = new QAction("Quit", this);
  connect(this->_actExit, SIGNAL(triggered()), this, SLOT(close()));
}

void		MainWindow::createMenus()
{
  this->_menuFile = this->menuBar()->addMenu("File");
  this->_menuFile->addAction(this->_actNew);
  this->_menuFile->addAction(this->_actSaveAs);
  this->_menuFile->addAction(this->_actClose);
  this->_menuFile->addSeparator();
  this->_menuFile->addAction(this->_actExit);
}

void		MainWindow::newFile()
{
  if (this->_document == 0)
    {
      NewFileDialog d;
      if (d.exec() == QDialog::Accepted)
        {
          this->_document = new Document(d.getWidth(), d.getHeight(), this);
          this->setCentralWidget(this->_document);
        }
    }
  else
    QMessageBox::warning(this, "Error", "Please close the current document");
}

void		MainWindow::closeFile()
{
  if (this->_document == 0)
    QMessageBox::warning(this, "Error", "No opened document to close");
  else
    {
      delete this->_document;
      this->_document = 0;
    }
}

void		MainWindow::saveAsFile()
{
  if (this->_document == 0)
    QMessageBox::warning(this, "Error", "No opened document to save as");
  else
    {
      QString fileName = QFileDialog::getSaveFileName(this);
      if (fileName.isEmpty())
        return ;

      QFile file(fileName);
      if (!file.open(QFile::WriteOnly | QFile::Text))
      {
        QMessageBox::warning(this, "Error", QString("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
        return ;
      }

      MapView::Map const& map = this->_document->getMap();
      QTextStream out(&file);
      QApplication::setOverrideCursor(Qt::WaitCursor);
      out << this->_document->getMapWidth() << endl;
      out << this->_document->getMapHeight() << endl;
      Q_FOREACH(MapView::Line line, map)
        {
          Q_FOREACH(MapView::Cell cell, line)
            out << cell;
          out << endl;
        }
      out << endl;
      QApplication::restoreOverrideCursor();
    }
}
