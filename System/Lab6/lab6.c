#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
    printf("EXAM! EXAM! EXAM!\n");
    if(fork() == 0){
        execl("./myBash.sh", "myBash.sh", (char *)0);
    }
	return 0;
    
}
