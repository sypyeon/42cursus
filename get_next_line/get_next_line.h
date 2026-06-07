/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:37:32 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/22 18:17:52 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_str_join(char *dest, char *src);
char	*ft_gnl_strdup(const char *s);

#endif