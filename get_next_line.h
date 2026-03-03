/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:52:52 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/03/03 19:52:54 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_to_mem(int fd, char *mem, char *buffer);
char	*extract_line(char *mem);
char	*update_mem(char *mem);
size_t	f_strlen(const char *s);
char	*f_strchr(const char *s, int c);
char	*f_strjoin(char *s1, char *s2);

#endif