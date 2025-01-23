/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:56:50 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/23 12:40:12 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_var	var)
{
	int	i;

	i = 0;
	printf("var : %p\n", &var);
	printf("nb philo : %d %p\n", var.nb_philo, &var.nb_philo);
	printf("time die : %dms %p\n", var.t_2_die, &var.t_2_die);
	printf("t0 : %ldms %p\n", var.t_start, &var.t_start);
	printf("time eat : %dms %p\n", var.t_2_eat, &var.t_2_eat);
	printf("time sleep : %dms %p\n", var.t_2_slp, &var.t_2_slp);
	printf("meals : %d %p\n\n", var.nb_eat_4_each, &var.nb_eat_4_each);
	while (i < var.nb_philo)
	{
		printf("adr fork : %p\n\n", &(var.mut_forks[i]));
		printf("lft fork : %p\n", (var.philo[i]).f_lft);
		printf("adr philo : %p\n", &(var.philo[i]));
		printf("id : %d %p\n", (var.philo[i]).n, &(var.philo[i]).n);
		printf("last meal : %ld %p\n", (var.philo[i]).h_end_last_meal, &(var.philo[i]).h_end_last_meal);
		printf("is eating : %d %p\n", (var.philo[i]).is_eating, &(var.philo[i]).is_eating);
		printf("hour 2 die : %ld %p\n", (var.philo[i]).h_2_die, &(var.philo[i]).h_2_die);
		printf("nb meals : %d %p\n", (var.philo[i]).nb_meals, &(var.philo[i]).nb_meals);
		printf("rgt fork : %p\n\n", (var.philo[i]).f_rgt);
		i++;
	}
}
