#ifndef GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 2

char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char *extract_new_line(char * buffer , char *reminder);
void make_it_bigger(char **buffer ,int i);
int  ft_strlcpy(char *dst, const char *src);
#endif