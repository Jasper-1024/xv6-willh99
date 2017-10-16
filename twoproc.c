#include "types.h"
#include "user.h"

int
main(int args, char** argv)
{
    int pid, i;
    pid = fork();

    if(pid<0){
        printf(0, "Can't Fork try spooning\n");
    }
    else if(pid==0){
        for(i=0; i<100; i++){
            printf(0, "+");
            yield();
        }
    }
    else{
        for(i=0; i<100; i++){
            printf(0, "-");
            yield();
        }
        wait();
    }

    return 0;
}
