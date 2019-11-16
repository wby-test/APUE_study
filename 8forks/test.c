#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("no args\n");
        return 0;
    }

    int i = 0;
    for (; i < argc; i++ )
    {
        printf("%s\n", argv[i]);
    }

    return 0;
}