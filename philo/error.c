/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:51:51 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 15:57:24 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_arg_number_error(int argc)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Error, wrong number of arguments\n", 2);
		return (1);
	}
	return (0);
}

int	ft_type_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr_fd("Error, wrong syntax or negative number\n", 2);
			return (1);
		}
		i++;
	}
	if (ft_atol(str) > INT_MAX)
	{
		ft_putstr_fd("Error, number bigger than INTMAX\n", 2);
		return (1);
	}
	return (0);
}

int	ft_is_arg_error(int argc, char **argv)
{
	int	i;

	i = 1;
	if (ft_arg_number_error(argc) == 1)
			return (1);
	while (i < argc)
	{
		if (ft_type_error(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}