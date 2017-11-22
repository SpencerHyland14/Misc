#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

void child(int *fd, char *argv[]);
void parent(int *fd, char *argv[]);

int main(int argc, char *argv[]){
    
    int fd[2];
    
    if(pipe(fd) == -1)
        exit(1);
    if(fork() == 0)
        child(fd, argv);
    else
        parent(fd, argv);
    
    exit(0);
}

void child(int *fd, char *argv[]){
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    execlp(argv[2], argv[2], NULL);
}

void parent(int *fd, char *argv[]){
    sleep(1);
    
    int i = 0;
    char buf[100];
    
    close(fd[1]);
    int file = open(argv[1], O_CREAT | O_RDWR, 0755);
    //Gets the sum of the bytes contained in the file
    while(read(fd[0], &buf[i], 1) != 0){
        i++;
    }
    write(file, &buf, i);
    printf("The result of %s is written into %s with a total of %d bytes\n", argv[2], argv[1], i);
}
