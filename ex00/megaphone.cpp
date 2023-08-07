/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <eberger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:24:56 by eberger           #+#    #+#             */
/*   Updated: 2023/08/07 16:24:58 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*str_to_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
		i++;
	}
	return (str);
}

void	print_argv_uppercase(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		std::cout << str_to_uppercase(argv[i]);
		i++;
	}
	std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
		print_argv_uppercase(argc, argv);
	return (0);
}
