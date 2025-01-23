/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:56:50 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/23 15:40:13 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_var	var)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(var.m_m));
	printf("var : %p\n", &var);
	printf("nb philo : %d %p\n", var.nb_philo, &var.nb_philo);
	printf("time die : %ldms %p\n", var.t_2_die, &var.t_2_die);
	printf("t0 : %ldms %p\n", var.t_start, &var.t_start);
	printf("time eat : %ldms %p\n", var.t_2_eat, &var.t_2_eat);
	printf("time sleep : %ldms %p\n", var.t_2_slp, &var.t_2_slp);
	printf("meals : %d %p\n\n", var.nb_eat_4_each, &var.nb_eat_4_each);
	while (i < var.nb_philo)
	{
		ft_print_philo(var, &(var.philo[i]), i);
		i++;
	}
	pthread_mutex_unlock(&(var.m_m));
}

void	ft_print_philo(t_var var, t_philo *philo, int i)
{
	printf("adr fork : %p\n\n", &var.mut_forks[i]);
	printf("lft fork : %p\n", philo->f_lft);
	printf("adr philo : %p\n", philo);
	printf("id : %d %p\n", philo->n, &philo->n);
	printf("last meal : %ld %p\n", philo->h_last, &philo->h_last);
	printf("hour 2 die : %ld %p\n", philo->h_2_die, &philo->h_2_die);
	printf("nb meals : %d %p\n", philo->nb_meals, &philo->nb_meals);
	printf("rgt fork : %p\n\n", philo->f_rgt);
}
