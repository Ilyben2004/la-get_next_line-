#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	cc;

	cc = c;
	i = 0;
	if (cc == 0)
		return ((char *)s + ft_strlen(s));
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
        if (buffer[i] == '\0')
        {
            i++;
            break;
        }
    }
    return (i);
}

char * extract_new_line_reminder(char * buffer , char *reminder )
{
    char * new_line_adress;
    char * extracted_line;
    int i;
    int new_line_size;
    
    i = -1;
    new_line_adresse = ft_strchr(buffer ,'\n');
    if (!new_line_adress)
        return (NULL);
    new_line_size = ft_strlen (buffer);
    extracted_line = malloc (new_line_size + 1);

    if(new_line_adresse)
    {
        if(*(new_line_adresse + 1))
            reminder = new_line_adresse + 1;
        while (++i < new_line_size)
            extracted_line[i] = buffer[i];
        extracted_line[i] = 0;         
    }
    free(buffer);
    return extracted_line;

}