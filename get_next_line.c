#include "get_next_line.h"

void helper_func()
{
    if (!buffer)
        return (NULL);
    if (reminder[0] != 0)
    {
        count_ret = ft_strlcpy(buffer, reminder);
        reminder[0] = 0;
    }
    else
    {
        read_ret = read(fd, buffer, BUFFER_SIZE);
        if (read_ret <= 0) 
             return(free(buffer),NULL);
        count_ret = read_ret;
    }

}

char *get_next_line(int fd)
{
    static char reminder[BUFFER_SIZE + 1];
    char *buffer;
    int read_ret;
    int count_ret = 0;
    int i = 2;

    buffer = calloc(BUFFER_SIZE + 1, 1);
    if (!buffer)
        return (NULL);

    if (reminder[0] != 0)
    {
        count_ret = ft_strlcpy(buffer, reminder);
        reminder[0] = 0;
    }
    else
    {
        read_ret = read(fd, buffer, BUFFER_SIZE);
        if (read_ret <= 0) 
             return(free(buffer),NULL);
        count_ret = read_ret;
    }

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
