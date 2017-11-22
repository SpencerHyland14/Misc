#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

void alarmHandler();

int main(int argc, char *argv[]){
    int file = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    const char *buf[3];
    
    buf[0] = "EXAM! EXAM! EXAM!\n";
    buf[1] = "HELP! HELP! HELP!\n";
    buf[2] = "STUDY! STUDY! STUDY!\n";
    
    printf("The parent process has created the file %s\n", argv[1]);
    
    if(fork()==0){
        printf("Child process 1 created with %d\n", getpid());
        write(file, buf[0], 18);
        printf("Child 1 was writted to the file...Now exiting\n");
        sleep(5);
        kill(getpid(), SIGALRM);
        
        
    }else{
        pause();
        if(fork()==0){
            
            printf("Child process 2 created with %d\n", getpid());
            write(file, buf[1], 18);
            printf("Child 2 was writted to the file...Now exiting\n");
            sleep(5);
            signal(SIGALRM, alarmHandler);
            kill(getpid(), SIGALRM);
           
            
        }else{
            pause();
            signal(SIGALRM, alarmHandler);
            write(file, buf[2], 21);
            printf("Parent has written to the file\n");
            sleep(5);
            printf("Parent closing file and exiting...\n");
            close(file);
            
        }
        
    }
    exit(0);
}

void alarmHandler(){
    static int n = 0;
    if(n++<3)
        alarm(3);
    else
        exit(0);
    
}
