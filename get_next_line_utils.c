#include "get_next_line.h"


char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	cc;

    if(!s)
        return (NULL);

	cc = c;
	i = 0;

	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int ft_strlen(char * buffer)
{
    int i;
    
    i = 0;
    while (buffer[i])
    {
        i++;
        if (buffer[i] == '\n')
        {
            i++;
            break;
        }
    }
    return (i);
}

char * extract_new_line(char * buffer , char *reminder )
{
    char * new_line_adress;
    char * extracted_line;
    int i;
    int new_line_size;
    
    i = -1;
    new_line_adress = ft_strchr(buffer ,'\n');
    new_line_size = ft_strlen (buffer);
   
    if(new_line_adress)
    {
        extracted_line = malloc (new_line_size + 1);
        if(*(new_line_adress + 1))
            ft_strlcpy(reminder , new_line_adress + 1);
        while (++i < new_line_size)
            extracted_line[i] = buffer[i];
        extracted_line[i] = 0;         
    }
    else
        return(buffer);
    free(buffer);
    return extracted_line;
}

void make_it_bigger(char ** buffer ,int i)
{
    char *buffer_bigere;
    int j;

    j = -1;
    buffer_bigere = malloc(BUFFER_SIZE * i );
   
    while(buffer[++j])
    {
        buffer_bigere[j] = buffer[0][j];
    }
    ft_strlcpy(buffer_bigere,*buffer);
    free(*buffer);
    *buffer = buffer_bigere;
}


int  ft_strlcpy(char *dst, const char *src)
{
        int  i;

        i = 0;
        while (src[i] )
        {
                dst[i] = src[i];
                i++;
        }
       return (1);
}
