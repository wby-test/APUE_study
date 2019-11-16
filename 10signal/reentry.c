#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <pwd.h>

static void my_alarm(int signal)
{
    struct passwd *rootPtr;

    printf("in singal handle\n");
    if ((rootPtr = getpwnam("root")) == NULL)
    {
        printf("getpwnam(root) error\n");
        return;
    }
    alarm(1);
}

int main()
{
    struct passwd *ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);
    for(; ;)
    {
        if ((ptr = getpwnam("wby")) == NULL)
        {
            printf("getpwnam(root) error\n");
            return -1;
        } 

        if (strcmp(ptr->pw_name, "wby") != 0)
        {
            printf("return value corrupted!, pw_name = %s \n",
                ptr->pw_name);
        }
    }

    return 0;
}