#include<unistd.h>
#include<fcntl.h>

int main(void){
    int file, num=101;
    file=open("list1.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
    write(file, &num, sizeof(num));
    return 0;
}
