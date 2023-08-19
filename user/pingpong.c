#include "kernel/types.h"
#include "user/user.h"
#include "stddef.h"


int
main(int argc, char *argv[])
{
    int pd[2];
    pipe(pd);
    char buf[8];
    if (fork() == 0) 
    {
        read(pd[0], buf, 4);
        printf("%d: received %s\n", getpid(), buf);
        write(pd[1], "pong", 4);
    }
    else 
    {
        write(pd[1], "ping", 4);
        wait(NULL);
        read(pd[0], buf, 4);
        printf("%d: received %s\n", getpid(), buf);
    }
    exit(0);
}