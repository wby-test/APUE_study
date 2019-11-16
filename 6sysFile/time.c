//#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 
    time_t a;
    struct tm localTime;
    time(&a);
    printf("%d\n", a);  
    localTime =  *localtime(&a);
    printf("y:%d \n m:%d \n d:%d \n h:%d \n min:%d \n s:%d \n ", localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,  localTime.tm_hour, localTime.tm_min, localTime.tm_sec);

    printf("function clock_gettime...\n");
    struct timespec time;
    if ( (clock_gettime(CLOCK_REALTIME, &time)) != 0)
    {
        return -1;
    }
    printf("now time is %d s ---- %d ns \n", time.tv_nsec);
    localTime = *localtime(&time.tv_sec);
    printf("y:%d \n m:%d \n d:%d \n h:%d \n min:%d \n s:%d \n ====== \n", localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,  localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    

    localTime = *gmtime(&time.tv_sec);
    printf("y:%d \n m:%d \n d:%d \n h:%d \n min:%d \n s:%d \n ", localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,  localTime.tm_hour, localTime.tm_min, localTime.tm_sec);

    return 0;
    */

    time_t t;
    struct tm *gmt, *area;
    tzset(); /*tzset()*/
    t = time(NULL);
    area = localtime(&t);
    printf("Local time is: %s", asctime(area)); //asctime(已经弃用)
    gmt = gmtime(&t);
    printf("GMT is: %s", asctime(gmt));
    return 0;
}