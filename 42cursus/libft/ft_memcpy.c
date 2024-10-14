/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:13:07 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/11 21:38:06 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp_d;
	char	*temp_s;

	if (dest == src || n == 0)
		return (dest);
	temp_d = (char *)dest;
	temp_s = (char *)src;
	i = 0;
	while (i < n)
	{
		temp_d[i] = temp_s[i];
		i++;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// #include "libft.h" // ft_memcpy가 선언된 헤더파일

// int main(void)
// {
//     // 표준 memcpy 테스트
//     printf("Testing standard memcpy(NULL, NULL, 0):\n");
//     void *std_result = memcpy(NULL, NULL, 0);
//     if (std_result == NULL)
//         printf("Standard memcpy: Passed\n");
//     else
//         printf("Standard memcpy: Failed\n");

//     // ft_memcpy 테스트
//     printf("Testing ft_memcpy(NULL, NULL, 0):\n");
//     void *ft_result = ft_memcpy(NULL, NULL, 0);
//     if (ft_result == NULL)
//         printf("ft_memcpy: Passed\n");
//     else
//         printf("ft_memcpy: Failed\n");

//     return 0;
// }