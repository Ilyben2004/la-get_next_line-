#include "get_next_line.h"


char *extract_new_line(char *buffer, char *reminder)
{
    char *new_line_address;
    char *extracted_line;
    int i;
    int new_line_size;

    new_line_address = ft_strchr(buffer, '\n');
    if (new_line_address)
    {
        new_line_size = new_line_address - buffer + 1;
        extracted_line = calloc(new_line_size + 1, 1);
        if (!extracted_line)
            return (NULL);
        for (i = 0; i < new_line_size; i++)
            extracted_line[i] = buffer[i];
        extracted_line[i] = '\0';
        if (*(new_line_address + 1))
            ft_strlcpy(reminder, new_line_address + 1);
        free(buffer);
        return (extracted_line);
    }
    return (buffer);
}

void *make_it_bigger(char **buffer, int i)
{
    char *buffer_bigger;
    int j;

    buffer_bigger = calloc(BUFFER_SIZE * i + 1, 1);
    if (!buffer_bigger)
        return (NULL);
    for (j = 0; (*buffer)[j]; j++)
        buffer_bigger[j] = (*buffer)[j];
    free(*buffer);
    *buffer = buffer_bigger;
    return (*buffer);
}

int ft_strlen(char *buffer)
{
    int i = 0;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}

int ft_strlcpy(char *dst, const char *src)
{
    int i = 0;

    if (!dst || !src)
        return (0);
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (i);
}