/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:09:50 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 10:35:25 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(t_var *var)
{
	(void) var;
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc != 5 && argc != 6)
		return (0);
	var = ft_init_var(argc, argv);
}
