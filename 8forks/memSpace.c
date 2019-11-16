#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

int g_globvar = 6;
char buf[] = "helloworld\n";
int main()
{
    int var;
    pid_t pid;

    var = 88;
    FILE *fp;
    write(STDOUT_FILENO, buf, sizeof(buf)-1);
    fp = fopen("test.txt", "a+");
    if(fwrite( buf, 1, sizeof(buf)-1, fp) != sizeof(buf)-1)
    {
        printf("write error %s\n", strerror(errno));
        return -1;
    }
    fflush(fp);
    printf("begin fork\n");

    if( (pid = fork()) < 0)
    {
        printf("fork error %s\n", strerror(errno));
        return -1;
    }
    else if(pid == 0)
    {
        g_globvar++;
        var++;
        printf("child progress  g_globvar = %d, var =  %d pid is = %ld\n", g_globvar, var, (long)getpid());
    }
    else
    {
        printf("parent progress return child program id is %d\n", pid);
        while(1)
        {
            var++;
            if(var = 10000)
            {
                break;
            }
        }
        sleep(1);
    }

    printf("pid = %ld, glob  = %d, var = %d\n", (long)getpid(), g_globvar, var);
    return 0;
}