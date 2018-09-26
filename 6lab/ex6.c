#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
  int fds[2];
  pipe(fds);
  printf("Create the first child\n");
  pid_t p1 = fork();
  if (p1 == 0)
  {
    printf("Wait while parent put PID into pipe\n");
    pid_t p2;
    read(fds[0], &p2, sizeof(pid_t));
    close(fds[0]);
    sleep(10);
    printf("Stop second child\n");
    kill(p2, SIGSTOP);
    printf("Wait 10 second\n");
    sleep(10);
    printf("Run second child\n");
    kill(p2, SIGCONT);
    sleep(10);
    printf("Terminate second child\n");
    kill(p2, SIGTERM);
  }
  else
  {
    printf("Create the second child\n");
    pid_t p2 = fork();
    if(p2 == 0)
    {
      while (1)
      {
        printf("I am second child and i am alive\n");
        sleep(1);
      }
    }
    else
    {
      write(fds[1], &p2, sizeof(pid_t));
      close(fds[1]);
      printf("Put in pipe PID of the second child: %d\n", p2);
      int exitCode;
      waitpid(p2, &exitCode, 0);
      printf("My second child was terminated\n");
      exit(exitCode);
    }
  }

  return 0;
}
