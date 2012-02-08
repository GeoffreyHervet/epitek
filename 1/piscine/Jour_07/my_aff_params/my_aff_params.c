/*
** my_aff_params.c for my_aff_params in /home/hervet_g//work/piscine/Jour_07
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 14:34:21 2010 geoffrey hervet
** Last update Wed Oct 13 15:39:10 2010 geoffrey hervet
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_aff_params(int argc, char **argv[])
{
  int	i;

  i = 0;
  while (i < argc)
    {
      my_putstr(argv[i++]);
      my_putchar('\n');
    }
}

int	main(int argc, char **argv[])
{
  my_aff_params(argc, argv);
}
