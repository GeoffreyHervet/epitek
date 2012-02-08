#include <ncurses.h>
#include <string>
#include <sys/time.h>
#include <algorithm>
#include <vector>
#include <map>
#include "Trace.h"
#include <iostream>
#include "NCursesDisplay.h"
#include "CPU.h"
#include "Network.h"
#include "Uptime.h"

NCursesDisplay::NCursesDisplay()
{
  PRINT_TRACE();

  initscr();
  cbreak();

  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);

  this->window = newwin(20/*SAME*/, 60/*this->getController()->countActivated() * 4*/, 0, 0);

  noecho();
  nodelay(this->window, TRUE);
  keypad(this->window, TRUE);
}

NCursesDisplay::~NCursesDisplay()
{
  PRINT_TRACE();

  box(this->window, ' ', ' ');
  werase(this->window);
  wrefresh(this->window);
  delwin(this->window);
}

void NCursesDisplay::setModulesController(ModulesController* var)
{
  PRINT_TRACE();

  this->_modulesController = var;
}

ModulesController* NCursesDisplay::getController()
{
  PRINT_TRACE();

  return (this->_modulesController);
}

int NCursesDisplay::getColorCPU(unsigned int percent)
{
  PRINT_TRACE();

  if (percent < 20)
    return (1);
  else if (percent < 50)
    return (2);
  else
    return (3);
}


int NCursesDisplay::getColor(unsigned int percent)
{
  PRINT_TRACE();

  if (percent < 50)
    return (1);
  else if (percent < 75)
    return (2);
  else
    return (3);
}

void NCursesDisplay::refresh_stats()
{
  PRINT_TRACE();

  IMonitorModule* tmp;

  this->line = 2;

  box(this->window, 0, 0);

  mvwprintw(this->window, 14, 51, "  ___  ");
  mvwprintw(this->window, 15, 51, "{~+_+~}");
  mvwprintw(this->window, 16, 51, " ( Y ) ");
  mvwprintw(this->window, 17, 51, "()~*~()");
  mvwprintw(this->window, 18, 51, "(_)-(_) ");
  //COMPUTER
  if ((tmp = this->getController()->getModule(MOD_COMPUTER)) != NULL)
    {
      mvwprintw(this->window, 0, 2, " %s (%s) ", ((dynamic_cast<Mod::Computer*>(tmp))->getComputerName()).c_str(), ((dynamic_cast<Mod::Computer*>(tmp))->getUserName()).c_str());
    }

  //OS
  if ((tmp = this->getController()->getModule(MOD_OS)) != NULL)
    {

      mvwprintw(this->window, this->line++, 2, "%s (%s) - %s", ((dynamic_cast<Mod::OS*>(tmp))->getOSType()).c_str(), ((dynamic_cast<Mod::OS*>(tmp))->is64b() ? "x64" : "x32"), ((dynamic_cast<Mod::OS*>(tmp))->getOSRelease()).c_str());
      mvwprintw(this->window, this->line++, 2, "Kernel: %s", ((dynamic_cast<Mod::OS*>(tmp))->getKernelVersion()).c_str());
    }


  //LOADAVG
  if ((tmp = this->getController()->getModule(MOD_LOADAVG)) != NULL)
    {
      tmp->updateInfo();

      mvwprintw(this->window, 8, 25, "Load average: %s", ((dynamic_cast<Mod::LoadAvg*>(tmp))->getLoadAvg()).c_str());
    }

  //UPTIME
  if ((tmp = this->getController()->getModule(MOD_UPTIME)) != NULL)
    {
      tmp->updateInfo();

      mvwprintw(this->window, 6, 25, "Uptime: %s", ((dynamic_cast<Mod::Uptime*>(tmp))->getUptime()).c_str());
    }

  //NETWORK
  if ((tmp = this->getController()->getModule(MOD_NETWORK)) != NULL)
    {
      tmp->updateInfo();

      std::map<std::string, netPackets> test = (dynamic_cast<Mod::Network*>(tmp))->getPackets();

      mvwprintw(this->window, 11, 25, "NETWORK:");
      int line = 12;
      for (std::map<std::string, netPackets>::iterator it = test.begin(); it != test.end(); ++it)
      	{
      	  mvwprintw(this->window, line, 27, "%s : ", (*it).first.c_str());
      	  mvwprintw(this->window, line, 33, "Transmit: %d", (*it).second.transmit);
	  ++line;
      	  mvwprintw(this->window, line, 33, "Receive: %d", (*it).second.receive);
	  ++line;
      	}
    }

  //TimeInfo
  if ((tmp = this->getController()->getModule(MOD_TIMEINFO)) != NULL)
    {
      tmp->updateInfo();
      mvwprintw(this->window, this->line, 2, "%s %s", ((dynamic_cast<Mod::TimeInfo*>(tmp))->getDate()).c_str(), ((dynamic_cast<Mod::TimeInfo*>(tmp))->getHour()).c_str());
      this->line += 2;
    }

  //CPU
  if ((tmp = this->getController()->getModule(MOD_CPU)) != NULL)
    {
      tmp->updateInfo();

      std::map<std::string, float> test = (dynamic_cast<Mod::CPU*>(tmp))->getActivity();

      for (std::map<std::string, float>::iterator it = test.begin(); it != test.end(); ++it)
	{
	  mvwprintw(this->window, this->line, 2, "%-5s [", (*it).first.c_str());

	  wattron(this->window, COLOR_PAIR(this->getColorCPU((unsigned int)((*it).second))));
	  mvwprintw(this->window, this->line, 9, "%f", (*it).second);
	  wattroff(this->window, COLOR_PAIR(this->getColorCPU((unsigned int)((*it).second))));
	  mvwprintw(this->window, this->line, 19, "\%]");
	  this->line++;
	}

      this->line += 2;
    }

  //RAM
  if ((tmp = this->getController()->getModule(MOD_RAM)) != NULL)
    {
      tmp->updateInfo();
      mvwprintw(this->window, this->line++, 2, "RAM: %d/%d MB", ((dynamic_cast<Mod::RAM*>(tmp))->getUsedRam()), ((dynamic_cast<Mod::RAM*>(tmp))->getTotalRam()));
      mvwprintw(this->window, this->line, 2, "[");
      wattron(this->window, COLOR_PAIR(this->getColor(((dynamic_cast<Mod::RAM*>(tmp))->getPercentRam()))));

      unsigned int tmp_ram = ((dynamic_cast<Mod::RAM*>(tmp))->getPercentRam()) / 10;
      unsigned int ram_incre = 0;

      while (ram_incre < tmp_ram)
	{
	  mvwprintw(this->window, this->line, 3 + ram_incre, "|");
	  ++ram_incre;
	}
      wattroff(this->window, COLOR_PAIR(this->getColor(((dynamic_cast<Mod::RAM*>(tmp))->getPercentRam()))));
      mvwprintw(this->window, this->line, 12, "]");
      wattron(this->window, COLOR_PAIR(this->getColor(((dynamic_cast<Mod::RAM*>(tmp))->getPercentRam()))));
      mvwprintw(this->window, this->line, 14, "%d%%", ((dynamic_cast<Mod::RAM*>(tmp))->getPercentRam()));
      wattroff(this->window, COLOR_PAIR(this->getColor(((dynamic_cast<Mod::RAM*>(tmp))->getPercentRam()))));
      this->line += 2;
    }

  //SWAP
  if ((tmp = this->getController()->getModule(MOD_SWAP)) != NULL)
    {
      tmp->updateInfo();
      mvwprintw(this->window, this->line++, 2, "SWAP: %d/%d MB", ((dynamic_cast<Mod::Swap*>(tmp))->getData().getUsed()), ((dynamic_cast<Mod::Swap*>(tmp))->getData().getTotal()));
      mvwprintw(this->window, this->line, 2, "[");
      wattron(this->window, COLOR_PAIR(this->getColor(((dynamic_cast<Mod::Swap*>(tmp))->getData().getPercent()))));

      unsigned int tmp_swap = ((dynamic_cast<Mod::Swap*>(tmp))->getData().getPercent()) / 10;
      unsigned int swap_incre = 0;

      while (swap_incre < tmp_swap)
        {
          mvwprintw(this->window, this->line, 3 + swap_incre, "|");
          ++swap_incre;
        }
      wattroff(this->window, COLOR_PAIR(this->getColor(((dynamic_cast<Mod::Swap*>(tmp))->getData().getPercent()))));
      mvwprintw(this->window, this->line, 12, "]");
      wattron(this->window, COLOR_PAIR(this->getColor(((dynamic_cast<Mod::Swap*>(tmp))->getData().getPercent()))));
      mvwprintw(this->window, this->line, 14, "%d%%", ((dynamic_cast<Mod::Swap*>(tmp))->getData().getPercent()));
      wattroff(this->window, COLOR_PAIR(this->getColor(((dynamic_cast<Mod::Swap*>(tmp))->getData().getPercent()))));
      this->line += 2;
    }

  wrefresh(this->window);
}

void NCursesDisplay::run()
{
  PRINT_TRACE();

  int c = 0;
  timeval t1, t2;
  double elapsedTime;

  t1.tv_sec = 0;
  t1.tv_usec = 0;

  while (c != 265)
    {
      gettimeofday(&t2, NULL);
      elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
      elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

      c = wgetch(this->window);
      if (c == 114 || elapsedTime > 500)
	{
	  gettimeofday(&t1, NULL);
	  werase(this->window);
	  this->refresh_stats();
	}
      else if (c == 265)
	delete (this);
      usleep(500);
    }
}
