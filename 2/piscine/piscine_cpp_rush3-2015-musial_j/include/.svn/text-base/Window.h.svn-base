/*
** Window.h for include in /home/hervet_g/rush/rush3/mygkrellm/include
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 21 18:21:26 2012 geoffrey hervet
** Last update Sat Jan 21 18:21:26 2012 geoffrey hervet
*/

#ifndef   __WINDOW_H__
# define  __WINDOW_H__

# include	<QApplication>
# include	<QtGui>
# include	<iostream>
# include	<map>
# include	<string>
# include	<unistd.h>

# include	"Trace.h"
# include	"ModulesController.h"

class		Window
 : public	  QMainWindow
{
    Q_OBJECT

    ModulesController	*_mc;
    QTimer	*_timer;
    std::map<std::string, QWidget*>	_widgs;
    std::vector<QProgressBar*>		_cores;

  public:
    Window(ModulesController *);

    void	pushTimeline(std::string const &, unsigned int data);

    ModulesController	*getController() { return this->_mc; };


  public slots:
    void	run();
    void	quit(){exit(0);};
};

#endif     /* !__WINDOW_H__ */
