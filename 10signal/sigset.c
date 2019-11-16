#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

sigset_t sig;

int main()
{
    sigemptyset();
    return 0;
}