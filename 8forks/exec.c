#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

char *event_init[] = {"USER=root", "PATH=/tmp", NULL};

int main(void)
{
    pid_t pid;
    if ( ( pid = fork() ) < 0 )
    {
        printf("fork error\n");
        return -1;
    } else if (pid == 0) 
    {
        if (execle("/home/wby/project/libeventTest/test", "test",(char *)0, event_init) < 0) 
        {
            printf( "execle error\n" );
        }
    }

    if (waitpid(pid, NULL, 0) < 0)
    {
        printf("wait error\n");
    }

    if ((pid = fork()) < 0) 
    {
        printf("fork 2 error\n");
        return -1;
    } else if (pid == 0) {
        if (execle("/home/wby/project/Cproject/APUE/8forks/test", "test" ,"hhh", "heiheihei", (char*)0, event_init) < 0)
        {
            printf("execlp error\n");
        }
    }

    if (waitpid(pid, NULL, 0) < 0)
    {
        printf("wait error\n");
    }
    return 0;
}