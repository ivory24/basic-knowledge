#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main() {
    int fd = open("nonexistent_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        printf("errno is %d\n", errno);
        if (errno == ENOENT) {
            printf("File does not exist\n");
        } else if (errno == EACCES) {
            printf("Permission denied\n");
        } else {
            printf("Unknown error\n");
        }
    } else {
        printf("File opened successfully\n");
        close(fd);
    }
    return 0;
}

// gcc errno_demo.c -o errno_demo