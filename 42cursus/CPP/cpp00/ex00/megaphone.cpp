/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:57:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/10/29 21:55:38 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	int	i = 1;
	std::string	str;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (av[i])
	{
		str += av[i];
		i++;
	}
	for (unsigned long j = 0; j < str.length(); j++)
	{
		str[j] = std::toupper(str[j]);
	}
	std::cout << str << std::endl;
}
