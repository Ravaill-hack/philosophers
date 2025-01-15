/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:56:50 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 13:30:03 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_var	var)
{
	int	i;

	i = 0;
	printf("nb philo : %d\ntime die : %d\n", var.nb_philo, var.t_2_die);
	printf("time eat : %d\ntime sleep : %d\n", var.t_2_eat, var.t_2_slp);
	printf("number of meals for each : %d\n\n", var.nb_eat_4_each);
	while (i < var.nb_philo)
	{
		printf("adr philo : %p\n", &(var.philo[i]));
		printf("id : %d\n", (var.philo[i]).n);
		printf("last meal : %d\n", (var.philo[i]).h_end_last_meal);
		printf("is eating : %d\n", (var.philo[i]).is_eating);
		printf("hour 2 die : %d\n", (var.philo[i]).h_2_die);
		printf("nb meals : %d\n", (var.philo[i]).nb_meals);
		printf("lft philo : %p\n", (var.philo[i]).ph_lft);
		printf("rgt philo : %p\n", (var.philo[i]).ph_rgt);
		printf("lft fork : %p\n", (var.philo[i]).f_lft);
		printf("rgt fork : %p\n\n", (var.philo[i]).f_rgt);
		i++;
	}
}
