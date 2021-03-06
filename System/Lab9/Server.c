#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
    int fd1, fd2;
    pid_t pid;
    char ch;
    char blanks[55]="                                                  | ";
    int writeblanks = 1;
    unlink("./fifo1");
    unlink("./fifo2");
    if ( mkfifo("./fifo1", 0777) || mkfifo("./fifo2", 0777)) {
        perror("fifo");
        exit(1);
    }
    while (1) {
        printf("\nWaiting for connection...\n");
        fd1 = open("./fifo1", O_RDONLY);
        fd2 = open("./fifo2", O_WRONLY);
        printf("\n my messages (server) received messages (client) \n");
        printf("-------------------------------------------------------------------------------\n");
        if ( (pid = fork()) == -1 ) {
            perror("fork");
            exit(1);
        }
        if ( pid == 0 )
            while (1) {
                ch = getchar();
                write(fd2, &ch, 1);
                
            }
        while ( read(fd1, &ch, 1) == 1 ) {
            if ( writeblanks == 1 )
                write(1, blanks, sizeof(blanks));
            writeblanks = 0;
            write(1, &ch, 1);
            if(ch == '\n')
                writeblanks = 1;
            
        }
        close(fd1);
        close(fd2);
        printf("\nClient left.\n\n\n");
        kill(pid, SIGTERM);
               
    }
}
