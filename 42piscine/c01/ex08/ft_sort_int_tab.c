/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:32:30 by sipyeon           #+#    #+#             */
/*   Updated: 2024/08/28 05:34:17 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	first;
	int	compare;

	first = 0;
	while (first < size - 1)
	{
		compare = first + 1;
		while (compare < size)
		{
			if (tab[first] > tab[compare])
			{
				temp = tab[first];
				tab[first] = tab[compare];
				tab[compare] = temp;
			}
			compare++;
		}
		first++;
	}
}

int main()
{
	int arr[] = {5, 4, 3, 2, 0, 6};
	
	ft_sort_int_tab(arr, 6);
	for(int i = 0; i < 6; ++i)
		printf("%d ", arr[i]);

	return 0;
}
