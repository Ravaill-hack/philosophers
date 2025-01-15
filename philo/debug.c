/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:56:50 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/15 17:22:26 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_var	var)
{
	int	i;

	i = 0;
	printf("nb philo : %d\ntime die : %dms\n", var.nb_philo, var.t_2_die);
	printf("hour init : %dms\n", var.t_start);
	printf("time eat : %dms\ntime sleep : %dms\n", var.t_2_eat, var.t_2_slp);
	printf("number of meals for each : %d\n\n", var.nb_eat_4_each);
	while (i < var.nb_philo)
	{
		printf("adr fork : %p\n\n", &(var.mut_forks[i]));
		printf("lft fork : %p\n", (var.philo[i]).f_lft);
		printf("adr philo : %p\n", &(var.philo[i]));
		printf("id : %d\n", (var.philo[i]).n);
		printf("last meal : %d\n", (var.philo[i]).h_end_last_meal);
		printf("is eating : %d\n", (var.philo[i]).is_eating);
		printf("hour 2 die : %d\n", (var.philo[i]).h_2_die);
		printf("nb meals : %d\n", (var.philo[i]).nb_meals);
		printf("lft philo : %p\n", (var.philo[i]).ph_lft);
		printf("rgt philo : %p\n", (var.philo[i]).ph_rgt);
		printf("rgt fork : %p\n\n", (var.philo[i]).f_rgt);
		i++;
	}
}
