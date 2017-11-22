#include<unistd.h>
#include<fcntl.h>

int main(void){
    int file=open("list2.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
    const char n[] = "GM\t101\tBuick\t2010\nFord\t102\tLincoln\t2005";
    write(file, &n, sizeof(n));
    return 0;

}
