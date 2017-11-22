
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*int main() {
    fork();
    fork();
    fork();
    printf("%d\n", getpid());
    
}*/
//Prints 2^n times
/*int main() {
    if (fork() == 0)
        fork();
    else {
        fork();
        fork();
        printf("%d\n", getpid());
    }
}*/
//Prints 4 times
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
if (fork() == 0)
fork();
else {
    fork();
    fork();
}
printf("%d\n", getpid());
}

