#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
// handler takes a signal number as argument whihc is signal
// return void and take integer
void handler(int signum)
{   // execute procedure then returns to point of exexution.
    printf("handler called with signum=%d\n",signum); // you cannot handle a FPE or
}  // SIGFAULT how do you handle on the fly??

int main(int argc, char *argv[])
{
    int cpid, status;
    // if floating point exception then execute that procedure.
    printf("pid %d\n",getpid());// pointer to a fucntion of htat type see man signal
    signal(SIGFPE,handler);  // kill is used to send a signal, signal sets it up, floating point
    signal(SIGSEGV,handler); // reference to a function.
    signal(SIGCHLD,handler); // if the child changes in some significant way, as in exits:
    signal(SIGKILL,handler);
    signal(SIGINT, handler);
    signal(SIGUSR1, handler);
    cpid = fork(); // fork a new process/
    if (cpid)
    {   printf("pid is %d\n",cpid );
        wait(&status);
        printf("child status %d\n",status);
    }
    else
    {   // child sleeps for five seconds and sleeps
        sleep(5);
        printf("child ending\n"); //SIGCHLD send to handler
        exit(0);
    }
    for (;;) // parent goes into an infinite look so you can send it signals
        ;
    return 0;
}
// keyboard interrupt is cntr c which is default interrupt keyboard SIGINT
// SIGQUIT use cntr \
// kill sends a signal!!!
// you can ignore some signals. like sigchild, but not SIGKILL
// default for SIGUSR1 is to kill, SIGUSR2 is also end process. need to code a my_handler
// wait on child, in signal handler wait for the child. I fyou do not wait for the child,
// you have a zombie state.
// p6 : loops around sleeping. have a signal handler that wants to handle siguser1.
// if siguser2 is recieved etc, terminate immediately. put in alarm. Handle hw. 
