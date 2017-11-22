/*
 Spencer Hyland
 104449507
 System Programming
 Assignment 2
 */


#include <unistd.h>
#include <stdio.h>


int main(void){
    //Opens the file
    FILE* file = fopen("storage.txt", "r+");
    int num =0;
    
    //Takes the number stored in the file and saves it to num
    fscanf(file, "%d", &num);
    
    //Goes back to the beginning of the file
    rewind(file);
    
    //Subtracts from the num
    num-=3;
    //Writes the new num to the file
    fprintf(file, "%d\n", num);
    //Prints the new num to terminal
    printf("from consumer: Current total is %d\n",num);
    
    //Runs the producer.sh file
    sleep(1);
    if(fork()==0){
        execl("./producer.sh", "producer.sh", (char *)0);
    }
    
    //closes the file
    fclose(file);
    return 0;
}
