/*
 Spencer Hyland
 104449507
 System Programming
 Assignment 2
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void handler();

int main(int argc, char *argv[]){
    char firstLine[] = "P6\n1000 1000\n255\n";
    int file = open(argv[1], O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
    
    //Colour declarations
    unsigned char green[3]={0,250,0};
    unsigned char red[3]={255,0,0};
    unsigned char blue[3] = {0,0,255};
    unsigned char violet[3] = {238,130,238};
    unsigned char yellow[3] = {255,255,0};
    unsigned char orange[3] = {255,165,0};
    unsigned char cyan[3] = {0,255,255};
    unsigned char magenta[3] = {255,0,255};
    unsigned char ocean[3] = {28,107,160};
    
    //Colour arrays that save the entered RGB values
    unsigned char colour1[3], colour2[3], colour3[3], colour4[3], colour5[3];
    
    //Writes the header into the file
    write(file, firstLine, 17);
    lseek(file, 17, SEEK_SET);
    
    
    //Checks the third argument(First colour entered)
    //to see what colour is entered and assigns the RGB values
    //to an array of that colour
    if(!(strcmp(argv[2], "red"))){
        memcpy(colour1, red, 3);
    }else if(!(strcmp(argv[2], "blue"))){
        memcpy(colour1, blue, 3);
    }else if(!(strcmp(argv[2], "green"))){
        memcpy(colour1, green, 3);
    }else if(!(strcmp(argv[2], "yellow"))){
        memcpy(colour1, yellow, 3);
    }else if(!(strcmp(argv[2], "orange"))){
        memcpy(colour1, orange, 3);
    }else if(!(strcmp(argv[2], "violet"))){
        memcpy(colour1, violet, 3);
    }else if(!(strcmp(argv[2], "cyan"))){
        memcpy(colour1, cyan, 3);
    }else if(!(strcmp(argv[2], "magenta"))){
        memcpy(colour1, magenta, 3);
    }else if(!(strcmp(argv[2], "ocean"))){
        memcpy(colour1, ocean, 3);
    }
    
    
    //checks for the 2nd colour that is entered
    if(!(strcmp(argv[3], "red"))){
        memcpy(colour2, red, 3);
    }else if(!(strcmp(argv[3], "blue"))){
        memcpy(colour2, blue, 3);
    }else if(!(strcmp(argv[3], "green"))){
        memcpy(colour2, green, 3);
    }else if(!(strcmp(argv[3], "yellow"))){
        memcpy(colour2, yellow, 3);
    }else if(!(strcmp(argv[3], "orange"))){
        memcpy(colour2, orange, 3);
    }else if(!(strcmp(argv[3], "violet"))){
        memcpy(colour2, violet, 3);
    }else if(!(strcmp(argv[3], "cyan"))){
        memcpy(colour2, cyan, 3);
    }else if(!(strcmp(argv[3], "magenta"))){
        memcpy(colour2, magenta, 3);
    }else if(!(strcmp(argv[3], "ocean"))){
        memcpy(colour2, ocean, 3);
    }
    //checks for the 3rd colour that is entered
    if(!(strcmp(argv[4], "red"))){
        memcpy(colour3, red, 3);
    }else if(!(strcmp(argv[4], "blue"))){
        memcpy(colour3, blue, 3);
    }else if(!(strcmp(argv[4], "green"))){
        memcpy(colour3, green, 3);
    }else if(!(strcmp(argv[4], "yellow"))){
        memcpy(colour3, yellow, 3);
    }else if(!(strcmp(argv[4], "orange"))){
        memcpy(colour3, orange, 3);
    }else if(!(strcmp(argv[4], "violet"))){
        memcpy(colour3, violet, 3);
    }else if(!(strcmp(argv[4], "cyan"))){
        memcpy(colour3, cyan, 3);
    }else if(!(strcmp(argv[4], "magenta"))){
        memcpy(colour3, magenta, 3);
    }else if(!(strcmp(argv[4], "ocean"))){
        memcpy(colour3, ocean, 3);
    }
    //Checks for the 4th colour that is entered
    if(!(strcmp(argv[5], "red"))){
        memcpy(colour4, red, 3);
    }else if(!(strcmp(argv[5], "blue"))){
        memcpy(colour4, blue, 3);
    }else if(!(strcmp(argv[5], "green"))){
        memcpy(colour4, green, 3);
    }else if(!(strcmp(argv[5], "yellow"))){
        memcpy(colour4, yellow, 3);
    }else if(!(strcmp(argv[5], "orange"))){
        memcpy(colour4, orange, 3);
    }else if(!(strcmp(argv[5], "violet"))){
        memcpy(colour4, violet, 3);
    }else if(!(strcmp(argv[5], "cyan"))){
        memcpy(colour4, cyan, 3);
    }else if(!(strcmp(argv[5], "magenta"))){
        memcpy(colour4, magenta, 3);
    }else if(!(strcmp(argv[5], "ocean"))){
        memcpy(colour4, ocean, 3);
    }
    
    //Checks for the 5th colour that is entered
    if(!(strcmp(argv[6], "red"))){
        memcpy(colour5, red, 3);
    }else if(!(strcmp(argv[6], "blue"))){
        memcpy(colour5, blue, 3);
    }else if(!(strcmp(argv[6], "green"))){
        memcpy(colour5, green, 3);
    }else if(!(strcmp(argv[6], "yellow"))){
        memcpy(colour5, yellow, 3);
    }else if(!(strcmp(argv[6], "orange"))){
        memcpy(colour5, orange, 3);
    }else if(!(strcmp(argv[6], "violet"))){
        memcpy(colour5, violet, 3);
    }else if(!(strcmp(argv[6], "cyan"))){
        memcpy(colour5, cyan, 3);
    }else if(!(strcmp(argv[6], "magenta"))){
        memcpy(colour5, magenta, 3);
    }else if(!(strcmp(argv[6], "ocean"))){
        memcpy(colour5, ocean, 3);
    }
    
    
    //First child writes 100 lines to file
    signal(SIGUSR1, handler);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if( j >=500){
                    write(file, &colour2, 3);
                }
                else{
                    write(file, &colour3, 3);
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    sleep(2);
    
    
    //Second child writes next 100 lines to file
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if( j >=500){
                    write(file, &colour2, 3);
                }
                else{
                    write(file, &colour3, 3);
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    
    //Third child writes to file and starts to make the diamond
    sleep(2);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if(j >= (550 - i) && j<= (450 + i)){
                    write(file, &colour1, 3);
                }
                else{
                    if( j >=500){
                        write(file, &colour2, 3);
                    }
                    else{
                        write(file, &colour3, 3);
                    }
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    
    //Fourth child writes to file
    sleep(2);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if(j >= (450 - i) && j<= (550 + i)){
                    write(file, &colour1, 3);
                }
                else{
                    if( j >=500){
                        write(file, &colour2, 3);
                    }
                    else{
                        write(file, &colour3, 3);
                    }
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    
    //Fifth child to write to file
    sleep(2);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if(j >= (350 - i) && j<= (650 + i)){
                    write(file, &colour1, 3);
                }
                else{
                    if( j >=500){
                        write(file, &colour2, 3);
                    }
                    else{
                        write(file, &colour3, 3);
                    }
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    
    //Sixth child process
    sleep(2);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if( j<= (750 - i) && j >= (250 + i)){
                    write(file, &colour1, 3);
                }
                else{
                    if( j >=500){
                        write(file, &colour4, 3);
                    }
                    else{
                        write(file, &colour5, 3);
                    }
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    
    //Seventh child process
    sleep(2);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if( j<= (650 - i) && j >= (350 + i)){
                    write(file, &colour1, 3);
                }
                else{
                    if( j >=500){
                        write(file, &colour4, 3);
                    }
                    else{
                        write(file, &colour5, 3);
                    }
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    
    //Eighth child process
    sleep(2);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if( j<= (550 - i) && j >= (450 + i)){
                    write(file, &colour1, 3);
                }
                else{
                    if( j >=500){
                        write(file, &colour4, 3);
                    }
                    else{
                        write(file, &colour5, 3);
                    }
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    //Ninth child process
    sleep(2);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if( j >=500){
                    write(file, &colour4, 3);
                }
                else{
                    write(file, &colour5, 3);
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    
    //Tenth child process
    sleep(2);
    if(fork()==0){
        for(int i =0;i<100;i++){
            for(int j=0;j<1000;j++){
                if( j >= 500){
                    write(file, &colour4, 3);
                }
                else{
                    write(file, &colour5, 3);
                }
            }
        }
        kill(getpid(), SIGUSR1);
        pause();
    }
    
    //Closes the file to prevent memory leaks
    close(file);
    return 0;
}


void handler(){
    sleep(1);
    return;
}
