#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int args, char *argv[]){
    if(fork() == 0){ //Process 2
    	if(fork() == 0){ //Process 5
    		sleep(atoi(argv[5]));
    		printf("Process 5 terminated. pid %d\n", getpid());
    		exit(0);
    	}
    	else{
    		if(fork() == 0){ //Process 7
    			sleep(atoi(argv[7]));
    			printf("Process 7 terminated. pid %d\n", getpid());
    			exit(0);
    		}
    	}
    	sleep(atoi(argv[2]));
    	printf("Process 2 terminated. pid %d\n", getpid());
    }
    else{ //Process 1
    	if(fork() == 0){ //Process 3
    		sleep(atoi(argv[3]));
    		printf("Process 3 terminated. pid %d\n", getpid());
    		exit(0);
    	}
    	else{//Process 4
    		if(fork() == 0){
    			sleep(atoi(argv[4]));
    			printf("Process 4 terminated. pid %d\n", getpid());
    			exit(0);
    		}
    		else{
    			if(fork() == 0){ //Process 6
    				sleep(atoi(argv[6]));
    				printf("Process 6 terminated. pid %d\n", getpid());
    				exit(0);
    			}
    		}
    	}
    	sleep(atoi(argv[1]));
		printf("Process 1 terminated. pid %d\n", getpid());
    }
	return 0;
    
}
