/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:27:29 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/06 00:23:42 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total_size;

	if (size && nmemb > 4294967295 / size)
		return (NULL);
	total_size = (nmemb * size);
	alloc = malloc(total_size);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, total_size);
	return (alloc);
}
