#include<unistd.h>
#include<fcntl.h>

int main (void){
    int file, num = 101;
    file = open("list2.txt", O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);
    lseek(file, 3, SEEK_SET);
    write(file, &num, sizeof(num));

    return 0;
}
