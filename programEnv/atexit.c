#include <stdio.h>
#include <stdlib.h>

void func1();
void func2();
void func3();
int func4();

int main()
{
    atexit(func1);
    atexit(func2);
    atexit(func3);
    char *env = (char *)malloc(1024);
    if (getenv(env) == NULL)
    {
        printf("-----\n");
    }
    free(env);
    char *p = getenv("HOME");
    printf("%s\n", p);
    func4();
    printf("-----\n");
    exit(0);
}

int func4()
{
    printf("func4\n");
    exit(0);
}

void func1()
{
    printf("func1 \n");
}

void func2()
{
    printf("func2 \n");
}

void func3()
{
    printf("func3 \n");
}