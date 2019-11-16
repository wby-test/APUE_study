#include <stdio.h>
#include <unistd.h>

int main()
{
    char name[65];
    gethostname(name, 65);
    printf("hostname = %s\n", name);
}