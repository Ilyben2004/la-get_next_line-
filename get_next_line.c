#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char reminder[BUFFER_SIZE];
    char *buffer;
    int read_ret;

    buffer = malloc (BUFFER_SIZE);
    read_ret = read(fd, buffer, BUFFER_SIZE);
    if



}