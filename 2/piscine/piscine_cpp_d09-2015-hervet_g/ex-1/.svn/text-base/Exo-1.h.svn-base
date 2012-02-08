/*
** Exo-1.h for ex-1 in /home/hervet_g/piscine/ok/ex-1
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 12 09:46:28 2012 geoffrey hervet
** Last update Thu Jan 12 09:46:28 2012 geoffrey hervet
*/

#ifndef   __EXO1_H__
# define  __EXO1_H__

typedef struct	s_cthulu
{
  int		m_power;
  char		*m_name;

  void		(*PrintPower)(struct s_cthulu *);
  void		(*Attack)(struct s_cthulu *);
  void		(*Sleeping)(struct s_cthulu *);
  /*
   * void (*CthulhuInitializer)(struct s_cthulu *);
   */
}		t_cthulhu;

typedef	struct	s_koala
{
  t_cthulhu	m_parent;
  char		m_isALegend;

  void		(*Eat)(struct s_koala *);
  /*
   * void		(*KoalaInitializer)();
   */
}		t_koala;

t_cthulhu	*NewCthulhu(void);
t_koala		*NewKoala(char *, char);

void	PrintPower(struct s_cthulu *);
void	Attack(struct s_cthulu *);
void	Sleeping(struct s_cthulu *);
void	CthulhuInitializer(struct s_cthulu *);

void	Eat(struct s_koala *);
void	KoalaInitializer(t_koala *, char *, char);

#endif     /* !__EXO-1_H__ */
