#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
int numSigs1 = 0;

void handler(int signum)
{
    if (signum == SIGUSR1) {
      printf("received SIGUSR1\n");
      numSigs1++;
      if (numSigs1 >= 4) {
        printf("terminating due to 4 SIGUSR1 signals");
        exit(0);
        }
      } else if(signum == SIGUSR2){
        printf("received SIGUSR2\n");
        exit(0);
      } else if(signum == SIGINT){
        printf("Keyboard Interrupt!\n");
        exit(0);
      }
}

int main(int argc, char *argv[]) {
  alarm(90);

  if (argc > 1  &&  strcmp(argv[1],"-hw") == 0){
    printf("hello world\n");
    exit(0);
  }

  signal(SIGUSR1, handler);
  signal(SIGUSR2, handler);
  signal(SIGINT, handler);

  while (true) {
    sleep(1);
    printf("sleep\n" );
  }

  return 0;
}
