/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:28 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/27 11:59:26 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new_calloc;
	size_t	calloc_len;

	calloc_len = nmemb * size;
	if (calloc_len < nmemb && calloc_len < size)
		return (0);
	new_calloc = malloc(calloc_len);
	if (!new_calloc)
		return (0);
	while (calloc_len-- > 0)
		new_calloc[calloc_len] = 0;
	return (new_calloc);
}

size_t	ft_strlen_char(char const *str, char stop)
{
	size_t	i;

	if (!str)
		return (0);
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

	if (!s)
		return (NULL);
	i = ft_strlen_char(s, 0);
	while (s[i] != (unsigned char)c)
	{
		if (i == 0 && s[i] != c)
			return (NULL);
		i--;
	}
	return ((char *) &s[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;
	size_t	i;

	if (!s)
		return (0);
	sub_len = 0;
	while (start < ft_strlen_char(s, 0) && sub_len < len && s[start + sub_len])
		sub_len++;
	sub = ft_calloc(sub_len + 1, sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
