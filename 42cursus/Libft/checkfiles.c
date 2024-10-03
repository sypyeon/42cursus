/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:03:21 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/03 22:26:22 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

int	main()
{
	if (ft_isalnum('1') != 0 && ft_isalnum('a') != 0 && ft_isalnum('?') == 0)
		printf("ft_isalnum: OK!\n");
	else
		printf("ft_isalnum: FAILED\n");
//isalnum check
	if (ft_isprint('1') != 0 && ft_isprint('a') != 0 && ft_isprint('\0') == 0)
		printf("ft_isprint: OK!\n");
	else
		printf("ft_isprint: FAILED\n");
//isprint check
	if (ft_isdigit('1') != 0 && ft_isdigit('a') == 0 && ft_isdigit('\0') == 0)
		printf("ft_isdigit: OK!\n");
	else
		printf("ft_isdigit: FAILED\n");
//isdigit check
	if (ft_isascii('1') != 0 && ft_isascii('a') != 0 && ft_isascii(300) == 0)
		printf("ft_isascii: OK!\n");
	else
		printf("ft_isascii: FAILED\n");
//isascii check
	if (ft_isalpha('A') != 0 && ft_isalpha('Z') != 0 && ft_isalpha('1') == 0)
		printf("ft_isalpha: OK!\n");
	else
		printf("ft_isalpha: FAILED\n");
//isalpha check
	if (ft_strlen("Hello World") == 11 && ft_strlen("") == 0)
		printf("ft_strlen: OK!\n");
	else
		printf("ft_strlen: FAILED\n");
//strlen check
//	ft_bzero(void *s, size_t n);
//	*ft_memset(void *s, int c, size_t n);
//	*ft_memcpy(void *dest, const void *src, size_t n);
//	*ft_memmove(void *dest, const void *src, size_t n);
	return (0);
}
