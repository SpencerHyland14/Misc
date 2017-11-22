/*
 Spencer Hyland
 104449507
 System Programming
 Assignment 1
 */

#include<unistd.h>
#include<fcntl.h>




int main(int argc, char *argv[]){
    
    //Integer declaration for the program
    
    //Arrays to store the widths and heights
    int width1[255] = {0}, height1[255] = {0};
    int width2[255] = {0}, height2[255] = {0};
    int width3[255] = {0}, height3[255] = {0};
    
    int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    int flag = 0;
    
    int wCounter = 0, hCounter= 0;
    
    int picWidth1 = 0, picHeight1 = 0;
    int picWidth2 = 0, picHeight2 = 0;
    int picWidth3 = 0, picHeight3 = 0;
    
    //Opening the given ppm files
    int file1 = open(argv[1], O_RDWR);
    int file2 = open(argv[2], O_RDWR);
    int byte = 0;
    int counter3 = 0;
    

    //Reads the first file entered and determines its width and height and stores the integers into an array
    lseek(file1, 3, SEEK_SET);
    while(temp1 != 10){
        read(file1, &temp1, 1);
        if (temp1 == 32){
            flag = 1;
        }
        else if (temp1 == 10){
            break;
        }
        else if(flag == 0){
            temp1 = temp1 - 48;
            width1[wCounter]= temp1;
            wCounter++;
        }
        else if (flag == 1){
            temp1 = temp1 - 48;
            height1[hCounter]= temp1;
            hCounter++;
        }
        
    }
    
    //Compacts the width array and finds the width
    for (int counter = 0; counter< wCounter; counter++){
        picWidth1 = 10*picWidth1 + width1[counter];
    }
    // Compacts the Height array and finds the height
    for (int counter = 0; counter< hCounter; counter++){
        picHeight1 = 10*picHeight1 + height1[counter];
    }
    
    //Reads the second file entered and determines its width and height and stores the numbers into an array
    flag = 0;
    wCounter = 0;
    hCounter = 0;
    lseek(file2, 3, SEEK_SET);
    while (temp2 != 10){
        read(file2, &temp2, 1);
        if (temp2 == 32){
            flag = 1;
        }
        else if (temp2 == 10){
            break;
        }
        else if(flag ==0){
            temp2 = temp2 - 48;
            width2[wCounter] = temp2;
            wCounter++;
        }
        else if (flag == 1){
            temp2 = temp2 - 48;
            height2[hCounter] = temp2;
            hCounter++;
        }
    }
    
    //Compacts the second width array and finds the width
    for (int counter = 0; counter<wCounter; counter++){
        picWidth2 = 10*picWidth2 + width2[counter];
    }
    
    //Compacts the second height array and finds the height
    for (int counter = 0; counter<hCounter; counter++){
        picHeight2 = 10*picHeight2 + height2[counter];
    }
    
    //If statement checking to make sure that the first entered file is larger than the second.
    //Produces error message if not
    if (picHeight1 < picHeight2 || picWidth1 < picWidth2){
        char errorMessage [] = "ERROR file 2 is larger than file 1 please try again... \n";
        write(STDOUT_FILENO, errorMessage, sizeof(errorMessage));
        
        close(file1);
        close(file2);
        return 0;
    }
    
    //Creates the new file that will be merged onto
    int newFile = open(argv[3], O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
    
    //Seeks to the beginning of the new file and the file1 and copys the file over to the new file which will become merged
    lseek(file1, 0, SEEK_SET);
    lseek(newFile, 0, SEEK_SET);
    while(counter3 != 3){
        if(temp3 == 10)
            counter3++;
        read(file1, &temp3, 1);
        write(newFile, &temp3, 1);
    }
    
    //Runs through the height and width of file1 and copies it to newFile
    for(int counter = 0; counter < picHeight1; counter++){
        for (int counter2 = 0; counter2 < picWidth1*3; counter2++){
            read(file1, &temp3, 1);
            write(newFile, &temp3, 1);
        }
    }
    
    flag = 0;
    wCounter = 0;
    hCounter = 0;
    lseek(newFile, 3, SEEK_SET);
    
    //While its the ascii characters determinging the information of the file
    //it will collect the information of the height and width of the newFile
    while(temp4 != 10){
        read(newFile, &temp4, 1);
        if (temp4 == 32){
            flag = 1;
        }
        else if (temp4 == 10){
            break;
        }
        else if(flag == 0){
            temp4 = temp4 - 48;
            width3[wCounter] = temp4;
            wCounter++;
        }
        else if (flag == 1){
            temp4 = temp4 - 48;
            height3[hCounter] = temp4;
            hCounter++;
        }
    }
    
    //Compacts the newFile width into a single integer
    for (int counter = 0; counter<wCounter; counter++){
        picWidth3 = 10*picWidth3 + width3[counter];
    }
    
    //Compacts the newFile height into a single height integer
    for (int counter = 0; counter<hCounter; counter++){
        picHeight3 = 10*picHeight3 + height3[counter];
    }

    
    int tByte = 0;
    //To run along the height of the pixels
    for(int counter = 0; counter<picHeight2; counter++){
        //Seeks to the right hand corner of the image file
        lseek(newFile, (picWidth3-picWidth2)*3, SEEK_CUR);
        //Once at the right hand corner start copying file2 to newFile
        for (int counter2 = 0; counter2<picWidth2*3; counter2++){
            read(file2, &tByte, 1);
            write(newFile, &tByte, 1);
        }
    }

    //Closes all files to prevent memory leaks
    close(file1);
    close(file2);
    close(newFile);
    
    return 0;
    
    
}


