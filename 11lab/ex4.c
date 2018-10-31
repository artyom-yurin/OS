#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){

    int fin, fout;
    char *src, *dst;

    fin = open("ex1.txt", O_RDONLY);
    fout = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    struct stat bufstat;

    fstat(fin, &bufstat);

    src = mmap(NULL, bufstat.st_size, PROT_READ, MAP_PRIVATE, fin, 0);

    ftruncate(fout, bufstat.st_size);

    dst = mmap(NULL, bufstat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fout, 0);


    memcpy(dst, src, bufstat.st_size);

    munmap(src, bufstat.st_size);
    munmap(dst, bufstat.st_size);

    close(fin);
    close(fout);

    return 0;
}
