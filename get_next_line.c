#include "get_next_line.h"

void * helper_func(char *buffer, char * reminder , int * count_ret , int * read_ret, int fd)
{
    if (!buffer)
        return (NULL);
    if (reminder[0] != 0)
    {
        *count_ret = ft_strlcpy(buffer, reminder);
        reminder[0] = 0;
    }
    else
    {
        *read_ret = read(fd, buffer, BUFFER_SIZE);
        if (*read_ret <= 0) 
             return(free(buffer),NULL);
        *count_ret = *read_ret;
    }
    return ((char *)1);

}

char *get_next_line(int fd)
{
    static char reminder[BUFFER_SIZE + 1];
    char *buffer;
    int read_ret;
    int count_ret;
    int i;

    count_ret = 0;
    i = 2;
    buffer = calloc(BUFFER_SIZE + 1, 1);
    if(!helper_func(buffer,reminder,&count_ret,&read_ret,fd))
        return (NULL);

    while (!ft_strchr(buffer, '\n') && count_ret > 0)
    {
        if (!make_it_bigger(&buffer, i++))
            return(free(buffer),NULL);
        read_ret = read(fd, buffer + count_ret, BUFFER_SIZE);
        if (read_ret <= 0)
            break;
        count_ret += read_ret;
    }

    if (!*buffer)
         return(free(buffer),NULL);
    return (extract_new_line(buffer, reminder));
}
