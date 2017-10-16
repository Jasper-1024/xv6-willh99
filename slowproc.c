#include "types.h"
#include "user.h"

#define LOOP_MAX     5
#define MAX_WORK_ITS 1000000

//-----------------------------------------------------------------------------
int 
fibonacci(int n) {
  int a = 0;
  int b = 1;
  int sum = 0;
 
  while(n--) {
       sum = a+b;
       a = b;
       b = sum;
       //printf(0, "sum is %d\n", sum);
  }
  return sum;
}
//-----------------------------------------------------------------------------
int 
dowork(void) {
  int i;
  int fx;

  for( i = 1; i < MAX_WORK_ITS; i++ ) {
    fx = fibonacci(i % 10);
  }
  return fx;
}

//-----------------------------------------------------------------------------
int
main(int argc, char *argv[]) {
  int pid;
  int i;
  int fx;

  pid = fork();
  if( pid == 0 ) {
    //Child
    printf( 1, "(+)Child pid: %d\n", getpid() );

    for( i = 0; i < LOOP_MAX; i++ ) {
      fx = dowork();
      printf( 0, "+" );
      sleep(1);
    }
    printf( 1, "\nfx:%d\n", fx); // ensures loop not optimized by compiler 
  } else {
    //Parent
    printf( 1, "(-)Parent pid: %d\n", getpid() );

    for( i = 0; i < LOOP_MAX; i++ ) {
      printf( 0, "-" );
      yield();
    }
    wait();
  }
  printf( 0, "\n" );
  exit();
}

