/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 03:03:46 by sipyeon           #+#    #+#             */
/*   Updated: 2025/02/19 21:17:58 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_s(char *arg);
int		ft_p(void *arg, char *base);
int		ft_d(int arg);
int		ft_u(unsigned int arg);
int		ft_x(unsigned int arg, char *base);
size_t	ft_strlen(char *s);
void	ft_putchar(int c);
void	ft_putstr(char *s);
char	*ft_l_itoa(long n);

#endif