#include <stdio.h>
#include <stdlib.h>
extern int errno;
int main (int argc, char *argv[])
{
  int i;
  char **ptr;
  extern char **environ;

  for (i = 0; i < argc; i++)    /* echo all command-line args */
    printf ("argv[%d]: %s\n", i, argv[i]);


  printf("Environment variables:\n");

  setenv("SOME_ENV_VAR","SOME_ENV_VAL",1);
  putenv("NAME123");
//  printf("error no=%d",errno);
  for (ptr = environ; *ptr != 0; ptr++) /* and all env strings */
    printf ("%s\n", *ptr);

  exit (0);
}
