#include "types.h"
#include "user.h"

int
main(int args, char** argv)
{
    char *ptr;
    int bytes = 1024;
    int err;

    ptr = (char*) malloc(bytes);

    err = minitop(ptr, bytes);
    if(err != 0){
        printf(1, "Error system call minitop failed. Error code [%d]\n", err);
        exit();
    }

    printf(1, "%s", ptr);
    free(ptr);
    exit();
}
