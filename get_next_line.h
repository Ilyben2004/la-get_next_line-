#ifndef GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#define BUFFER_SIZE 42

char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void extract_new_line(char * buffer , char *reminder , int there_is_a_remider);


#endif