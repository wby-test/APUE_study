#include <stdio.h>
#include <signal.h>

static void handle(int signal)
{
    if (signal == SIGUSR1)
    {
        printf("SIGNAL1\n");
       // return ;
    } 
    else if (signal == SIGUSR2)
    {
        printf("SIGNAL2\n");
        //return ;
    }
    else {
        printf("nothing get\n");
        return ;
    }
    return;
}

int main()
{
    if (signal(SIGUSR1, handle) == SIG_ERR)
    {
        printf("can't catch SIGUSR1\n");
        //return -1;
    }
    if (signal(SIGUSR2, handle) == SIG_ERR)
    {
        printf("can't catch SIGUSR2\n");
        //return -1;
    }

    for( ; ; )
    {
        pause();
    }

    return 0;
}