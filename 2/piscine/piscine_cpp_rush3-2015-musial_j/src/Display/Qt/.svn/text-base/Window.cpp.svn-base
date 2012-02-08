//
// Window.cpp for Qt in /home/hervet_g/rush/rush3/mygkrellm/src/Display/Qt
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Sat Jan 21 18:25:31 2012 geoffrey hervet
// Last update Sat Jan 21 18:25:31 2012 geoffrey hervet
//

#include	<iostream>
#include	<algorithm>
#include	<sstream>

#include	"IMonitorModule.h"

#include	"Window.h"

Window::Window(ModulesController *mc)
  : QMainWindow(), _mc(mc)
{
  PRINT_TRACE();

  this->setWindowTitle("Monitor MyGKrellM ** Rush C++ with Qt");

  QWidget	*content = new QWidget;
  this->setCentralWidget(content);
  //this->centralWidget();

  QMenu		*menuFile = this->menuBar()->addMenu("&File");
  QAction	*quit     = new QAction("&Quit", this);

  quit->setIcon(QIcon("./img/door_out.png"));
  menuFile->addAction(quit);

  connect(quit, SIGNAL(triggered()), this, SLOT(quit()));

  QVBoxLayout	*layout = new QVBoxLayout;

  int	height = 100;
  int	width = 300;

  this->_cores = std::vector<QProgressBar*>(8);

  if (this->getController()->getModule(MOD_TIMEINFO) != NULL)
  {
    this->_widgs["TIME"] = new QLabel;
    layout->addWidget(this->_widgs["TIME"]);
    height += 20;
  }

  if (this->getController()->getModule(MOD_COMPUTER) != NULL)
  {
    this->_widgs["COMPUTER"] = new QLabel;
    layout->addWidget(this->_widgs["COMPUTER"]);
    height += 100;
  }

  if (this->getController()->getModule(MOD_OS) != NULL)
  {
    this->_widgs["OS"] = new QLabel;
    layout->addWidget(this->_widgs["OS"]);
    height += 20;
  }

  if (this->getController()->getModule(MOD_UPTIME))
  {
    this->_widgs["UPT"] = new QLabel;
    layout->addWidget(this->_widgs["UPT"]);
    height += 20;
  }

  if (this->getController()->getModule(MOD_LOADAVG) != NULL)
  {
    this->_widgs["LOAD"] = new QLabel;
    layout->addWidget(this->_widgs["LOAD"]);
    height += 20;
  }

  if (this->getController()->getModule(MOD_NETWORK) != NULL)
  {
    this->_widgs["NET"] = new QLabel;
    layout->addWidget(this->_widgs["NET"]);
    height += 20;
  }

  if (this->getController()->getModule(MOD_CPU) != NULL)
  {
    this->_widgs["CPU"] = new QWidget;

    QLabel  *label_img  = new QLabel("CPU Cores", this);
    QPixmap *pixmap_img = new QPixmap("img/proc.png");
    label_img->setPixmap(*pixmap_img);

//    QGridLayout *gridLayout = new QGridLayout;
 //   gridLayout->addWidget(label_img);
  //  setLayout(gridLayout);

    layout->addWidget(label_img);

    layout->addWidget(this->_widgs["CPU"]);

    IMonitorModule* tmp = this->getController()->getModule(MOD_CPU);
    tmp->updateInfo();
    std::map<std::string, float> test = (dynamic_cast<Mod::CPU*>(tmp))->getActivity();
    int	i = 0;
    for (std::map<std::string, float>::iterator it = test.begin(); it != test.end(); ++it)
      layout->addWidget(this->_cores[i++] = new QProgressBar());
    height += 180;
  }

  if (this->getController()->getModule(MOD_RAM) != NULL)
  {
    QLabel  *label_img  = new QLabel("RAM", this);
    QPixmap *pixmap_img = new QPixmap("img/Memory.png");
    label_img->setPixmap(*pixmap_img);
    layout->addWidget(label_img);

    this->_widgs["RAM"] = new QProgressBar;
    layout->addWidget(this->_widgs["RAM"]);
    height += 50;
  }


  if (this->getController()->getModule(MOD_SWAP) != NULL)
  {
    QLabel  *label_img  = new QLabel("SWAO", this);
    QPixmap *pixmap_img = new QPixmap("img/Swap.png");
    label_img->setPixmap(*pixmap_img);
    layout->addWidget(label_img);
    this->_widgs["SWAP"] = new QProgressBar;
    layout->addWidget(this->_widgs["SWAP"]);
    height += 50;
  }

  content->setLayout(layout);

  this->setFixedSize(width, height);
  this->_timer = new QTimer();
  this->_timer->setInterval(500);
  this->_timer->start();
  connect(this->_timer, SIGNAL(timeout()), this, SLOT(run()));
}

void		Window::run()
{
  PRINT_TRACE();
  IMonitorModule* tmp;
  std::string display;

  if ((tmp = this->getController()->getModule(MOD_COMPUTER)) != NULL)
  {
    tmp->updateInfo();
    dynamic_cast<QLabel*>(this->_widgs["COMPUTER"])->setText((dynamic_cast<Mod::Computer*>(tmp))->getComputerName().c_str());
  }

  if ((tmp = this->getController()->getModule(MOD_OS)) != NULL)
  {
    tmp->updateInfo();
    display = (dynamic_cast<Mod::OS*>(tmp))->getOSType();
    display += ((dynamic_cast<Mod::OS*>(tmp))->is64b() ? " x64" : " x32");
    display += (dynamic_cast<Mod::OS*>(tmp))->getOSRelease();
    display += "\n" + (dynamic_cast<Mod::OS*>(tmp))->getKernelVersion();
    dynamic_cast<QLabel*>(this->_widgs["OS"])->setText(display.c_str());
  }

  //TimeInfo
  if ((tmp = this->getController()->getModule(MOD_TIMEINFO)) != NULL)
  {
    tmp->updateInfo();
    display = (dynamic_cast<Mod::TimeInfo*>(tmp))->getDate();
    display += " " + (dynamic_cast<Mod::TimeInfo*>(tmp))->getHour();

    dynamic_cast<QLabel*>(this->_widgs["TIME"])->setText(display.c_str());
  }

  if ((tmp = this->getController()->getModule(MOD_RAM)) != NULL)
  {
    tmp->updateInfo();

    std::ostringstream ss;
    ss << std::flush << "RAM: " << ((dynamic_cast<Mod::RAM*>(tmp))->getUsedRam()) << "/" <<  ((dynamic_cast<Mod::RAM*>(tmp))->getTotalRam()) << "MB";
    display = ss.str();
    dynamic_cast<QProgressBar*>(this->_widgs["RAM"])->setValue((dynamic_cast<Mod::RAM*>(tmp))->getPercentRam());
  }

  if ((tmp = this->getController()->getModule(MOD_SWAP)) != NULL)
    {
      tmp->updateInfo();
      dynamic_cast<QProgressBar*>(this->_widgs["SWAP"])->setValue ((dynamic_cast<Mod::Swap*>(tmp))->getData().getPercent());
    }

  if ((tmp = this->getController()->getModule(MOD_CPU)) != NULL)
  {
    tmp->updateInfo();

    int		idx = 0;
    std::map<std::string, float> test = (dynamic_cast<Mod::CPU*>(tmp))->getActivity();
    for (std::map<std::string, float>::iterator it = test.begin(); it != test.end(); ++it)
      this->_cores[idx++]->setValue((int)((*it).second));
  }

  if ((tmp = this->getController()->getModule(MOD_LOADAVG)) != NULL)
  {
    tmp->updateInfo();

    std::ostringstream ss;
    ss << std::flush << "Load average: " << (dynamic_cast<Mod::LoadAvg*>(tmp))->getLoadAvg();
    display = ss.str();
    dynamic_cast<QLabel*>(this->_widgs["LOAD"])->setText(display.c_str());
  }

  if ((tmp = this->getController()->getModule(MOD_NETWORK)) != NULL)
    {
      tmp->updateInfo();

      std::ostringstream ss;
      ss << std::flush << "Network: ";
      std::map<std::string, netPackets> test = (dynamic_cast<Mod::Network*>(tmp))->getPackets();
      for (std::map<std::string, netPackets>::iterator it = test.begin(); it != test.end(); ++it)
        ss << "\n" << (*it).first << "\t- Transmit: " <<  (*it).second.transmit <<  "\n\t- Receive: " <<  (*it).second.receive;
      ss << "\n\n";
      display = ss.str();
      dynamic_cast<QLabel*>(this->_widgs["NET"])->setText(display.c_str());
    }

  if ((tmp = this->getController()->getModule(MOD_UPTIME)) != NULL)
    {
      tmp->updateInfo();

      display = "Uptime: " +  (dynamic_cast<Mod::Uptime*>(tmp))->getUptime();
      dynamic_cast<QLabel*>(this->_widgs["UPT"])->setText(display.c_str());
    }


}

void		Window::pushTimeline(std::string const &key, unsigned int data)
{
  PRINT_TRACE();
  if (data)
    (void)key;
}
