/*
** Skat.h for ex00 in /home/hervet_g/piscine/piscine_cpp_d07a-2015-hervet_g/ex00
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Jan 10 17:20:30 2012 geoffrey hervet
** Last update Tue Jan 10 17:20:30 2012 geoffrey hervet
*/

#ifndef   __SKAT_H__
# define  __SKAT_H__

# include	<string>

class Skat
{
  std::string const	_name;
  int			_stimPaks;

  public:
    Skat(const std::string & name = "bob", int stimPaks = 15);
    ~Skat();
    int&		stimPaks();
    const		std::string& name(void) const;
    void		shareStimPaks(int number, int &stock);
    void		addStimPaks(unsigned int number);
    void		useStimPaks(void);
    void		status(void);

};

#endif     /* !__SKAT_H__ */
