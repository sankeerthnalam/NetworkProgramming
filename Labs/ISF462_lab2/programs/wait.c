#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main ()
{
  int i = 0, j = 0; 
  pid_t ret;
  int status;

  ret = fork ();
  if(ret == 0){
      for (i = 0; i < 5000; i++)
	    printf ("Child: %d\n", i);
      printf ("Child ends\n");
    }
  else
    {
      //wait (&status);
      waitpid(ret,0,0);

      printf ("Parent resumes.\n");
      for (j = 0; j < 5000; j++){
              printf ("Parent: %d\n", j);
              kill(ret,20);
       }
    }
}
