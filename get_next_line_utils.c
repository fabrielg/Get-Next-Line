/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:28 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/25 13:54:34 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new_calloc;
	size_t	calloc_len;

	calloc_len = nmemb * size;
	if (calloc_len < nmemb || calloc_len < size)
		return (0);
	new_calloc = malloc(calloc_len);
	if (!new_calloc)
		return (0);
	ft_bzero(new_calloc, calloc_len);
	return (new_calloc);
}

void	*ft_memset(void *s, int c, size_t n)
{
	while (n-- > 0)
		((unsigned char *)s)[n] = c;
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t	ft_strlen_char(char const *str, char stop)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	length;
	char	*dup;

	length = ft_strlen_char(s, '\n');
	dup = malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen_char(s, 0);
	while (s[i] != (unsigned char)c)
	{
		if (i == 0 && s[i] != c)
			return ((char *) 0);
		i--;
	}
	return ((char *) &s[i]);
}
