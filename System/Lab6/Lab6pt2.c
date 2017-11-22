#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    
    for(int i = 1; i<argc; i+=2){
        if (fork()==0){
            printf("PID is %d\n", getpid());
            execlp(argv[i], argv[i], argv[i+1], (char *)0);
            exit(0);
        }
    }
	return 0;
}
