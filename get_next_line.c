/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:03:05 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/03/02 21:34:51 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_mem(int fd, char *mem, char *buffer)
{
	int		bytes_read;

	bytes_read = 0;
	while (!(f_strchr(mem, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (mem);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		mem = f_strjoin(mem, buffer);
		if (!mem)
			break ;
	}
	return (mem);
}

char	*extract_line(char *mem)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!mem || !mem[0])
		return (NULL);
	while (mem[i] && mem[i] != '\n')
		i++;
	if (mem[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = mem[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_mem(char *mem)
{
	char	*new_mem;
	int		i;
	int		j;

	i = 0;
	while (mem[i] && mem[i] != '\n')
		i++;
	if (!mem[i])
	{
		free (mem);
		return (NULL);
	}
	new_mem = (char *)malloc(sizeof(char) * (f_strlen(mem) - i + 1));
	if (!new_mem)
	{
		free (mem);
		return (NULL);
	}
	i++;
	j = 0;
	while (mem[i])
		new_mem[j++] = mem[i++];
	new_mem[j] = '\0';
	free (mem);
	return (new_mem);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	mem = read_to_mem(fd, mem, buffer);
	free (buffer);
	if (!mem)
		return (NULL);
	line = extract_line(mem);
	if(!line)
	{
		free(mem);
		mem = NULL;
		return (NULL);
	}
	mem = update_mem(mem);
	return (line);
}
