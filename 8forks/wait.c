#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

void pre_exit(int status)
{
    if(WIFEXITED(status))
    {
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    }
    else if(WIFSIGNALED(status))
    {
        printf("abnormal termination, signal number is %d%s\n", WTERMSIG(status),
    
#ifdef WCOREDUMP
        __WCOREDUMP(status) ? "(core file generated)" : "");  
#else
        "");
#endif
    }
    else if (WIFSTOPPED(status))
    {
        printf("child stopped, signal nember = %d\n", WSTOPSIG(status));
    }
        
}


int main(void)
{
    pid_t   pid;
    int status;

    if((pid = fork()) < 0)
    {
        printf("1 --fork error, %s\n", strerror(errno));
        return -1;
    } 
    else if(pid == 0)
    {
        exit(7);
    }
    if(wait(&status) != pid)
    {
        printf("1 --wait error %s\n", strerror(errno));
    }
    pre_exit(status);

     if((pid = fork()) < 0)
    {
        printf("2 --fork error, %s\n", strerror(errno));
        return -1;
    } 
    else if(pid == 0)
    {
        abort();
    }
    if(wait(&status) != pid)
    {
        printf("2 --wait error %s\n", strerror(errno));
    }
    pre_exit(status);

    if((pid = fork()) < 0)
    {
        printf("3 --fork error, %s\n", strerror(errno));
        return -1;
    } 
    else if(pid == 0)
    {
        status /= 0;
    }
    if(wait(&status) != pid)
    {
        printf("1 --wait error %s\n", strerror(errno));
    }
    pre_exit(status);

    return 0;
}