#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int main(void)
{

    char *c = NULL;
    int fd = open("test.txt", O_RDONLY);
    while (c = get_next_line(fd))
    {
        printf("%s",c);
        free(c);
    }
    
    
}
