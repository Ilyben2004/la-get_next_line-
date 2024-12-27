/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:56:23 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/27 12:56:26 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_new_line(char *buffer, char *reminder)
{
	char	*new_line_address;
	char	*extracted_line;
	int		i;
	int		new_line_size;

	i = -1;
	new_line_address = ft_strchr(buffer, '\n');
	if (new_line_address)
	{
		new_line_size = new_line_address - buffer;
		extracted_line = ft_calloc(new_line_size + 1, 1);
		if (!extracted_line)
			return (NULL);
		while (++i < new_line_size)
			extracted_line[i] = buffer[i];
		if (*(new_line_address + 1))
			ft_strlcpy(reminder, new_line_address + 1);
		free(buffer);
		return (extracted_line);
	}
	return (buffer);
}

void	*make_it_bigger(char **buffer, int i)
{
	char	*buffer_bigger;
	int		j;

	j = -1;
	buffer_bigger = ft_calloc(BUFFER_SIZE * i + 1, 1);
	if (!buffer_bigger)
		return (NULL);
	while ((*buffer)[++j])
		buffer_bigger[j] = (*buffer)[j];
	free(*buffer);
	*buffer = buffer_bigger;
	return (*buffer);
}

char	*ft_strchr(const char *s, int c)
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

int	ft_strlcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	i = 0;
	while ((i < nmemb * size))
		*((char *)array + i++) = 0;
	return (array);
}
