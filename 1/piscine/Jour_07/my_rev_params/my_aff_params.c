/*
** my_aff_params.c for my_aff_params in /home/hervet_g//work/piscine/Jour_07
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 13 14:34:21 2010 geoffrey hervet
** Last update Wed Oct 13 15:42:38 2010 geoffrey hervet
*/
int	my_rev_params(int argc, char **argv[])
{
  argc = argc - 1;
  while (argc >= 0)
    {
      printf("%s\n", argv[argc]);
      argc = argc - 1;
    }
}

int	main(int argc, char **argv[])
{
  my_rev_params(argc, argv);
}
