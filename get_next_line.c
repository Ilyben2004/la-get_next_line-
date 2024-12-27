/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:52:43 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/27 12:52:46 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*helper_func(char *buffer, char *reminder, int *read_values, int fd)
{
	if (!buffer)
		return (NULL);
	if (reminder[0] != 0)
	{
		read_values[1] = ft_strlcpy(buffer, reminder);
		reminder[0] = 0;
	}
	else
	{
		read_values[0] = read(fd, buffer, BUFFER_SIZE);
		if (read_values[0] <= 0)
			return (free(buffer), NULL);
		read_values[1] = read_values[0];
	}
	return ("valid");
}

char	*get_next_line(int fd)
{
	static char	reminder[BUFFER_SIZE + 1];
	char		*buffer;
	int			i;
	int			read_values[2];

	read_values[1] = 0;
	i = 2;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!helper_func(buffer, reminder, read_values, fd))
		return (NULL);
	while (!ft_strchr(buffer, '\n') && read_values[1] > 0)
	{
		if (!make_it_bigger(&buffer, i++))
			return (free(buffer), NULL);
		read_values[0] = read(fd, buffer + read_values[1], BUFFER_SIZE);
		if (read_values[0] <= 0)
			break ;
		read_values[1] += read_values[0];
	}
	if (!*buffer)
		return (free(buffer), NULL);
	return (extract_new_line(buffer, reminder));
}
