#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//linux 中该信号不起作用

static void sig_cld(int);

int main()
{
    pid_t pid;

    if(signal(SIGCLD, sig_cld) == SIG_ERR)
    {
        perror("main sigerror");
    }

    if ((pid = fork()) < 0)
    {
        perror("fork error");
    } 
    else if(pid == 0)
    {
        sleep(2);
        _exit(0);
    }

    pause();
    exit(0);
}

static void sig_cld(int signo)
{
    pid_t pid;
    int status;

    printf("SIGCLD recieved\n");
    if (signal(SIGCLD, sig_cld) == SIG_ERR)
    {
        perror("signal error\n");
    }

    if ((pid = wait(&status)) < 0)
    {
        perror("wait error");
    }
}