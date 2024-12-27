/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:52:51 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/27 12:55:26 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*extract_new_line(char *buffer, char *reminder);
void	*make_it_bigger(char **buffer, int i);
int		ft_strlcpy(char *dst, const char *src);
void	*ft_calloc(size_t nmemb, size_t size);
void	*helper_func(char *buffer, char *reminder, int *read_values, int fd);
#endif
