#include	"opt_get.h"

int main()
{
  {
     const char*format = "-f -a";
     char *av[] = {"ls", "-af"};
     t_opt* res = opt_get(2, av, format);
     printf("!= NULL : %p\n", res);
     // res != NULL car av concorde avec format
  }
#if 0
  {
      const char*format = "-f ARG -u -a";
      char *av[] = {"ls", "-u", "-f", "main.c",    "-a"};
      t_opt* res = opt_get(5, av, format);
      // res != NULL car av concorde avec format
   }
   {
      const char*format = "-f ARG -u -a";
      char *av[] = {"ls", "-u"};
     t_opt* res = opt_get(2, av, format);
     // res == NULL car av ne concorde pas avec format
     // les options -f ARG et -a etants obligatoires
   }
   {
     const char*format = "-f [-a]";
     char *av[] = {"ls", "-f"};
     t_opt* res = opt_get(2, av, format);
     // res != NULL car av concorde avec format
     // l’option -a etant optionnelle
   }
   {
     const char*format = "-f [-a]";
     char *av[] = {"ls", "-a"};
     t_opt* res = opt_get(2, av, format);
     // res == NULL car av ne concorde pas avec format
     // l’option -f etant obligatoire
   }
   {
     const char*format = "-f [-a] [-u ARG]";
     char *av[] = {"ls", "-f", "-u"};
     t_opt* res = opt_get(3, av, format);
     // res == NULL car av ne concorde pas avec format
     // Un argument etant obligatoire en presence de l’option -u
   }
   {
     const char*format = "-a ...";
     char *av[] = {"ls", "-a", "file1", "file2", "file3"};
     t_opt* res = opt_get(5, av, format);
     // res != NULL car av concorde avec format
   }
   {
     const char*format = "-a ...";
     char *av[] = {"ls", "-a"};
     t_opt* res = opt_get(2, av, format);
     // res != NULL car av concorde avec format
   }
#endif
   return (0);
}
