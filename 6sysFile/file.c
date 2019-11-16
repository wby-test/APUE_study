#include <sys/utsname.h>
#include <stdio.h>
#include <unistd.h>

int main() 
{
    char name[65];
    gethostname(name, 65);
    printf("hostname = %s\n", name);
    struct utsname a;
    if(uname(&a) == -1)
    {
        printf("get uname error\n");
        return -1;
    }
    printf("machine is %s system is %s\n", a.machine, a.sysname);
    return 0;
}