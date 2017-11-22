#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>

int main(int num, char *args[]){
    
    //Checks to make sure there is only the number entered as an argument
    if(num != 2){
        //If not error message is produced and program terminated
        printf("Error no argument entered\n");
        return 0;
    }
    //Converts the entered argument from char to int
    int in = atoi(args[1]);
    //Checks to make sure the argument is between 1 and 10
    if(in < 1 || in > 10){
        printf("Invalid input\n");
        return 0;
    }
    
    //Writes the entered argument into the file
    if(!fork()){
        int file = open("data.dat", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
        write(file, args[1] , sizeof(args[1])/4);
    }
    
    //Checks the process ID if 0 then it represents the child and runs child functions
    else{
        //Opens the dat file and saves its contents
        char buf[2];
        int data = open("data.dat", O_RDONLY);
        //Reads the information from data and saves it to buf
        int fileInfo = read(data, buf, 2);
        
        int num = atoi(buf);
        int fact= 1;
        
        for(int i= 1; i<=num; i++){
            fact *= i;
        }
        printf("%d! is: %d\n", num, fact);
        
    }

        
    
    return 0;
}
        
    
    
    
    
