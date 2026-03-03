/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:02:29 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/03/03 15:29:02 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*f_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*(unsigned char *)s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = (char *)malloc(sizeof(char) * ((f_strlen(s1) + f_strlen(s2) + 1)));
	if (!tmp)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	free(s1);
	return (tmp);
}
