#include "get_next_line.h"

char * get_next_line(int fd)
{
    static char reminder[BUFFER_SIZE];
    char *buffer;
    int read_ret;
    char *line;
    int i;
    int count_ret;

    count_ret = 0;

    i = 2;
    buffer = malloc (BUFFER_SIZE);
    if (reminder[0] == 0)
    {
        read_ret = read(fd,buffer,BUFFER_SIZE);
        count_ret = read_ret;
    }
    else
    {
        ft_strlcpy(buffer,reminder);
        reminder[0] = 0;
    }
    while(!ft_strchr(buffer, '\n') && read_ret == BUFFER_SIZE)
    {
        make_it_bigger(&buffer , i );
        read_ret = read(fd, buffer +count_ret,BUFFER_SIZE);
        printf("%s\n ",buffer);
        count_ret += read_ret;
        if(read_ret == 0)
            break; 
    }
    return (extract_new_line(buffer,reminder));
}