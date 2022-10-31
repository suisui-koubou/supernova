#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/exec.3.html

int main() {
    char *argv[2];
    argv[0] = "cat";
    argv[1] = 0;
    if (fork() == 0) {
        close(0);
        open("input.txt", O_RDONLY);
        execv("cat", argv); 
        exit(0);
    }else{
        wait(0);
    }
}
