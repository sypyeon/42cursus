/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 03:03:46 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/22 13:12:57 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_d(long nb);
int		ft_printf(const char *s, ...);
int		ft_arg_count(const char *s);
void	ft_putchar(long c);
void	ft_putstr(char *s);

#endif