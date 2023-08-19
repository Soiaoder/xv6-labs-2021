#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc !=2)
    {
        printf("Please enter the parameters!");
        exit(1);
    }
    else
    {
        int duration = atoi(argv[1]);
        sleep(duration);
    }
    exit(0);
}