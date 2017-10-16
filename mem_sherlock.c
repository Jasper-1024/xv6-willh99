#include "types.h"
#include "user.h"

int
main(int args, char** argv)
{

	while(1){

		sleep(1);
		malloc(1<<23);
	}
	return halt();
}
